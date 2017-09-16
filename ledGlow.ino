

  void checkError(int c)
  {
    if(c>85&&flag==1)//change limit
    {
    digitalWrite(ledR,HIGH);
    delay(2000);
    digitalWrite(ledR,LOW);    
    }
  else
    {
    digitalWrite(ledG,HIGH);
    delay(2000);
    digitalWrite(ledG,LOW);     
    flag=0;
    }  
  }
   

