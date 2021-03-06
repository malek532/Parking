#include <Servo.h>
Servo servo_5;
int i=0;
#define trigPin 3
#define echoPin 4
#define ledr 6
#define ledb 7
#define moteur 5
float duration, distance;
void tourne(void){
    for (i=60 ; i<=180 ; i++)
  {
  servo_5.write(i);
  Serial.println (i);
    delay(10);
  }
 delay(1000);
 for (i=180   ; i>=60;i--)
{
  servo_5.write(i);
  Serial.println(i);
  delay (50);
}
}

void setup() {
  servo_5.attach(5);
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1000);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
  
  
  distance = (duration / 2) * 0.0343;

  Serial.print("Distance = ");
  if (distance >= 10  || distance <= 2) {
     Serial.println("Out of range");
     digitalWrite(ledr , HIGH);
     digitalWrite(ledb , LOW);
     
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
    digitalWrite(ledr , LOW);
    digitalWrite(ledb , HIGH);
    tourne();
  }
  delay(500);
}
