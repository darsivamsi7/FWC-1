/*
   Boolean Expression:
   Y = A'BC' + AD'

   ESP32 Output Pins:
   GPIO16 -> 7447 A (LSB)
   GPIO17 -> 7447 B
   GPIO18 -> 7447 C
   GPIO19 -> 7447 D (MSB)

   The ESP32 internally generates all 16 input combinations.
   If Y = 0, the 7447 displays 0.
   If Y = 1, the 7447 displays 1.
*/
#include<Arduino.h>
#define BCD_A 16
#define BCD_B 17
#define BCD_C 18
#define BCD_D 19

void displayDigit(int digit)
{
  digitalWrite(BCD_A, digit & 0x01);
  digitalWrite(BCD_B, (digit >> 1) & 0x01);
  digitalWrite(BCD_C, (digit >> 2) & 0x01);
  digitalWrite(BCD_D, (digit >> 3) & 0x01);
}

void setup()
{
  pinMode(BCD_A, OUTPUT);
  pinMode(BCD_B, OUTPUT);
  pinMode(BCD_C, OUTPUT);
  pinMode(BCD_D, OUTPUT);
}

void loop()
{
  for (int i = 0; i < 16; i++)
  {
    // Generate inputs internally
    bool A = (i >> 3) & 1;
    bool B = (i >> 2) & 1;
    bool C = (i >> 1) & 1;
    bool D =  i       & 1;

    // Boolean Function
    bool Y = ((!A && B && !C) || (A && !D));

    if (Y)
      displayDigit(1);   // Display digit 1
    else
      displayDigit(0);   // Display digit 0

    delay(1000);
  }
}
