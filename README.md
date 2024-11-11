# Line Following Car Using Arduino

## Description
This project involves building a line-following car using an Arduino, two IR sensors, and a motor driver. The car detects a line on a surface and follows it by adjusting its motor movements based on sensor readings. It demonstrates basic robotics and sensor integration.

## Components Needed
- Arduino board (e.g., Arduino Uno)
- 2 IR sensors
- Motor driver (e.g., L298N or L293D)
- 2 DC motors
- Car chassis
- Power supply (batteries or power adapter)
- Jumper wires
- Breadboard (optional)

## Wiring Diagram
- **Left IR sensor**: Connect to digital pin 2
- **Right IR sensor**: Connect to digital pin 3
- **Motor driver inputs**:
  - IN1 to pin 4
  - IN2 to pin 5
  - IN3 to pin 6
  - IN4 to pin 7
- **Motor driver outputs**: Connected to the motors
- **Power**: Supply adequate voltage to the motor driver and Arduino

## Arduino Code
Upload the following code to your Arduino using the Arduino IDE:

```cpp
// Pin assignments
const int leftSensor = 2;
const int rightSensor = 3;
const int motor1Pin1 = 4;
const int motor1Pin2 = 5;
const int motor2Pin1 = 6;
const int motor2Pin2 = 7;

void setup() {
  // Set sensor pins as input
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  // Set motor pins as output
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  Serial.begin(9600); // For debugging
}

void loop() {
  int leftState = digitalRead(leftSensor);
  int rightState = digitalRead(rightSensor);

  // Case 1: Both sensors on the line
  if (leftState == LOW && rightState == LOW) {
    moveForward();
  }
  // Case 2: Left sensor off the line, right sensor on the line
  else if (leftState == HIGH && rightState == LOW) {
    turnRight();
  }
  // Case 3: Right sensor off the line, left sensor on the line
  else if (rightState == HIGH && leftState == LOW) {
    turnLeft();
  }
  // Case 4: Both sensors off the line (stop)
  else {
    stopCar();
  }
}

void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void turnRight() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void turnLeft() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void stopCar() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
```
