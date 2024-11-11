// Pin assignments
const int MyLeftSensor = 2;
const int MyRightSensor = 3;
const int MyMotor1Pin1 = 4;
const int MyMotor1Pin2 = 5;
const int MyMotor2Pin1 = 6;
const int MyMotor2Pin2 = 7;

void setup() {
  // Set sensor pins as input
  pinMode(MyLeftSensor, INPUT);
  pinMode(MyRightSensor, INPUT);

  // Set motor pins as output
  pinMode(MyMotor1Pin1, OUTPUT);
  pinMode(MyMotor1Pin2, OUTPUT);
  pinMode(MyMotor2Pin1, OUTPUT);
  pinMode(MyMotor2Pin2, OUTPUT);

  Serial.begin(9600); // For debugging
}

void loop() {
  int LeftyLefty = digitalRead(MyLeftSensor);
  int Behold_TheRight = digitalRead(MyRightSensor);

  // Case 1: Both sensors on the line
  if (LeftyLefty == LOW && Behold_TheRight == LOW) {
    moveForward();
  }
  // Case 2: Left sensor off the line, right sensor on the line
  else if (LeftyLefty == HIGH && Behold_TheRight == LOW) {
    turnRight();
  }
  // Case 3: Right sensor off the line, left sensor on the line
  else if (Behold_TheRight == HIGH && LeftyLefty == LOW) {
    turnLeft();
  }
  // Case 4: Both sensors off the line (stop)
  else {
    stopCar();
  }
}

void moveForward() {
  digitalWrite(MyMotor1Pin1, HIGH);
  digitalWrite(MyMotor1Pin2, LOW);
  digitalWrite(MyMotor2Pin1, HIGH);
  digitalWrite(MyMotor2Pin2, LOW);
}

void turnRight() {
  digitalWrite(MyMotor1Pin1, LOW);
  digitalWrite(MyMotor1Pin2, HIGH);
  digitalWrite(MyMotor2Pin1, HIGH);
  digitalWrite(MyMotor2Pin2, LOW);
}

void turnLeft() {
  digitalWrite(MyMotor1Pin1, HIGH);
  digitalWrite(MyMotor1Pin2, LOW);
  digitalWrite(MyMotor2Pin1, LOW);
  digitalWrite(MyMotor2Pin2, HIGH);
}

void stopCar() {
  digitalWrite(MyMotor1Pin1, LOW);
  digitalWrite(MyMotor1Pin2, LOW);
  digitalWrite(MyMotor2Pin1, LOW);
  digitalWrite(MyMotor2Pin2, LOW);
}