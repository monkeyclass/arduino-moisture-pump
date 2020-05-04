// constants
const int pumpPin = 12;
const int sensorPin = A0;
const int moistLimit = 400;

const long mesInterval = 10000;


// variables
int pump_state = HIGH;
int sensorValue;
int limit = 300;

unsigned long prevMillis = 0;
unsigned long curMillis = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pumpPin, OUTPUT);
  // Serial.begin(9600);
}

void loop() {
  curMillis = millis();
  if (curMillis - prevMillis >= mesInterval) {
    sensorValue = analogRead(sensorPin);
    if (sensorValue > moistLimit) {
      digitalWrite(pumpPin, HIGH);
      prevMillis = curMillis;
      delay(5000);
      digitalWrite(pumpPin, LOW);
    }
  }
}

// digitalWrite(pumpPin, HIGH);
// sensorValue = analogRead(sensorPin); // only enable shortly when measure needed. e.g once every two hour
// Serial.println("Analog Value : ");
// Serial.println(sensorValue);
//  delay(1000); // use millis instead like in rummiduino