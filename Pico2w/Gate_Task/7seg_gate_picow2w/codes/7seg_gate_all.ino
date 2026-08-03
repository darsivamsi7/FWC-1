int segPins[8]={0,1,2,3,4,5,6,7};

byte digit0[8]={0,0,0,0,0,0,1,1};
byte digit1[8]={1,0,0,1,1,1,1,1};

void display0()
{
  for(int i=0;i<8;i++)
    digitalWrite(segPins[i],digit0[i]);
}

void display1()
{
  for(int i=0;i<8;i++)
    digitalWrite(segPins[i],digit1[i]);
}

void setup()
{
  for(int i=0;i<8;i++)
  {
    pinMode(segPins[i],OUTPUT);
    digitalWrite(segPins[i],HIGH);
  }
}

void loop()
{
  for(int i=0;i<16;i++)
  {
    int A,B,C,D;

    switch(i)
    {
      case 0:  A=0; B=0; C=0; D=0; break;
      case 1:  A=0; B=0; C=0; D=1; break;
      case 2:  A=0; B=0; C=1; D=0; break;
      case 3:  A=0; B=0; C=1; D=1; break;
      case 4:  A=0; B=1; C=0; D=0; break;
      case 5:  A=0; B=1; C=0; D=1; break;
      case 6:  A=0; B=1; C=1; D=0; break;
      case 7:  A=0; B=1; C=1; D=1; break;
      case 8:  A=1; B=0; C=0; D=0; break;
      case 9:  A=1; B=0; C=0; D=1; break;
      case 10: A=1; B=0; C=1; D=0; break;
      case 11: A=1; B=0; C=1; D=1; break;
      case 12: A=1; B=1; C=0; D=0; break;
      case 13: A=1; B=1; C=0; D=1; break;
      case 14: A=1; B=1; C=1; D=0; break;
      case 15: A=1; B=1; C=1; D=1; break;
    }

    int Y=(A&&B)||(C&&D);

    if(Y)
      display1();
    else
      display0();

    delay(2000);
  }
}