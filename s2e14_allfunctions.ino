/*
Topics Covered:
- How to use the button to change the mode of the car so that it can blink lights, sense light, avoid obstacles and follow a line.

Tutorial at: https://youtu.be/NYNL7z_iMzM
*/


int motb_pin1 = 3;
int motb_pin2 = 11;

int mota_pin1 = 9;
int mota_pin2 = 10;

int button_pin = 2;

int trig_pin = 4;
int echo_pin = 5;

int right_sensor_pin = 6;
int left_sensor_pin = 12;

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
  
  //-IR sensor pin
  pinMode(right_sensor_pin,INPUT);
  pinMode(left_sensor_pin,INPUT);
  
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
  
  delay(600);
  
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
  
  delay(800);
  
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
  
  //while (distance > 5) {
  while (distance > 5 || distance == 0) {
  
    //-do nothing except check distance
    distance = ultrasonic();
    Serial.println(distance);
    
    if (digitalRead(2)==LOW) {
      break;
    }
    
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

void forward() {
  //- motor a
  analogWrite(mota_pin1,150);
  analogWrite(mota_pin2,0);
  
  //- motor b
  analogWrite(motb_pin1,0);
  analogWrite(motb_pin2,150);
}

void tankRight() {
  //- motor a
  analogWrite(mota_pin1,150);
  analogWrite(mota_pin2,0);
  
  //- motor b
  analogWrite(motb_pin1,150);
  analogWrite(motb_pin2,0);
}

void tankLeft() {
  //- motor a
  analogWrite(mota_pin1,0);
  analogWrite(mota_pin2,150);
  
  //- motor b
  analogWrite(motb_pin1,0);
  analogWrite(motb_pin2,150);
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

void lineFollower() {
  //- 1 -> senses black
  //- 0 -> senses white
 
  
  int leftStatus = digitalRead(left_sensor_pin);
  int rightStatus = digitalRead(right_sensor_pin);
  

  if (leftStatus == 1 && rightStatus == 0) {
    //-left sensor sees black
    //-tank left
    tankLeft();
  }
  
  if (rightStatus == 1 && leftStatus == 0) {
    //- right sensor sees black
    //- tank right
    tankRight();
  }
  
  if (leftStatus == 0 && rightStatus == 0) {
    //- both sensors see white
    //- go straight
    forward();
  }
  
  if (leftStatus == 1 && rightStatus == 1) {
    //- both sensors see black/nothing 
    //- stop
    stop();
  }
}

void loop() {
  
  while (digitalRead(2)==HIGH) {
  }
  delay(1000);
  
  for (int i=0; i<5 ; i++) {
    digitalWrite(7,LOW);
    delay(100);
    digitalWrite(7,HIGH);
    delay(100);
  }
  
  //-wait for button to trigger light sensing
  while (digitalRead(2)==HIGH) {
  }
  delay(1000);
 
  while (digitalRead(2)==HIGH) {
   if (analogRead(A0) < 100) {
      forward();
   }
   if (analogRead(A0) > 100) {
      stop();
   }
  }
  delay(1000);
  
  //-avoid obstacles
  
  while (digitalRead(2)==HIGH) {
    moveToWall(200,200);
    delay(1000);
    moveBackward(200,200);
    delay(500);
    stop();
    delay(1000);
  }
  delay(1000);
  
  //-line following mode
  while (1==1) {
    lineFollower();
  }
  
}
