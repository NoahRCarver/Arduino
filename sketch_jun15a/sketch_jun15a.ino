#include <Servo.h>

Servo trigger;
void setup() {
  trigger.attach(11);
  Serial.begin(57600);
  trigger.write(0);
}

void loop() {
  
  if(Serial.available() >0){
  char ch = Serial.read();
  if(ch == 'f'){
    trigger.write(180);
    delay(1000);
  }else
  {
    trigger.write(0);
  }
  
  
  }
}

