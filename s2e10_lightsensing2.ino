/*
Challenge #1: Find out A0 levels using input pullup resistor
- super bright: 20
- light on : 42
- light off: 64
- full darkness: 260

Challenge #2: move car when light is on, stop when light is off

Challenge #3: Find out A1 levels using input pullup resistor
- super bright: 25
- light on : 28
- light off: 52
- full darkness: 175

Challenge #4: Push the car around left/right using a flash light

Challenge #5: Car goes straight all the time but when it sees light
on the left, it turns slightly to the left.  
When it sees light on the right, it turns slightly to the right.

*/


int motb_pin1 = 3;
int motb_pin2 = 11;

int mota_pin1 = 9;
int mota_pin2 = 10;

int button_pin = 2;

int trig_pin = 4;
int echo_pin = 5;

void setup() {
  
  //-Control Motor B
  pinMode(motb_pin1,OUTPUT);
  pinMode(motb_pin2,OUTPUT);
  
  //-Control Motor A
  pinMode(mota_pin1,OUTPUT);
  pinMode(mota_pin2,OUTPUT);
  
  //- button
  pinMode(button_pin,INPUT_PULLUP);
  
  //-ultrasonic pin
  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  
  //- photoresistor pin
  pinMode(A0,INPUT_PULLUP);
  pinMode(A1,INPUT_PULLUP);
  
  Serial.begin(9600);
  
}

//-sends sound out and receives sound
//-returns the distance in centimeters
int ultrasonic() {
  
  long time;
  float distance;
  
  //-trigger a sound 
  // send out trigger signal
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trig_pin, LOW);
  
  //- a sound has gone out!!
  //- wait for a sound to come back
  
  time = pulseIn(echo_pin, HIGH);
  
  //- calculate the distance in centimeters
  distance = 0.01715 * time;
  
  return distance;

}

//- turn 90 degrees
void turnRight() {
  
  //- motor b is stopped
  analogWrite(motb_pin1,0);
  analogWrite(motb_pin2,0);
  
  //- motor a moves forward
  analogWrite(mota_pin1,255);
  analogWrite(mota_pin2,0);
  
  delay(200);
  //delay(600);
  
  //- stop motor a
  analogWrite(mota_pin1,0);
  analogWrite(mota_pin2,0);
  
}

void tankTurn(int speeda, int speedb) {
  //- motor a moves ... backwards
  analogWrite(mota_pin1,0);
  analogWrite(mota_pin2,speeda);
  
  //- motor b moves forward
  analogWrite(motb_pin1,0);
  analogWrite(motb_pin2,speedb);
  
  delay(1650);
  
  //- stop both motors
  stop();
  
}

void turnAround(int speeda, int speedb) {
  
  //- motor a is stopped
  analogWrite(mota_pin1,0);
  analogWrite(mota_pin2,0);
  
  //- motor b moves forward
  analogWrite(motb_pin1,0);
  analogWrite(motb_pin2,speedb);
  
  delay(1650);
  
  //- stop motor b
  analogWrite(motb_pin1,0);
  analogWrite(motb_pin2,0);
  
}

void turnLeft() {
  
  //- motor a is stopped
  analogWrite(mota_pin1,0);
  analogWrite(mota_pin2,0);
  
  //- motor b moves forward
  analogWrite(motb_pin1,0);
  analogWrite(motb_pin2,255);
  
  delay(200);
  //delay(800);
  
  //- stop motor b
  analogWrite(motb_pin1,0);
  analogWrite(motb_pin2,0);
  
}

void stop() {
  //- motor a
  analogWrite(mota_pin1,255);
  analogWrite(mota_pin2,255);
  
  //- motor b
  analogWrite(motb_pin1,255);
  analogWrite(motb_pin2,255);
}


void moveToWall(int speeda, int speedb) {
  
  //- move forward!
  //- motor a
  analogWrite(mota_pin1,speeda);
  analogWrite(mota_pin2,0);
  
  //- motor b
  analogWrite(motb_pin1,0);
  analogWrite(motb_pin2,speedb);
  
  //-stop when you hit a wall!!
  
  int distance = ultrasonic();
  
  while (distance > 5) {
    //-do nothing except check distance
    distance = ultrasonic();
  }
  
  //-stop!!!
  stop();
  
}



void moveForward_no_distance(int speeda, int speedb) {
  //- motor a
  analogWrite(mota_pin1,speeda);
  analogWrite(mota_pin2,0);
  
  //- motor b
  analogWrite(motb_pin1,0);
  analogWrite(motb_pin2,speedb);
}


void moveForward(int speeda, int speedb, int inches) {
  
  int myDelay;
  
  //- motor a
  analogWrite(mota_pin1,speeda);
  analogWrite(mota_pin2,0);
  
  //- motor b
  analogWrite(motb_pin1,0);
  analogWrite(motb_pin2,speedb);
  
  //- move forward the distance in inches
  
  myDelay = inches*125;
  delay(myDelay);
  
  //- stop
  stop();
  
}

void moveBackward(int speeda, int speedb) {
  
  //- motor a
  analogWrite(mota_pin1,0);
  analogWrite(mota_pin2,speeda);
  
  //- motor b
  analogWrite(motb_pin1,speedb);
  analogWrite(motb_pin2,0);
  
}

void loop() {
  
  Serial.println(analogRead(A1));
  
  delay(100);
  
  //- if the A1 light is on, move the left wheel forward
  if (analogRead(A1) < 30) {
    //-move the left wheel forward
    turnRight();
  }
  else {
    //-stop the left wheel
  }
  
  //- if the A0 light is on, move the right wheel forward
  if (analogRead(A0) < 45) {
    turnLeft();
  }
  else {
    
  }
  
  
  
  /*
  //- if light is on
  if (analogRead(A0) < 45) {
    moveForward_no_distance(200,200);
  }
  //- if light is off
  else if (analogRead(A0) > 45) {
    stop();
  }
  */
  
 /* 
  //- loop here as long as the button is NOT pressed
  while (digitalRead(button_pin)==HIGH) {
    //- do nothing
  }
  
  //- code jumps here once you press the button
  delay(1000);
  moveToWall(120,120);
  */
}
