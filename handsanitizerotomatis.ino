/*
 * Simple Automatic Sanitizer
 * Was made and developed for Social Activities (KKN-UGM)
 */

const int trigPin  = 11;              // trigPin, echoPin and relayPin are adjustable, depends on the connection your components to the Arduino
const int echoPin  = 12; 
const int relayPin = 10; 
const int batasJarak = 25;            // centimeters, and adjustable depends on your optimal condition

float jarak;
long durasi;

void setup() {
  Serial.begin (9600);      
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);   
  pinMode(relayPin, OUTPUT); 
}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  durasi = pulseIn(echoPin, HIGH);

  jarak = 0.034*(durasi/2);

  if(jarak < batasJarak)                          // The alcohol (sanitizer) comes out
    {
      digitalWrite(relayPin, LOW);
      delay(1000);
      digitalWrite(relayPin, HIGH);
      delay(2000);

    }
  else{
    digitalWrite(relayPin, HIGH); 
  }
    

  // print the value to Serial Monitor, for monitoring only
//  Serial.print("jarak: ");
//  Serial.print(jarak);
//  Serial.println(" cm");

  delay(200);
}
