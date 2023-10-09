int Z,Y,X,W;
int D,C,B,A;
void setup(){
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(13,OUTPUT);
}
void loop(){
  digitalWrite(13,HIGH);
  delay(1000);
  D = (!Z&&!Y&&!X&&!W) || (!Z&&!Y&&!X&&W);
  C = (!Z&&!Y&&X&&!W)|| (!Z&&!Y&&X&&W) ||(!Z&&Y&&!X&&!W) || (!Z&&Y&&!X&&W);
  B = (!Z&&!Y&&X&&!W) ||(!Z&&!Y&&X&&W)|| (!Z&&Y&&X&&!W) || (!Z&&Y&&X&&W);
  A = (!Z&&!Y&&!X&&!W)|| (!Z&&!Y&&X&&!W) ||(!Z&&Y&&!X&&!W)|| (!Z&&Y&&X&&!W)|| (Z&&!Y&&!X&&!W);
  digitalWrite(2,A);
  digitalWrite(3,B);
  digitalWrite(4,C);
  digitalWrite(5,D);
  digitalWrite(13,LOW);
  W = digitalRead(6);
  X = digitalRead(7);
  Y = digitalRead(8);
  Z = digitalRead(9); 
}
