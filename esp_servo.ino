#include <Servo.h>

Servo servo;

int isObstaclePin = D3;  // This is our input pin
int isObstacle = HIGH;  // HIGH MEANS NO OBSTACLE
int led = 2;

void setup() {
  servo.attach(D4); //D4
  servo.write(0);
  Serial.begin(115200); // Communication speed
  pinMode(led, OUTPUT);
  pinMode(isObstaclePin, INPUT);
}

void loop() {
  isObstacle = digitalRead(isObstaclePin);
  if (isObstacle == LOW)
  {
    Serial.println("OBSTACLE!!, OBSTACLE!!");
    digitalWrite(led, HIGH);
    servo.write(110);
    delay(500);
    servo.write(0);
    delay(500);
  }
  else
  {
    Serial.println("clear");
    digitalWrite(led, LOW);
  }
}
