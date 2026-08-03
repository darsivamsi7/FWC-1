#include <Arduino.h>

int A = 2;
int B = 3;
int C = 4;
int D = 5;

void setup()
{
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
}

void loop()
{
    for(int n = 0; n <= 9; n++)
    {
        int w = bitRead(n,0);
        int x = bitRead(n,1);
        int y = bitRead(n,2);
        int z = bitRead(n,3);

        int a = !w;

        int b = (w && !x && !z) || (!w && x);

        int c = (!x && y) || (!w && y) || (w && x && !y);

        int d = (!w && z) || (w && x && y);

        digitalWrite(A, a);
        digitalWrite(B, b);
        digitalWrite(C, c);
        digitalWrite(D, d);

        delay(1000);
    }
}
