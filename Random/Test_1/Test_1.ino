

//motor 1
int enA=9;
int in1=8;
int in2=7;

//motor 2
int enB=3;
int in3=5;
int in4=4;



void setup() {
   // set all motor pins to outputs

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  delay(10000);
}

void forward() {

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

//SET SPEED TO 20O OUT OF POSSIBLE RANGE 0~255
  analogWrite(enA, 100);
  analogWrite(enB, 100);

}

void backward(){

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enA, 100);
  analogWrite(enB, 100);
}

void spinclock(){

  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  analogWrite(enA, 100);
  analogWrite(enB, 100);
  
}

void spincounter(){
  
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enA, 100);
  analogWrite(enB, 100);
  
}


void loop(){

 
  backward();
  delay(1000);
  forward();
  delay(1000);
}
