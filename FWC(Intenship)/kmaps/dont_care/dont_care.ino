//Declaring all variables as integers
int Z=0,Y=0,X=1,W=1;  // int Z,Y,X,W
int D,C,B,A;

//Code released under GNU GPL.  Free to use for anything.
void disp_7447(int D, int C, int B, int A)
{
  digitalWrite(2, A); //LSB
  digitalWrite(3, B); 
  digitalWrite(4, C); 
  digitalWrite(5, D); //MSB

}
// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(2, OUTPUT);  
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    //pinMode(6,OUTPUT);
    //pinMode(7,OUTPUT);
    //pinMode(8,OUTPUT);
    //pinMode(9,OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //W = digitalWrite(6);
  //X = digitalWrite(7);
  //Y = digitalWrite(8);
  //Z = digitalWrite(9);
  A=(!W);
  B=(!W&&X&&!Z || W&&!X);
  C=(W&&X&&!Y&&!Z || !X&&Y || !W&&Y);
  D=(W&&X&&Y || !X&&Z);
  
disp_7447(D,C,B,A);  
}
