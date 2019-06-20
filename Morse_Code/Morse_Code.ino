/*
 * Program care afiseaza codul morse folosind niste leduri conectate la pinul 9 si
   la GND pe aceasi parte, de pe un Arduino Uno
*/
#define min 200 //timp intre puncte
#define max 400 //timp intre linii

int bec = 13;
int brightMax = 255;
int brightMin = 0;
String str[30];

void setup() 
{
  pinMode(bec, OUTPUT);
  Serial.begin(9600);
}

void Blink(int x, int y)  // functie pentru un blink, led deschis-inchis
{                                         
  digitalWrite (bec, brightMax);       
  delay(x);                              // x este valoarea in ms pentru cat timp sta ledul deschis
  digitalWrite (bec, brightMin);
  delay(y);                              // y este valoarea in ms pentru cat timp sta ledul inchis
}
#pragma region Litere
void A()
{
  Blink(min,min);
  Blink(max,max);
}

void B()
{
  Blink(max,max);
  Blink(min, min);
  Blink(min, min);
  Blink(min, max);
}

void C()
{
  Blink(max,max);
  Blink(min,min);
  Blink(max,max);
  Blink(min,max);
}

void D()
{
  Blink(max, max);
  Blink(min, min);
  Blink(min, max);
}

void E()
{
  Blink(min, max);
}

void F_()
{
  Blink(min, min);
  Blink(min, min);
  Blink(max, max);
  Blink(min, max);
}

void G()
{
  Blink(max, max);
  Blink(max, max);
  Blink(min, max);
}

void H()
{
  Blink(min, min);
  Blink(min, min);
  Blink(min, min);
  Blink(min, max);
}

void I()
{
  Blink(min, min);
  Blink(min, max);
}

//J, K

void L()
{
  Blink(min,min);
  Blink(max,max);
  Blink(min,min);
  Blink(min,max);
}

//M, N

void O()  // functie pentru litera O
{
  Blink(max,max);
  Blink(max,max);
  Blink(max,max);
}

void P()
{
  Blink(min,min);
  Blink(max,max);
  Blink(max,max);
  Blink(min,max);
}

// Q, R

void S()  // functie pentru litera S 
{
  Blink(min, min);
  Blink(min, min);
  Blink(min, max);
}

void T()
{
  Blink(max,max);
}


void U()
{
  Blink(min,min);
  Blink(min,min);
  Blink(max,max);
}

void V()
{
  Blink(min,min);
  Blink(min,min);
  Blink(min,min);
  Blink(max,max);
}

//X, Y, Z

#pragma endregion

char pui;

void loop() 
{
  /* Adauga text pt codul morse;
     Ex.: S(); O(); S();
  */
  while(Serial.available() > 0)
  {
    pui = Serial.read();
    Serial.println(pui);
  }
 delay(2000);
}
