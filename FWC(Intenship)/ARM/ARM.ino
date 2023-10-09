
int Y,U,V,W;
void setup()
{
 pinMode(7, OUTPUT);
 pinMode(2, INPUT);
 pinMode(3, INPUT);
 pinMode(4, INPUT);
}
void loop(){
  U = digitalRead(2);
 V = digitalRead(3);
 W = digitalRead(4);
 Y = (!U&&!V&&W)||(!U && V && !W)||(U&&!V&&W)||(U&&V&&W);
 digitalWrite(7, Y);
 
}
