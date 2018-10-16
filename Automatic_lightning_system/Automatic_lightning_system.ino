int motionSensorPin = 7;    //the digital pin connected to the PIR sensor's output
int ledPin = 11;
int lightSensorPin = A5;
int lightThreshold = 180;



void setup(){
  Serial.begin(9600);
  pinMode(motionSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

////////////////////////////
//LOOP
void loop(){
  Serial.print(analogRead(lightSensorPin));
  Serial.print("     ");
  Serial.print(digitalRead(motionSensorPin));
  if (analogRead(lightSensorPin) > lightThreshold){
    
    if(digitalRead(motionSensorPin) == 1) {
        digitalWrite(ledPin, HIGH);
        Serial.println("    Y");
    } else {
      digitalWrite(ledPin, LOW);
         Serial.println("    N");
    }
  } else {
        Serial.println("    NN");
    digitalWrite(ledPin, LOW);
 }

  delay(500);


}
  
  

