//Initialize Ultrasonic
#define ECHO_PIN 10
#define TRIG_PIN 11

//ultrasonic timings
unsigned long currentMillis;
unsigned long previousMillis;
const unsigned long US_PERIOD = 100; //period between readings

//Max distance we want
const int MAX_DISTANCE = 200;

int distance = 0;

//motor 1
int enA=9;
int in1=8;
int in2=7;

//motor 2
int enB=3;
int in3=5;
int in4=4;


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
  
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  usReadCm();

  motorGo();
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
  }
}

void motorGo(){
  if(distance<77){
    forward();  
  }
  else{
    noward();  
  }
}


void forward() {

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

//SET SPEED TO 20O OUT OF POSSIBLE RANGE 0~255
  analogWrite(enA, 165);
  analogWrite(enB, 255);

}

void backward(){

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enA, 100);
  analogWrite(enB, 100);
}

void noward(){
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enA, 0);
  analogWrite(enB, 0);
  
}
