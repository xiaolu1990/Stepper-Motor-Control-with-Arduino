#define forwardLedPin 10 // the pin for LED to indicate forward processing
#define backwardLedPin 13 // the pin for LED to indicate backward processing
#define forwardPin 2 // the pin for the forward button
#define backwardPin 3 // the pin for the backward button
#define PUL 7 // the output pin of the pulse form
#define DIR 6 // the pin for the direction

int delta_theta = 45;  // the forward degree at each step move
int stepPerRevolution = 6400;  // the total steps per revolution

int state_forward = 0;  // the initial state for the forward button
int state_backward = 0; // the initial state for the backward button 
int pulsePerStep;


void setup() {
  // define the pinModes
  pinMode(forwardLedPin, OUTPUT);
  pinMode(backwardLedPin, OUTPUT);
  pinMode(forwardPin, INPUT);
  pinMode(backwardPin, INPUT);
  pinMode(PUL, OUTPUT);
  pinMode(DIR, OUTPUT);
}

void loop() {
  // read the button state
  state_forward = digitalRead(forwardPin);
  state_backward = digitalRead(backwardPin);
  
  // forward a certain degree in clockwise when the forward button is pressed
  if (state_forward == HIGH){
    digitalWrite(DIR, HIGH);
    digitalWrite(forwardLedPin, HIGH);
    stepPulseForm();
    digitalWrite(forwardLedPin, LOW);
  }
  else if (state_backward == HIGH){
    digitalWrite(DIR, LOW);
    digitalWrite(backwardLedPin, HIGH);
    stepPulseForm();
    digitalWrite(backwardLedPin, LOW);
  }
}

void stepPulseForm(){
  // declares the pulse form for each rotation step
  pulsePerStep = delta_theta * stepPerRevolution / 360;
  for (int i=0; i<pulsePerStep; i++){
    digitalWrite(PUL, HIGH);
    delayMicroseconds(50);
    digitalWrite(PUL, LOW);
    delayMicroseconds(50);
  }
}
