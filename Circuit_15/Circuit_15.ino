#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
char line1[] = {'H','e','l','l','o',' ','M','r','.',' ','C','a','r','v','e','r'};
//char line2[] = {'H','o','w',' ','a','r','e',' ','y','o','u','?',' ',' ',' ',' '};
char line2[] = "How are you?    ";
bool line1Done = false;
void setup()
{
   
  lcd.begin(16, 2);

  lcd.clear();
  Serial.begin(9600);

}

void loop()
{
  for(int i = 0; i<16; i++){
     lcd.setCursor(i,0);
    if(i<(millis()/200)){
      lcd.print(line1[i]);
      if(i == 15){
        line1Done=true;
      }
    }else{
      int r = rand();
      lcd.print(r);
    }
  } 
  for(int i = 0; i<16; i++){
     lcd.setCursor(i,1);
    if((i<((millis()/200)-16))&&line1Done){
      lcd.print(line2[i]);
    }else{
      int r = rand();
      lcd.print(r);
    }
  } 
}

