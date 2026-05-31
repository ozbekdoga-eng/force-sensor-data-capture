/*     Simple Stepper Motor Control Exaple Code

    by Doga Ozbek, www.HowToMechatronics.com
    https://qxf2.com/blog/arduino-tutorials-for-testers-serial-monitor/#:~:text=To%20read%20integer%20type%20of,the%20integer%20type%20of%20data. link---->Dogi

*/
// defines pins numbers
const int stepPin = 27;
const int dirPin = 32;
const int home_top = 36;
const int home_bot = 39;
int steps_min;
int steps_max;
float step_mm=0;
long delay_begin;
//long tic, tac;
// float tic_tac;



void setup() {
  Serial.begin(9600);
  // Sets the two pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(home_top, INPUT_PULLUP);
  pinMode(home_bot, INPUT_PULLUP);

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

  digitalWrite(dirPin, LOW); //Inial Positioning
  for (int x = 0; x < 0.5 * steps_max; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }

  delay(1000);

}


void loop() {

  //Serial.println("Compression Amount (mm): ");        //Prompt User for input
  while (Serial.available() == 0) {

    digitalWrite(dirPin, HIGH); //Changes the rotations direction
    delayMicroseconds(1000);
    digitalWrite(dirPin, HIGH); //Changes the rotations direction
    delayMicroseconds(1000);
    Serial.print(float(float(micros())/float(1000000)),4);
    Serial.print("\t");
    Serial.print(float(step_mm),4);
    Serial.print("\n");
  

  }          // wait for user input

  step_mm = Serial.parseFloat();

  if (step_mm!=0)
  {

  // Makes 200 pulses for making one full cycle rotation 

  for (int x = 0; x < step_mm * 100; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
    Serial.print(float(float(micros())/float(1000000)),4);
    Serial.print("\t");
    Serial.print(float(float(x)/float(100)),4);
    Serial.print("\n");
  }

  // tac = micros();
  // tic_tac = tac - tic;
  // tic_tac = tic_tac/1000000;
  // Serial.print("Time Passed (s): ");Serial.print(tic_tac,4);
  // Serial.print("\tInput (mm): ");Serial.println(step_mm);
  // delay(1000); // One second delay

  delay_begin=micros();

  while(micros()-delay_begin<1000000)
  { 
    delayMicroseconds(1000);
    digitalWrite(dirPin, LOW); //Changes the rotations direction
    delayMicroseconds(1000);
    digitalWrite(dirPin, LOW); //Changes the rotations direction
    Serial.print(float(float(micros())/float(1000000)),4);
    Serial.print("\t");
    Serial.print(float(step_mm),4);
    Serial.print("\n");
  }

  // Makes 400 pulses for making two full cycle rotation
  for (int x = 1; x <= step_mm * 100; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
    Serial.print(float(float(micros())/float(1000000)),4);
    Serial.print("\t");
    Serial.print(float(step_mm-float(x)/float(100)),4);
    Serial.print("\n");
  }
  }
}
