/*
Challenges:
1) Rewire motors to pins 3,11,9 and 10
2) Make functions for forward, backwards and stop
3) Make function for forward and backwards that allows you to set speed
4) Make your car move and slow down by using the for loop
5) Change forward and backwards functions so that you can set the speed for BOTH motors.
6) Create function to turnRight() and turnLeft()
*/

int motb_pin1 = 3;
int motb_pin2 = 11;

int mota_pin1 = 9;
int mota_pin2 = 10;

int button_pin = 2;

void setup() {
  
  //-Control Motor B
  pinMode(motb_pin1,OUTPUT);
  pinMode(motb_pin2,OUTPUT);
  
  //-Control Motor A
  pinMode(mota_pin1,OUTPUT);
  pinMode(mota_pin2,OUTPUT);
  
  //- button
  pinMode(button_pin,INPUT_PULLUP);
  
}

//- turn 90 degrees
void turnRight() {
  
}

void turnLeft() {
  
}

void stop() {
  //- motor a
  analogWrite(mota_pin1,255);
  analogWrite(mota_pin2,255);
  
  //- motor b
  analogWrite(motb_pin1,255);
  analogWrite(motb_pin2,255);
}

void moveForward(int speed) {
  
  //- motor a
  analogWrite(mota_pin1,speed);
  analogWrite(mota_pin2,0);
  
  //- motor b
  analogWrite(motb_pin1,0);
  analogWrite(motb_pin2,speed);
  
}

void moveBackward(int speed) {
  
  //- motor a
  analogWrite(mota_pin1,0);
  analogWrite(mota_pin2,speed);
  
  //- motor b
  analogWrite(motb_pin1,speed);
  analogWrite(motb_pin2,0);
  
}



void loop() {
  
  if (digitalRead(button_pin)==LOW) {
    for (int i=255;i>0;i--) {
      moveForward(i);
      delay(100);
    }
    
    
  }
  else {
    stop();
  }

}
