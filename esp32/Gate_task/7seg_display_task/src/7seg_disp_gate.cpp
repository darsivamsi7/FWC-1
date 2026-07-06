/*
   ESP32
   Boolean Function:
   Y = A'BC' + AD'

   Display:
   Y = 0  --> Displays 0
   Y = 1  --> Displays 1

   Inputs A,B,C,D are generated automatically.*/
#include <Arduino.h>
 int segA = 13; int segB = 12; int segC = 14; int segD = 27; int segE = 26;
 int segF = 25;
 int segG = 33;

void display0()
{
  // Common Anode (LOW = ON)

  digitalWrite(segA, LOW);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
}

void display1()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}

void setup()
{
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
}

void loop()
{
  for(int i = 0; i < 16; i++)
  {
    bool A = (i >> 3) & 1;
    bool B = (i >> 2) & 1;
    bool C = (i >> 1) & 1;
    bool D = i & 1;

    // Boolean Expression
    bool Y = ((!A && B && !C) || (A && !D));

    if(Y)
      display1();
    else
      display0();

    delay(1000);
  }
}
