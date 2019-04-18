#include <Servo.h> 

Servo left;
Servo right;


void setup() 
{ 
  left.attach(9);

  right.attach(10);
  
} 

void loop() {
  
    right.write(180);
    left.write(-180);

    delay(5000);

    right.write(180);
    left.write(180);

    delay(2000);
      
    } 
