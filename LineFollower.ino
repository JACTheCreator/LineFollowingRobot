#include <Servo.h>

Servo rightServo;
Servo leftServo;

/*
 * The setup() function is called when a sketch starts. 
 * Use it to initialize variables, pin modes, start using libraries, etc.
 */
void setup() 
{
  /**
   * Configures the specified pins on the sensors to behave an input.
   */
  pinMode(2, INPUT); //s0
  pinMode(3, INPUT); //s1
  pinMode(4, INPUT); //s2
  pinMode(5, INPUT); //s3
  pinMode(6, INPUT); //s4
  pinMode(7, INPUT); //s5
  pinMode(8, INPUT); //s6
  pinMode(9, INPUT); //s7
}


void loop() 
{
  if(digitalRead(5) == 0 && digitalRead(6) == 0)
  {	   
    forward();
  }	  
  else if(digitalRead(2) == 0 || digitalRead(3) == 0 || digitalRead(4)== 0 || digitalRead(5) == 0)
  {	  
    right(); 
  }	  
  else if(digitalRead(6) == 0 || digitalRead(7) == 0 || digitalRead(8) == 0 || digitalRead(9) == 0)	
  {	  
    left();
  }	 
  else
  {	 
    stop();
  }
}

/*
 *
 */
void forward()
{
  checkAttachedStatus();
  leftServo.write(-180);
  rightServo.write(180);
}

/*
 *
 */
void reverse()
{
  checkAttachedStatus();
  leftServo.write(180);
  rightServo.write(-180);
}

/*
 *
 */
void left()
{
  checkAttachedStatus();
  leftServo.write(-180);
  rightServo.write(-180);
}

/*
 *
 */
void right()
{
  checkAttachedStatus();
  leftServo.write(180);
  rightServo.write(180);
}

/*
 *
 */
void stop()
{
 rightServo.detach();
 leftServo.detach();
}

/*
 *
 */
void checkAttachedStatus()
{
  if(!leftServo.attached() && !rightServo.attached())
  {
    rightServo.attach(12);
    leftServo.attach(13);
  }
}
