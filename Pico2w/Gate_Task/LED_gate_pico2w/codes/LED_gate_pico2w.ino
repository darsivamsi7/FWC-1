int A, B, C, D, Y, LED = 1;

void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  for (A = 0; A <= 1; A++)
  {
    for (B = 0; B <= 1; B++)
    {
      for (C = 0; C <= 1; C++)
      {
        for (D = 0; D <= 1; D++)
        {
          Y = (A && B) || (C && D);

          digitalWrite(LED, Y);

          delay(1000);   // Hold each condition for 1 second
        }
      }
    }
  }
}