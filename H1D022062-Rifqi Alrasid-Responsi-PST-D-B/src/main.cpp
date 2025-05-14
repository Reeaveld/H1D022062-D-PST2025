#include <Arduino.h>
#include <Servo.h>

Servo myservo;

void setup()
{
  myservo.attach(D0);
}

int echoPin = D2;
int trigPin = D1;
int servoPin = D0;


// deklarasi variabel waktu dan jarak

long duration;
int distance;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(servoPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(9);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // untuk menghitung waktu sinyal diterima
  duration = pulseIn(echoPin, HIGH);

  // menghitung jarak
  distance = duration * 0.034 / 2;
  // display serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // set Servo berdasarkan kondisi
  if(distance < 15){
    digitalWrite(servoPin, HIGH);
    myservo.write(90);
  } else {
    digitalWrite(servoPin, HIGH);
    myservo.write(0);
  }
  delay(1000);
}