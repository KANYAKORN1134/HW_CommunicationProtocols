#include<Wire.h>
int b1 = A0;
int b2 = A1;
int wire;
void setup(){
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Wire.begin();
  Serial.begin(9600);
}
void loop(){
  if(digitalRead(b1) == 1){
    while(digitalRead(b1) == 1);
    Serial.print(1);
    Wire.beginTransmission(1);
    Wire.write(1);
    Wire.endTransmission();
  }
   if(digitalRead(b2) == 1){
    while(digitalRead(b2) == 1);
    Serial.print(2);
    Wire.beginTransmission(1);
    Wire.write(2);
    Wire.endTransmission();
  }
}
  
