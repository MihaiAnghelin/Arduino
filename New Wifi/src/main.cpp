#include "functions.hpp"

void setup()
{
	pinMode(13, OUTPUT);

	Serial.begin(9600);
	wifiSerial.begin(9600);

	sendToWifi("AT+CWMODE=1", responseTime, DEBUG);		  // configure as client
	sendToWifi("AT+CIFSR", responseTime, DEBUG);		  // get ip address
	sendToWifi("AT+CIPMUX=1", responseTime, DEBUG);		  // configure for multiple connections
	sendToWifi("AT+CIPSERVER=1,90", responseTime, DEBUG); // turn on server on port 80

	sendToUno("Wifi connection is running!", responseTime, DEBUG);
}

void loop()
{
	if (Serial.available() > 0)
	{
		String message = readSerialMessage();
		if (find(message, "debugEsp8266:"))
		{
			String result = sendToWifi(message.substring(13, message.length()), responseTime, DEBUG);
			if (find(result, "OK"))
				sendData("\nOK");
			else
				sendData("\nEr");
		}
	}
	if (wifiSerial.available() > 0)
	{

		String message = readWifiSerialMessage();

		if (find(message, "esp8266:"))
		{
			String result = sendToWifi(message.substring(8, message.length()), responseTime, DEBUG);
			if (find(result, "OK"))
				sendData("\n" + result);
			else
				sendData("\nErrRead"); //At command ERROR CODE for Failed Executing statement
		}
		else if (find(message, "HELLO"))
		{						//receives HELLO from wifi
			sendData("\\nHI!"); //arduino says HI
		}
		else if (find(message, "LEDON"))
		{
			//turn on built in LED:
			digitalWrite(13, HIGH);
		}
		else if (find(message, "LEDOFF"))
		{
			//turn off built in LED:
			digitalWrite(13, LOW);
		}
		else
		{
			sendData("\nErrRead"); //Command ERROR CODE for UNABLE TO READ
		}
	}
	delay(responseTime);
}