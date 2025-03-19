#include <Arduino.h>

// deklarasi variabel

int echoPin = D2;
int trigPin = D1;
int ledPin = D0;


// deklarasi variabel waktu dan jarak

long duration;
int distance;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
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

  // set LED berdasarkan kondisi
  if(distance < 10){
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(1000);
}