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

}

void demo0ne() {
//this function will run the motors in both directions at a fixed speed

//turn on motor A
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);

//SET SPEED TO 20O OUT OF POSSIBLE RANGE 0~255
analogWrite(enA, 200);

//turn on motor B
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);

//set speed to 200 out of possible range 0~255
analogWrite(enB, 200);
delay(2000);

//now change motor directions
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);

delay(2000);

//now turn off motors
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);

}

void demoTwo()

{

 //function will run motor accross full range of speeds
 //maximum speed is determined by the motor itself and the operating voltage

 //turn on motors

digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);



//accelerate

for(int i =0; i<256; i++)
  {
    analogWrite(enA, i);
    analogWrite(enB, i);
  }

}
  void loop(){
  
      demo0ne();

      delay(1000);

      demoTwo();
  
      delay(1000);
  
  }
  
