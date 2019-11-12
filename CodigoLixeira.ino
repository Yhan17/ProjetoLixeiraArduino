#include <Ultrasonic.h>

#include <Servo.h>

const int trigPin = 6;
const int echoPin = 5;
Servo myservo;
 
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(2);
}

void loop() {
 int duration, distance,pos=0,i;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = abs((duration/2) / 29);
 
  
   Serial.print(distance);
   Serial.println(" cm");
  
 if(distance<=7)
  {
     myservo.write(300);
     delay(4500);

 }
  else{
    myservo.write(90);
  } 
 delay(450);
}
