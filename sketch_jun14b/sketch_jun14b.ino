#include <Servo.h> 

Servo myservo;

void setup() 
{ 
  pinMode(12, INPUT_PULLUP);
  myservo.attach(9);
  myservo.write(0);  
} 

void loop() {
if(digitalRead(12)!=HIGH){
  myservo.write(90);
}else{
  myservo.write(20);
}


} 
