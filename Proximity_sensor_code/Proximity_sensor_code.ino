// Define the pins for the ultrasonic sensor
const int trigPin = 2;
const int echoPin = 3;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Set the trigger pin as an OUTPUT
  pinMode(trigPin, OUTPUT);
  // Set the echo pin as an INPUT
  pinMode(echoPin, INPUT);
}

void loop() {
  // Trigger a pulse to the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the duration of the pulse from the echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  int distance = duration / 58.2; // Speed of sound is approximately 343 meters/second (34300 cm/second)

  // Output the distance to the serial monitor for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000); // Delay for readability, adjust as needed
}
