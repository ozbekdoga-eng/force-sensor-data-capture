/*     Simple Stepper Motor Control Exaple Code

    by Dejan Nedelkovski, www.HowToMechatronics.com
    https://qxf2.com/blog/arduino-tutorials-for-testers-serial-monitor/#:~:text=To%20read%20integer%20type%20of,the%20integer%20type%20of%20data. link---->Dogi

*/
// defines pins numbers
const int stepPin = 8;
const int dirPin = 9;
const int home_top = 4;
const int home_bot = 5;
int steps_min;
int steps_max;
float step_mm;
long tic, tac;
float tic_tac;


void setup() {
  Serial.begin(9600);
  // Sets the two pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(home_top, INPUT_PULLUP);
  pinMode(home_top, INPUT_PULLUP);

  digitalWrite(dirPin, LOW); //Homing for top.
  while (digitalRead(home_top)) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  steps_min = 0;
  delay(1000);

  digitalWrite(dirPin, HIGH); //Homing for bottom.
  while (digitalRead(home_bot)) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
    steps_max++;
  }
  delay(1000);

  digitalWrite(dirPin, LOW);
  for (int x = 0; x < 0.5 * steps_max; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }

  delay(1000);


}

void loop() {

  Serial.println("How old are you? ");        //Prompt User for input
  while (Serial.available() == 0) {}          // wait for user input
  step_mm = Serial.parseFloat();

  digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  tic = micros();
  for (int x = 0; x < step_mm * 100; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
  }
  tac = micros();
  tic_tac = tac - tic;
  tic_tac = tic_tac/1000000;
  Serial.print("Time Passed (s): ");Serial.print(tic_tac,4);
  Serial.print("\tInput (mm): ");Serial.println(step_mm);
  delay(1000); // One second delay

  digitalWrite(dirPin, LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for (int x = 0; x < step_mm * 100; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
  }
//  Serial.println(step_mm);
  delay(1000);
}
