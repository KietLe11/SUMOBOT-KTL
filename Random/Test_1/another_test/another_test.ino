//#define FIND REPLACE-WITH
#define MOTORA_1 6
#define MOTORA_2 9
#define MOTORB_1 10 
#define MOTORB_2 11

void setup() {
  //pinMode(PIN Number,OUTPUT)
  pinMode(MOTORA_1, OUTPUT);
  pinMode(MOTORA_2, OUTPUT);
  pinMode(MOTORB_1, OUTPUT);
  pinMode(MOTORB_2, OUTPUT);
  
  digitalWrite(MOTORA_1, LOW);
  digitalWrite(MOTORA_2, LOW);
  digitalWrite(MOTORB_1, LOW);
  digitalWrite(MOTORB_2, LOW);
}

void loop() {
  
  analogWrite(MOTORA_1, 128);
  
  analogWrite(MOTORB_1, 128);

  delay(1000);
  
  analogWrite(MOTORA_1, 0);
  
  analogWrite(MOTORB_1, 0);
  delay(1000);

  
  analogWrite(MOTORA_2, 128);
  
  analogWrite(MOTORB_2, 128);

  delay(1000);
  
  analogWrite(MOTORA_2, 0);
  
  analogWrite(MOTORB_2, 0);
  delay(1000);
}
