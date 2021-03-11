#include "functions.hpp"

void setup()
{
  Serial.begin(9600);
  esp8266.begin(9600);

  delay(2000);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  sendData("AT+RST\r\n", 2000);            // reset module
  sendData("AT+CWMODE=1\r\n", 1000);       // configure as access point
  sendData("AT+CIFSR\r\n", 1000);          // get ip address //192.168.4.1
  sendData("AT+CIPMUX=1\r\n", 1000);       // configure for multiple connections
  sendData("AT+CIPSERVER=1,80\r\n", 1000); // turn on server on port 80
}

void loop()
{
  if (esp8266.available()) // check if the esp is sending a message
  {
    if (esp8266.find("+IPD,"))
    {
      delay(1000); // wait for the serial buffer to fill up (read all the serial data)
      // get the connection id so that we can then disconnect
      int connectionId = esp8266.read() - 48; // subtract 48 because the read() function returns
                                              // the ASCII decimal value and 0 (the first decimal number) starts at 48

      esp8266.find("pin="); // advance cursor to "pin="

      int pinNumber = (esp8266.read() - 48) * 10; // get first number i.e. if the pin 13 then the 1st number is 1, then multiply to get 10
      pinNumber += (esp8266.read() - 48);         // get second number, i.e. if the pin number is 13 then the 2nd number is 3, then add to the first number

      digitalWrite(pinNumber, !digitalRead(pinNumber)); // toggle pin

      // make close command
      String closeCommand = "AT+CIPCLOSE=";
      closeCommand += connectionId; // append connection id
      closeCommand += "\r\n";

      sendData(closeCommand, 1000); // close connection
    }
  }
}