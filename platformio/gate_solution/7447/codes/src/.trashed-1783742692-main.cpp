#include <Arduino.h>

// 7447 BCD input pins
const int bcdA = 9;
const int bcdB = 10;
const int bcdC = 11;
const int bcdD = 12;

void displayOutput(int Y)
{
    if (Y == 0)
    {
        // BCD 0000
        digitalWrite(bcdA, LOW);
        digitalWrite(bcdB, LOW);
        digitalWrite(bcdC, LOW);
        digitalWrite(bcdD, LOW);
    }
    else
    {
        // BCD 0001
        digitalWrite(bcdA, HIGH);
        digitalWrite(bcdB, LOW);
        digitalWrite(bcdC, LOW);
        digitalWrite(bcdD, LOW);
    }
}

void setup()
{
    pinMode(bcdA, OUTPUT);
    pinMode(bcdB, OUTPUT);
    pinMode(bcdC, OUTPUT);
    pinMode(bcdD, OUTPUT);
}

void loop()
{
    int A, B, C, D, Y;

    // Test Case 1 : 0000 -> Y = 0
    A = 0; B = 0; C = 0; D = 0;
    Y = (A && B) || (C && D);
    displayOutput(Y);
    delay(2000);

    // Test Case 2 : 1100 -> Y = 1
    A = 1; B = 1; C = 0; D = 0;
    Y = (A && B) || (C && D);
    displayOutput(Y);
    delay(2000);

    // Test Case 3 : 0101 -> Y = 0
    A = 0; B = 1; C = 0; D = 1;
    Y = (A && B) || (C && D);
    displayOutput(Y);
    delay(2000);

    // Test Case 4 : 0011 -> Y = 1
    A = 0; B = 0; C = 1; D = 1;
    Y = (A && B) || (C && D);
    displayOutput(Y);
    delay(2000);
}
