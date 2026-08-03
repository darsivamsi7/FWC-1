
 int segPins[8] = {0,1,2,3,4,5,6,7};


byte digits[10][8] = {
  
  {0,0,0,0,0,0,1,1}, 
  {1,0,0,1,1,1,1,1}, 
  {0,0,1,0,0,1,0,1}, 
  {0,0,0,0,1,1,0,1}, 
  {1,0,0,1,1,0,0,1}, 
  {0,1,0,0,1,0,0,1}, 
  {0,1,0,0,0,0,0,1}, 
  {0,0,0,1,1,1,1,1}, 
  {0,0,0,0,0,0,0,1}, 
  {0,0,0,0,1,0,0,1}  
};

void displayDigit(int num)
{
  for(int i=0;i<8;i++)
  {
    digitalWrite(segPins[i], digits[num][i]);
  }
}

void setup()
{
  for(int i=0;i<8;i++)
  {
    pinMode(segPins[i], OUTPUT);
    digitalWrite(segPins[i], HIGH);
  }
}

void loop()
{
  for(int i=0;i<=9;i++)
  {
    displayDigit(i);
    delay(1000);
  }
}