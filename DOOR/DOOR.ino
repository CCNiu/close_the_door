#include <Ultrasonic.h>

Ultrasonic ultrasonic(12, 13);
int distance;
int no_close_time;
void setup() {
  Serial.begin(9600);
}
void loop() {
  delay(500); //每次間格1秒
  no_close_time =0;//設計時器
  distance = ultrasonic.read(); //不加參數就是輸出CM，可用read(INC)輸出英寸
  while( distance>5){     //若未關門
    no_close_time = no_close_time + 1 ; //計數器++
    delay(1000);        //delay
    Serial.print("no_close_time: ");
    Serial.println(no_close_time);
    if (no_close_time>=6){
      close_the_fucking_door();
    }
    distance = ultrasonic.read(); //不加參數就是輸出CM，可用read(INC)輸出英寸
  }
  Serial.print("Distance in CM: ");
  Serial.println(distance);
}
void close_the_fucking_door(){
  tone(7,3000,1000);
  delay(1010);
}