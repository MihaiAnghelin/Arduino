#include <Arduino.h>
#include <SoftwareSerial.h>
#define port 9600

SoftwareSerial ESPserial(4, 5); // RX | TX

void setup()
{
  Serial.begin(port);
  ESPserial.begin(port);

  Serial.println("");
  Serial.println("Remember to to set Both NL & CR in the serial monitor.");
  Serial.println("Ready");
  Serial.println("");
}

void loop()
{
  if ( ESPserial.available() )
  {
    Serial.write( ESPserial.read() );
  }

  if ( Serial.available() ) {
    ESPserial.write( Serial.read() );
  }
}