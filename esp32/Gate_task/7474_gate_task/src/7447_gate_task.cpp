#include <Arduino.h>

//====================================================
// ESP32 -> 7474 Connections
//====================================================

// Data Inputs
#define DATA_A 32
#define DATA_B 33
#define DATA_C 25
#define DATA_D 26

// Common Clock
#define CLK 21

//====================================================
// Generate One Clock Pulse
//====================================================

void pulseClock()
{
    digitalWrite(CLK, LOW);
    delayMicroseconds(5);

    digitalWrite(CLK, HIGH);
    delayMicroseconds(5);

    digitalWrite(CLK, LOW);
    delayMicroseconds(5);
}

//====================================================
// Send BCD to 7474
//====================================================

void sendBCD(bool b3, bool b2, bool b1, bool b0)
{
    digitalWrite(DATA_A, b3);
    digitalWrite(DATA_B, b2);
    digitalWrite(DATA_C, b1);
    digitalWrite(DATA_D, b0);

    // Latch all four flip-flops simultaneously
    pulseClock();
}

//====================================================

void setup()
{
    pinMode(DATA_A, OUTPUT);
    pinMode(DATA_B, OUTPUT);
    pinMode(DATA_C, OUTPUT);
    pinMode(DATA_D, OUTPUT);

    pinMode(CLK, OUTPUT);

    digitalWrite(CLK, LOW);
}

//====================================================

void loop()
{
    // Generate all 16 input combinations
    for (int value = 0; value < 16; value++)
    {
        bool A = (value >> 3) & 1;
        bool B = (value >> 2) & 1;
        bool C = (value >> 1) & 1;
        bool D = value & 1;

        // Simplified Boolean Expression
        // Y = A'B'C + A'D

        bool Y = (!A && !B && C) || (!A && D);

        if (Y)
        {
            // Send 0001
            sendBCD(0, 0, 0, 1);
        }
        else
        {
            // Send 0000
            sendBCD(0, 0, 0, 0);
        }

        delay(2000);
    }
}

