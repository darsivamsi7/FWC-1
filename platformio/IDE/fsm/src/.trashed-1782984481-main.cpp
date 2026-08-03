#include <Arduino.h>
int W,X,Y,Z;
int A,B,C,D;

void load9()
{
  // Normal inactive state
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  digitalWrite(A0,HIGH);

  delay(10);

  // Set W=1
  digitalWrite(11,LOW);

  // Set X=0
  digitalWrite(12,LOW);

  // Set Y=0
  digitalWrite(13,LOW);

  // Set Z=1
  digitalWrite(A0,LOW);

  delay(50);

  // Return to normal mode
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  digitalWrite(A0,HIGH);

  delay(50);
}

void clockPulse()
{
  digitalWrite(10,HIGH);
  delay(10);

  digitalWrite(10,LOW);
  delay(10);
}

void setup()
{
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);

  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

  pinMode(10,OUTPUT);

  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(A0,OUTPUT);

  digitalWrite(10,LOW);

  load9();
}

void loop()
{
  W = digitalRead(2);
  X = digitalRead(3);
  Y = digitalRead(4);
  Z = digitalRead(5);

  // Down-counter FSM equations

  A = (W && Z) ||
      (!W && !X && !Y && !Z);

  B = (X && Y) ||
      (X && Z) ||
      (W && !Z);

  C = (Y && Z) ||
      (W && !Z) ||
      (X && !Y && !Z);

  D = !Z;

  digitalWrite(6,A);
  digitalWrite(7,B);
  digitalWrite(8,C);
  digitalWrite(9,D);

  clockPulse();

  delay(1000);
}
