// defines pins numbers
const int stepPin = 3;
const int dirPin = 2;
int potensio;
void setup() {
  // Sets the two pins as Outputs
  Serial.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}
void loop() {

  digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
    Serial.println(potensio);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(100);
  } //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
