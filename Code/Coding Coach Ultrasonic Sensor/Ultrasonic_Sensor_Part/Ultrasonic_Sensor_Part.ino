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


void setup() {
  pinMode(TRIG_PIN, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600);
  delay(1000);
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

    distance = duration*0.34/2;//in centimeters

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

void loop() {
  usReadCm();
}
