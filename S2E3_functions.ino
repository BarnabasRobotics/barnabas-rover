/*
Function/Sub-routine
- set/group/list of instructions

Challenges
1) create motor A forward function
2) create motor A backward function
3) create motor A stop function
4) move motor A forward 1 sec, stop 1 sec, backward 1 sec, stop 1 sec
5) Do the [1-4] but with motor B
6) create move car forward/backward/stop function
7) ruler challenge

*/

void setup() {
  
  //-Control Motor B
  pinMode(10,OUTPUT);
  pinMode(12,OUTPUT);
  
  
  //-Control Motor A
  pinMode(8,OUTPUT);
  pinMode(11,OUTPUT);
  
}

void motorABackward() {
  digitalWrite(8,HIGH);
  digitalWrite(11,LOW);
}

void motorAForward() {
  digitalWrite(8,LOW);
  digitalWrite(11,HIGH);
}

void motorAStop() {
  digitalWrite(8,HIGH);
  digitalWrite(11,HIGH);
}

void loop() {

/*  
  digitalWrite(10,HIGH);
  digitalWrite(12,HIGH);
  */
  
  motorAForward();
  delay(1000);
  motorAStop();
  delay(1000);
  
  motorABackward();
  delay(1000);
  motorAStop();
  delay(1000);

}
