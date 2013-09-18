// Controlling a servo pair position using a Parallax 2-Axis Joystick 27800 (coupled variable resistor) 
// Serves in an elbow configuration 
// As modified by Colin Chapman [ChapLab]

#include <Servo.h> 
 
Servo Aservo;                           // create servo object to control servo base 
Servo Bservo;                           // create servo object to control servo arm 
 
int xAxis = 0;                          // analog pin used to connect the x axis of the joystick
int yAxis = 1;                          // analog pin used to connect the y axis of the joystick
int xVal  ;                             // variable to read the value from the x axis of the joystick
int yVal  ;                             // variable to read the value from the y axis of the joystick
 
void setup() 
{ 
  Aservo.attach(9);                     // attaches base servo on pin 9 to the servo object 
  Bservo.attach(8);                     // attaches arm servo on pin 8 to the servo object 
} 
 
void loop() 
{ 
  xVal = analogRead(xAxis);             // reads the value of the x axis of the joystick (value between 0 and 1023) 
  xVal = map(xVal, 0, 1023, 0, 179);    // scale it to use it with the servo (value between 0 and 180) 
  Aservo.write(xVal);                   // sets the servo position according to the scaled value 
  yVal = analogRead(xAxis);             // reads the value of the y axis of the joystick (value between 0 and 1023) 
  yVal = map(yVal, 0, 1023, 0, 179);    // scale it to use it with the servo (value between 0 and 180) 
  Bservo.write(yVal);                   // sets the servo position according to the scaled value 
  delay(15);                            // waits for the servo to get there 
} 
