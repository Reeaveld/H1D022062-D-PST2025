#include <Arduino.h>
#include <Servo.h>

Servo myservo;

void setup()
{
  myservo.attach(D0);
}

void loop()
{
  for(int pos=0; pos<=180; pos++){ // goes from 0 degrees to 180 degrees
      myservo.write(pos);
      delay(5);
  }

  for(int pos=180; pos>=0; pos--){ // goes from 180 degrees to 0 degrees
      myservo.write(pos);
      delay(5);
  }

  myservo.write(180);
  delay(500);
  myservo.write(0);
  delay(500);
  myservo.write(180);
  delay(500);
  // Add a delay to prevent the loop from running too fast
}