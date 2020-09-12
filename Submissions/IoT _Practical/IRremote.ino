#include<IRremote.h>
int red=13;
int green=9;
int blue=10;
int buzzer=7;

int RECV_PIN=2;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(buzzer,OUTPUT);
  
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRln");
}

void loop()
{
  if (irrecv.decode(&results))
    {
     Serial.println(results.value,HEX);
    
     irrecv.resume(); // Receive the next value
   
     if(results.value==0xFD08F7){
      digitalWrite(red,HIGH);  
      digitalWrite(blue,LOW);
      digitalWrite(green,LOW);
       digitalWrite(buzzer,LOW);
       
    }
    else if(results.value==0xFD8877){
      digitalWrite(red,LOW);  
      digitalWrite(blue,HIGH);
      digitalWrite(green,LOW);
      digitalWrite(buzzer,LOW);
      
    }
    else if(results.value==0xFD48B7){
      digitalWrite(red,LOW);  
      digitalWrite(blue,LOW);
      digitalWrite(green,HIGH); 
      digitalWrite(buzzer,LOW);
    }
    else if(results.value==0xFD28D7){
      digitalWrite(red,HIGH);  
      digitalWrite(blue,HIGH);
      digitalWrite(green,HIGH); 
      digitalWrite(buzzer,HIGH);
      }
     delay(30);
  }
 
  
  }
  
  
 
