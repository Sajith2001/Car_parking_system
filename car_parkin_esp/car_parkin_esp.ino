#include <Servo.h>

#define TRIG_PIN_1 2 // Pin for the first ultrasonic sensor's trigger
#define ECHO_PIN_1 3 // Pin for the first ultrasonic sensor's echo
#define SERVO_PIN_1 12 // Pin for the first servo motor

#define TRIG_PIN_2 4 // Pin for the second ultrasonic sensor's trigger
#define ECHO_PIN_2 5 // Pin for the second ultrasonic sensor's echo
// #define SERVO_PIN_2 8 // Pin for the second servo motor

Servo servo1; // Create a servo object for the first sensor
// Servo servo2; // Create a servo object for the second sensor

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);
  pinMode(TRIG_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);

  servo1.attach(SERVO_PIN_1); // Attach the first servo to the specified pin
  // servo2.attach(SERVO_PIN_2); // Attach the second servo to the specified pin
}

void loop() {
  long duration1, distance1;
  long duration2, distance2;
  
  // Code for the first ultrasonic sensor
  digitalWrite(TRIG_PIN_1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_1, LOW);
  duration1 = pulseIn(ECHO_PIN_1, HIGH);
  distance1 = (duration1 / 2) / 29.1;

  // Code for the second ultrasonic sensor
  digitalWrite(TRIG_PIN_2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_2, LOW);
  duration2 = pulseIn(ECHO_PIN_2, HIGH);
  distance2 = (duration2 / 2) / 29.1;

  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.println(" cm");

  Serial.print("Distance 2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  if (distance1 <= 6) { // Adjust the maximum distance as needed
    Serial.println("Object detected by Sensor 1");
    // Perform your desired actions when an object is detected by Sensor 1 or Sensor 2
    servo1.write(90); // Adjust the angle as needed
}
 else if (distance2 <= 6) {
    Serial.println("Object detected by Sensor 2");
    // Perform your desired actions when no object is detected by Sensor 1 or Sensor 2
    servo1.write(90); // Adjust the angle as needed
 }else {
    Serial.println("No object detected by Sensor 1 or Sensor 2.");
    // Perform your desired actions when no object is detected by Sensor 1 or Sensor 2
    servo1.write(0); // Adjust the angle as needed
}


  // if (distance2 >= 6) { // Adjust the maximum distance as needed
  //   Serial.println("No object detected by Sensor 2.");
  //   // Perform your desired actions when an object is detected by Sensor 2
  //   servo1.write(90); // Adjust the angle as needed
  // } else {
  //   Serial.println("Object detected by Sensor 2!");
  //   // Perform your desired actions when no object is detected by Sensor 2
  //   servo1.write(0); // Adjust the angle as needed
  // }

  delay(2000); // Delay for stability
}
