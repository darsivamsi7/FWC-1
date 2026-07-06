// ESP32 Boolean Expression
// Y = A'BC' + AD'
// Inputs are generated automatically (0000 to 1111)
#include <Arduino.h>
#define LED_PIN 2

void setup()
{
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    for (int i = 0; i < 16; i++)
    {
        bool A = (i >> 3) & 1;
        bool B = (i >> 2) & 1;
        bool C = (i >> 1) & 1;
        bool D = i & 1;

        // Boolean Expression
        bool Y = ((!A && B && !C) || (A && !D));

        if (Y)
        {
            digitalWrite(LED_PIN, HIGH);
            delay(500);
            digitalWrite(LED_PIN, LOW);
            delay(500);
        }
        else
        {
            digitalWrite(LED_PIN, LOW);
            delay(1000);
        }
    }
}
