#include<Wire.h>
#define latch 10
#define data 11
#define clk 13
int count;
int n[8]=
{
   0b10000000, 
   0b01000000, 
   0b00100000, 
   0b00010000, 
   0b00001000,
   0b00000100,  
   0b00000010, 
   0b00000001
   
};
void setup(){
  Wire.begin(1);
  Wire.onReceive(receiveEvent);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  shiftOut(data, clk, LSBFIRST, n[8]);
  digitalWrite(10, HIGH);
  digitalWrite(10, LOW);
}
void loop(){
  delay(100);
}
void receiveEvent(int howMany){
  int x = Wire.read();
  if(x == 2){
    count++;
  }
  if(x == 1){
    count--;
  }
  if(count == 8){
    count = 0;
  }
  if(count == -1){
    count = 7;
  }
  shiftOut(data,clk,LSBFIRST,n[count]);
  digitalWrite(10, HIGH);
  digitalWrite(10, LOW);
}
