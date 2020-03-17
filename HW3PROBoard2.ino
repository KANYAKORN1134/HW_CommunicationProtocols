#define latch 10
#define data 11
#define clk 13
int count;
int a[8] = {
   0b00000110, //1
   0b01011011, //2
   0b01001111, //3
   0b11100110, //4
   0b01101101, //5
   0b01111101, //6
   0b00100111, //7
   0b01111111, //8
 };
void setup(){
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  if(Serial.available()){
    char a = Serial.read();
    if(a == '1'){
      count--;
    }
    if(a == '2'){
      count++;
    }
  }
  if(count == 8){
    count = 0;
  }
  if(count == -1){
    count = 7;
  }
  shiftOut(data,clk,MSBFIRST,a[count]);
  digitalWrite(10, HIGH);
  digitalWrite(10, LOW);
  Serial.println(count);
}
