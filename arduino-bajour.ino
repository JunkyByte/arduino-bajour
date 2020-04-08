int relay = 8;
int led_alwaystrue = 2;
int PIRInterrupt = 3;
volatile byte relayState = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(relay, OUTPUT);
  pinMode(led_alwaystrue, OUTPUT);
  digitalWrite(led_alwaystrue, HIGH);
  digitalWrite(relay, HIGH);

  pinMode(PIRInterrupt, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIRInterrupt), detectMotion, RISING);
  
  Serial.begin(9600);
}

void loop(){
  //Serial.println(digitalRead(PIRInterrupt));
}

void detectMotion(){
  Serial.println("Motion");
  Serial.println(digitalRead(PIRInterrupt));
  if (relayState == LOW){
    digitalWrite(relay, LOW);
    relayState = HIGH;
  } else {
    digitalWrite(relay, HIGH);
    relayState = LOW;
  }
  Serial.println("Turned " + String(relayState));
}
