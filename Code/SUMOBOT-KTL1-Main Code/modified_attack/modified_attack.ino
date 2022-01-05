//Initialize Ultrasonic
#define ECHO_PIN 10
#define TRIG_PIN 11

//ultrasonic sensorrrrr
//ultrasonic timings
unsigned long currentMillis;
unsigned long previousMillis;
const unsigned long US_PERIOD = 100; //period between readings
//Max distance we want
const int MAX_DISTANCE = 200;
int distance;

//motor 1
int enA=9;
int in1=8;
int in2=7;

//motor 2
int enB=3;
int in3=5;
int in4=4;

//line sensors
int lsLeft = 2;
int lsRight = 6;
int sensorValueLeft;
int sensorValueRight;

//attack adjustment
boolean target = false;
int targetD = 67;
String action;



void setup() {
  pinMode(TRIG_PIN, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an INPUT

  // set all motor pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //line sensor setup
  pinMode(lsLeft, INPUT);
  pinMode(lsRight,INPUT);
  
  Serial.begin(9600);
  delay(5000);
}

void loop() {
  usReadCm();

  attack();
  
  lineSensor();
}

void usReadCm(){
  currentMillis = millis();
  
  if(currentMillis > previousMillis + US_PERIOD){
    
    //clears trig
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    //sets the trig pin to high for 10 microseconds
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    //reads the echo_pin
    long duration = pulseIn(ECHO_PIN, HIGH, 38000);

    distance = duration*0.034/2;//in centimeters

    if(distance > MAX_DISTANCE){
      distance = MAX_DISTANCE;
    }
    if(distance == 0){ 
      distance = MAX_DISTANCE;
    }

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    previousMillis = currentMillis;

    if((distance<targetD) && (sensorValueLeft==1) && (sensorValueRight==1)){
     target = true; 
     }
  }
}

void attack(){
  
  if(sensorValueLeft==0 && sensorValueRight==0){
    backward();
    target = false;
    action = "backing up";
    Serial.println(action);
    }
  else if(sensorValueLeft==0){
    turnRight();
    target = false;
    action = "turning right";
    Serial.println(action);
    }
  else if(sensorValueRight==0){
    turnLeft();
    target = false;
    action = "turning left";
    Serial.println(action);
    }
    else if((target == true) && (sensorValueLeft==1) && (sensorValueRight==1) ){
    forward();
    action = "attacking";
    Serial.println(action);
    }
    else if (!(target == true) && (sensorValueLeft==1) && (sensorValueRight==1) ){
    forward();
    action = "looking";
    Serial.println(action);
    }
  }
  
void lineSensor(){
  sensorValueLeft = digitalRead(lsLeft);
  Serial.print(sensorValueLeft);

  sensorValueRight = digitalRead(lsRight);
  Serial.print(sensorValueRight);
  }


void forward() {

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

//SET SPEED TO 20O OUT OF POSSIBLE RANGE 0~255
  analogWrite(enA, 255);
  analogWrite(enB, 255);

}

void backward(){

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enA, 255);
  analogWrite(enB, 255);
}


void turnLeft(){

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  analogWrite(enA, 255);
  analogWrite(enB, 0);
}

void turnLeft(int tempSpeed){

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  analogWrite(enA, tempSpeed);
  analogWrite(enB, 0);
}

void turnRight(){

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enA, 0);
  analogWrite(enB, 255);
}

void turnRight(int tempSpeed){

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enA, 0);
  analogWrite(enB, tempSpeed);
}

//turn by having wheels spin in opposite directions
void turnturnLeft(int tempSpeed){

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  analogWrite(enA, tempSpeed);
  analogWrite(enB, tempSpeed);
}

void turnturnRight(int tempSpeed){

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enA, tempSpeed);
  analogWrite(enB, tempSpeed);
}

void noward(){
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enA, 0);
  analogWrite(enB, 0);
  
}
