#include <Servo.h>              // Add library  (Kütüphaneyi Ekleyin)
#include<vexMotor.h>
#include <SPI.h>  
#include "RF24.h"
RF24 myRadio(7, 8);
byte addresses[][6] = {"0"};
Servo name_servo;               // Define any servo name  (Servo İsmi Tanımlayın)
vexMotor wheelL; vexMotor wheelR; vexMotor wheelF;
int isAuto = 0;
#define trigPin 2
#define echoPin 3
const int buzzer = 6; const int light = 5;
const int light2 = 1;
struct Control {
   int data;
   int turn;
   int isAuto;
   int buzzer;
   int light;
};
struct Control cnt;

void setup() {
  Serial.begin(9600);
  wheelF.attach(4); wheelR.attach(9); wheelL.attach(10);
  pinMode(trigPin, OUTPUT); // setting the output pin with fast output (will output signals in high speed)
  pinMode(echoPin, INPUT); // setting the input pin with fast input (will get signals in high speed)
  pinMode(buzzer, OUTPUT);
  pinMode(light, OUTPUT); 
  pinMode(light2, OUTPUT);delay(1000);
  myRadio.begin(); 
  myRadio.setChannel(115); 
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS ) ; 
  myRadio.openReadingPipe(1, addresses[0]);
  myRadio.startListening();
  
}
int x;
void loop() {
  if ( myRadio.available())  {
    while (myRadio.available()) {
      myRadio.read( &cnt, sizeof(cnt) );
    }
    if (cnt.buzzer) {
        tone(buzzer, 1000); // Send 1KHz sound signal...
    } else {
        noTone(buzzer);
    }
    if (cnt.light) {  
        digitalWrite(light, HIGH);
        digitalWrite(light2, HIGH);
    } else {
        digitalWrite(light, LOW);
        digitalWrite(light2, LOW);
    }
    Serial.print(cnt.isAuto);
    Serial.print("<- state");
    Serial.print(", buzzer = ");
    Serial.print(cnt.buzzer);
    Serial.print(", light = ");
    Serial.print(cnt.light);
    if (cnt.isAuto == 0) {
      x = constrain(map(cnt.data, -600, 600, -254, 254), -254, 254);
      wheelL.write(-x);
      wheelR.write(x);
   
      wheelF.write(cnt.turn * 150);
      Serial.print("\n3Data:");
      Serial.print(cnt.data);
      Serial.print(", turn=");
      Serial.println(cnt.turn); 
    } 
    else {
      long duration, distance;
      digitalWrite(trigPin, LOW); // making the signal low
      delayMicroseconds(2); // waiting for 2 microseconds
      digitalWrite(trigPin, HIGH); // sending the signal to the sonic to trigger it
      delayMicroseconds(10); // keeping the output as HIGH to create the 10 microsecond pulse for triger
      digitalWrite(trigPin, LOW); // setting output back to LOW, now the triger pulse is generated and accordingly
  // a 40 KHz signal will be sent out of the transmitter
      duration = pulseIn2(echoPin, HIGH); // get the calculated duration from the function
      distance = (duration/2) / 29; // considers the speed of sound [(343.2m/s)/10000]
      Serial.print(distance);
      Serial.println("cm");
    
      if (distance < 7) {
          
//          tone(buzzer, 1000); // Send 1KHz sound signal...
//          delay(500);        // ...for 0.5 sec
//          noTone(buzzer);
          
          wheelF.write(130);
          wheelL.write(0);
          wheelR.write(0);
          delay(800);
          wheelF.write(0);
      } else {
          wheelF.write(0);
          wheelL.write(150);
          wheelR.write(-150);
          delay(500);
      }
   }
  }
}



unsigned long pulseIn2(uint8_t pin, uint8_t state) {
 unsigned long pulseWidth = 0;
 unsigned long loopCount = 0;
 unsigned long loopMax = 5000000;
 // While the pin is *not* in the target state we make sure the timeout hasn't been
//reached.
 while ((digitalRead(pin)) != state) {
 if (loopCount++ == loopMax) {
return 0;
 }
 }
 // When the pin *is* in the target state we bump the counter while still keeping
//track of the timeout.
 while ((digitalRead(pin)) == state) {
 if (loopCount++ == loopMax) {
return 0;
 }
 pulseWidth++;
 }
 // Return the pulse time in microseconds
 return pulseWidth * 2.36/2; //the coefficient here (2.36) is the value to be tweaked
// pulse width may vary from device to device
}
