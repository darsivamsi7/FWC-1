#include<Arduino.h>
#include <LiquidCrystal.h>

// LCD pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Voltage Divider Variables
int Voutq = 0;

float Vin = 5.0;
float Vout = 0.0;

float R1 = 220.0;   // Known resistor
float R2 = 0.0;     // Unknown resistor

void setup()
{
    lcd.begin(16, 2);

    lcd.setCursor(0, 0);
    lcd.print("----OHM METER---");

    Serial.begin(9600);

    delay(2000);
    lcd.clear();
}

void loop()
{
    // Read ADC value
    Voutq = analogRead(A0);

    // Convert ADC to Voltage
    Vout = Vin * Voutq / 1024.0;

    // Avoid divide by zero
    if(Vout > 0.01)
    {
        R2 = R1 * ((Vin / Vout) - 1.0);

        Serial.print("Resistance = ");
        Serial.print(R2);
        Serial.println(" Ohms");

        lcd.clear();

        lcd.setCursor(0, 0);
        lcd.print("Resistance:");

        lcd.setCursor(0, 1);
        lcd.print(R2);
        lcd.print(" Ohm");
    }
    else
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("No Resistor");
    }

    delay(1000);
}
