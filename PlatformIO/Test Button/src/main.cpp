#include <Arduino.h>

const int buttonPin1 = 2; // the number of the pushbutton pin
const int ledPin1 = 7;	  // the number of the LED pin

// const int buttonPin2 = 12;
// const int ledPin2 = 6;

int reading2 = 0;

int state = HIGH;	// the current state of the output pin
int reading = 0;	// the current reading from the input pin
int previous = LOW; // the previous reading from the input pin

long time = 0;		 // the last time the output pin was toggled
long debounce = 500; // the debounce time, increase if the output flickers

void setup()
{
	pinMode(ledPin1, OUTPUT);
	// pinMode(ledPin2, OUTPUT);
	pinMode(buttonPin1, INPUT);
	// pinMode(buttonPin2, INPUT);
}

void loop()
{
	reading = digitalRead(buttonPin1);

	// if the input just went from LOW and HIGH and we've waited long enough
	// to ignore any noise on the circuit, toggle the output pin and remember
	// the time
	if (reading == LOW && previous == HIGH && millis() - time > debounce)
	{
		if (state == LOW)
			state = HIGH;
		else
			state = LOW;
		time = millis();
	}
	digitalWrite(ledPin1, state);

	previous = reading;

	// if (reading == LOW)
	// {
	// 	digitalWrite(ledPin1, HIGH);
	// }
	// else
	// {
	// 	digitalWrite(ledPin1, LOW);
	// }

	// reading2 = digitalRead(buttonPin2);

	// if (reading2 == LOW)
	// {
	// 	digitalWrite(ledPin2, HIGH);
	// }
	// else
	// {
	// 	digitalWrite(ledPin2, LOW);
	// }
}
