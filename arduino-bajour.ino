int relay = 5;
int PIRInterrupt = 3;
volatile byte relayState = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);

  pinMode(PIRInterrupt, INPUT);  
  Serial.begin(9600);
}

void loop(){
  //Serial.println(sddigitalRead(PIRInterrupt));
  if (digitalRead(PIRInterrupt) == HIGH){
    Serial.println("Motion");
    delay(500);
    if (digitalRead(PIRInterrupt) == HIGH){
      if (relayState == LOW){
        digitalWrite(relay, LOW);
        relayState = HIGH;
      } else {
        digitalWrite(relay, HIGH);
        relayState = LOW;
      }
      Serial.println("Turned " + String(relayState));
    }
  }

  while (digitalRead(PIRInterrupt) == HIGH){
    delay(100);
  }
 }
