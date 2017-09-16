#include"elapsedMillis.h"

elapsedMillis timeElapsed;
int interval = 15000;
int prev = 0;
int LED13 = 13;
int Signal = 0;
int Cutoff = 800;
int count = 0;
int flag = 1;
int ledG = 12;
int ledR = 13;

int calcMax()
{
  delay(10000);
  for(int i=0;i<250;i++)
  {
    Signal = analogRead(0);
    if(Signal>count)
    count=Signal;
    delay(20);
  }
  Cutoff = .7*count;
  count=0;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(ledG,OUTPUT);
  pinMode(ledR,OUTPUT);
  //pinMode(13,OUTPUT);
  Serial.begin(9600);
  //calcMax();
}

void loop() {
  flag=1;
  // put your main code here, to run repeatedly:
  Signal = analogRead(0);
  //Serial.println(Signal);
  if(Signal > Cutoff && prev < Cutoff)
  {
    digitalWrite(LED13,HIGH);
    count++;
  }
  if(timeElapsed > interval)
  {
    checkError(count*4);
    if(flag==0)
      Serial.println(count*4);
      count = 0;
      timeElapsed = 0;     
    
    
  }
  prev = Signal;;
  delay(15);
}
