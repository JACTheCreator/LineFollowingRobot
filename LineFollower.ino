#include <Servo.h>

Servo rightServo;
Servo leftServo;

/**
 * The setup() function is called when a sketch starts. 
 * Use it to initialize variables, pin modes, start using libraries, etc.
 */
void setup() 
{
  pinMode(11, INPUT);

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
  followLine(digitalRead(11));
}

/**
 * If the value is: 
 * 0/false/LOW -> Follows a white line on a black surface
 * 1/true/HIGH -> Follows a black line on a white surface
 */
void followLine(uint8_t lineColour)
{
  if(digitalRead(5) == lineColour && digitalRead(6) == lineColour)
  {	   
    forward();
  }	  
  else if(digitalRead(2) == lineColour || digitalRead(3) == lineColour || digitalRead(4)== lineColour || digitalRead(5) == lineColour)
  {	  
    right(); 
  }	  
  else if(digitalRead(6) == lineColour || digitalRead(7) == lineColour || digitalRead(8) == lineColour || digitalRead(9) == lineColour)	
  {	  
    left();
  }	 
  else
  {	 
    stop();
  }
}

/**
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
