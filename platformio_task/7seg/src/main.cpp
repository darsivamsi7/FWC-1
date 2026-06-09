#include <Arduino.h>
int A = 1;
int B = 1;
int C = 1;
int D = 1;

// 7-segment pins
int segA = 2;
int segB = 3;
int segC = 4;
int segD = 5;
int segE = 6;
int segF = 7;
int segG = 8;

void display0() {
  digitalWrite(segA, LOW);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
}

void display1() {
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}

void setup() {

  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);

  int Y = (A && B) || (C && D);

  if (Y == 1)
    display1();
  else
    display0();
}

void loop() {
}
