/*
Challenges:
1) create LS and HS function for motor A
2) create LS and HS function for motor B
3) create LS and HS function for moving forward
4) create LS and HS function for moving backward
5) when you press moves forward HS, not press moves forward LS
6) adjust motor A and motor B HS + LS functions so that the robot goes perfectly.
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

void motorAForwardHS() {
  analogWrite(8,0);
  analogWrite(11,255);
}

void motorAForwardLS() {
  analogWrite(8,0);
  analogWrite(11,110);
}


void motorAStop() {
  digitalWrite(8,HIGH);
  digitalWrite(11,HIGH);
}

void loop() {
  
  motorAForwardHS();
  
  delay(1000);
  
  motorAForwardLS();
  
  delay(1000);
  

/*
  motorAForward();
  delay(1000);
  motorAStop();
  delay(1000);
  
  motorABackward();
  delay(1000);
  motorAStop();
  delay(1000);
  */

}
