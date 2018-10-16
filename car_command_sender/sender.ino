#include <SPI.h>  
#include "RF24.h"
RF24 myRadio(7, 8);
byte addresses[][6] = {"0"};
const int press = A0;
const int breakPed = A1;
const int left = 2;
const int right = 3; 
const int autoButton = 4;
const int buzzer = 5;
const int light = 6;

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
  myRadio.begin();  
  myRadio.setChannel(115); 
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate(RF24_250KBPS) ; 
  myRadio.openWritingPipe(addresses[0]);
  pinMode(press, INPUT);
  pinMode(breakPed, INPUT);
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  pinMode(autoButton, INPUT);
  pinMode(light, INPUT);
  cnt.data = 0;
  cnt.turn = 0;
  cnt.isAuto = 0;
  cnt.buzzer = 0;
  cnt.light = 0;
  delay(1000);
}
int x = 0, y = 0, z = 0, p = 0, k = 0, m = 0, d = 0;
int last = 0; int isChanged = 0; int prev = 0;
void loop() {
  myRadio.write(&cnt, sizeof(cnt)); 
  Serial.print("\nSender: gas=");
  Serial.print(x);
  Serial.print(", break=");
  Serial.print(y);
  x = analogRead(press);
  y = analogRead(breakPed);
  cnt.data = x - y;
  z = digitalRead(left);
  p = digitalRead(right);
  k = digitalRead(autoButton);
  m = digitalRead(buzzer);
  d = digitalRead(light);
  if ((k == 1 && last == 0)) {
    last = 1;
    delay(1000);
  } else {
    if (k == 1 && last == 1) {
      last = 0;
      delay(1000);
    }
  }

  if (d == 1 && prev == 0) {
    prev = 1;
    delay(500);
  } else {
      if (d == 1 && prev == 1) {
        prev = 0;
        delay(500);
      }
  }
  
  Serial.print(", turnL =");
  Serial.print(z);
  Serial.print(", turnR =");
  Serial.print(p);
  Serial.print(", state = ");
  Serial.print(last);
  Serial.print(", buzzer = ");
  Serial.print(m);
  Serial.print(", light = ");
  Serial.print(prev);
  cnt.turn = z - p;
  cnt.isAuto = last;
  cnt.buzzer = m;
  cnt.light = prev;
//  delay(500);
}
