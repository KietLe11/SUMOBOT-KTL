#define MOTOR_A 5 // Defines the pins for the motors with name
#define MOTOR_B 6 // Defines the pins for the motors with name
#define ENABLE 9 // Define Enable Pin
void setup() {
// put your setup code here, to run once:
pinMode(MOTOR_A, OUTPUT); // Tells Arduino to set pin to output
pinMode(MOTOR_B, OUTPUT); // Tells Arduino to set pin to output
pinMode(ENABLE, OUTPUT); // Tells Arduino to set pin to output
digitalWrite(ENABLE, HIGH); //Turns on the enable pin
//to enable motor controller
//LOW would turn it off
}
void loop() {
// put your main code here, to run repeatedly:
//Motor runs in one direction
analogWrite(MOTOR_A, 0); //Set MOTOR_A pin to 0
analogWrite(MOTOR_B, 128); //Set Motor_B pin to 50% duty
delay(1000); // Wait 1000 milliseconds
//Stop motor
analogWrite(MOTOR_A, 0);
analogWrite(MOTOR_B, 0);
delay(1000); // Wait 1000 milliseconds
//Code will loop back to 'void loop(){' line
//when it gets here
}
