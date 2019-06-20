/*
 Name:		VS_Test.ino
 Created:	3/17/2019 11:06:44 AM
 Author:	mihai
*/

#define min 250
#define max 500

void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
}

void Blink(int x, int y)
{
	digitalWrite(LED_BUILTIN, HIGH);
	delay(x);
	digitalWrite(LED_BUILTIN, LOW);
	delay(y);
}

void S()
{
	Blink(min, min);
	Blink(min, min);
	Blink(min, max);
}

void O()
{
	Blink(max, max);
	Blink(max, max);
	Blink(max, max);
}

void pause()
{
	delay(3000);
}

// the loop function runs over and over again forever
void loop()
{
	S();
	O();
	S();
	pause();
}
