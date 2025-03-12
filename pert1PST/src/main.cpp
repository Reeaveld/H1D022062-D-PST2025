#include <Arduino.h>

// put function declarations here:
int LED1 = D0;
int LED2 = D3;
int LED3 = D4;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED1,HIGH);
  delay(50);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,HIGH);
  delay(50);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,HIGH);
  delay(50);
  digitalWrite(LED3,LOW);
  digitalWrite(LED2,HIGH);
  delay(50);
  digitalWrite(LED2,LOW);
}
