#include <Arduino.h>

const int inputs[] = {9,10,11,12};

const int bcdA = 2;
const int bcdB = 3;
const int bcdC = 4;
const int bcdD = 5;

void setup()
{
    for(int i=0;i<4;i++)
        pinMode(inputs[i],OUTPUT);

    pinMode(bcdA,OUTPUT);
    pinMode(bcdB,OUTPUT);
    pinMode(bcdC,OUTPUT);
    pinMode(bcdD,OUTPUT);
}

void loop()
{
    for(int n=0;n<16;n++)
    {
        for(int i=0;i<4;i++)
            digitalWrite(inputs[i], (n >> i) & 1);

        int A = (n >> 0) & 1;
        int B = (n >> 1) & 1;
        int C = (n >> 2) & 1;
        int D = (n >> 3) & 1;

        int Y = (A & B) | (C & D);

        digitalWrite(bcdA, Y);
        digitalWrite(bcdB, LOW);
        digitalWrite(bcdC, LOW);
        digitalWrite(bcdD, LOW);

        delay(1000);
    }
}
