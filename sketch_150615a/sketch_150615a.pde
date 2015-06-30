import processing.serial.*;
int pos=90;
Serial port;
void  setup()
{
  size(720,200);
  println(Serial.list()[0]);
  port = new Serial(this, Serial.list()[0],57600);
  
  
  
}
void draw()
{
  pos=mouseX/4;
  port.write("f");
  
}
