/*
Challenges:
1) Wire the button and get motor A to move when you press and stop when you don't press
2) get motor B to move when you press and stop when don't press
3) get both motor A and B to move when you press and both to stop when you don't press
4) When you press, move both motors forward for 1 second and then stop.
5) When you press, move both motors backward for 1 second and then stop.
6) Do tape challenge

*/

void setup() {
  
  
  //-Button Setup
  pinMode(2,INPUT_PULLUP);
  
  //-Control Motor B
  pinMode(10,OUTPUT);
  pinMode(12,OUTPUT);
  
  
  //-Control Motor A
  pinMode(8,OUTPUT);
  pinMode(11,OUTPUT);
  
}


void loop() {
  
  //-if I press the button, move motor A
  if ( digitalRead(2) == LOW ) {
    digitalWrite(8,LOW);
    digitalWrite(11,HIGH);
  }
  
  //-if I don't press the button, stop motor A
  if ( digitalRead(2) == HIGH ) {
    digitalWrite(8,HIGH);
    digitalWrite(11,HIGH);
  }
  
  /*
  //-Turn on Motor B
  digitalWrite(10,LOW);
  digitalWrite(12,LOW);
  
  //-Turn on Motor A
  digitalWrite(8,LOW);
  digitalWrite(11,LOW);
  */
}
