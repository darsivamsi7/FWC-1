int A=8,B=9,C=10,D=11;

void setup()
{
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
}

void displayDigit(int n)
{
  switch(n)
  {
    case 0:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
      break;

    case 1:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
      break;
  }
}

void loop()
{
  for(int i=0;i<16;i++)
  {
    int a,b,c,d;

    switch(i)
    {
      case 0:  a=0;b=0;c=0;d=0; break;
      case 1:  a=0;b=0;c=0;d=1; break;
      case 2:  a=0;b=0;c=1;d=0; break;
      case 3:  a=0;b=0;c=1;d=1; break;
      case 4:  a=0;b=1;c=0;d=0; break;
      case 5:  a=0;b=1;c=0;d=1; break;
      case 6:  a=0;b=1;c=1;d=0; break;
      case 7:  a=0;b=1;c=1;d=1; break;
      case 8:  a=1;b=0;c=0;d=0; break;
      case 9:  a=1;b=0;c=0;d=1; break;
      case 10: a=1;b=0;c=1;d=0; break;
      case 11: a=1;b=0;c=1;d=1; break;
      case 12: a=1;b=1;c=0;d=0; break;
      case 13: a=1;b=1;c=0;d=1; break;
      case 14: a=1;b=1;c=1;d=0; break;
      case 15: a=1;b=1;c=1;d=1; break;
    }

    int Y=(a&&b)||(c&&d);

    displayDigit(Y);

    delay(2000);
  }
}