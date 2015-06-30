#include <LiquidCrystal.h>
#include <Servo.h> 

Servo motor;
LiquidCrystal lcd(10,9,5,4,3,2);
const int buzzerPin = 10;

void setup()
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(8,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.clear();
  motor.attach(11);
  motor.write(0); 
}
  int rot = 0;
void loop()
{
  
  
  lcd.setCursor(0,0);
  lcd.print(digitalRead(8)==HIGH);
  lcd.setCursor(1,0);
  lcd.print(digitalRead(7)==HIGH);
  lcd.setCursor(0,1);
  lcd.print("   ");
  lcd.setCursor(0,1);
  lcd.print(rot);
  
  
    motor.write(rot);
  
  if(digitalRead(7)==HIGH){
    if(rot>0){
      rot--;
    }
  }
  if(digitalRead(8)==HIGH){
    if(rot<180){
      rot++;
    }
  }
   
}


int freq(char note) 
{

  
  int i;
  const int numNotes = 8;  // number of notes we're storing


  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};
  
  
  for (i = 0; i < numNotes; i++) 
  {
    if (names[i] == note)        
    {
      return(frequencies[i]);     
    }
  }
  return(0); 
}

