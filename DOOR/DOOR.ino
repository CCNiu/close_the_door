#include <Ultrasonic.h>
#include <TM1637.h>        //主程式需要程式庫 “TM1637.h”

#define CLK 3              //數碼管  CLK 接 Arduino pin 3
#define DIO 2              //數碼管  DIO 接 Arduino pin 2

TM1637 tm1637(CLK,DIO);
Ultrasonic ultrasonic(12 , 13);
int distance=0;
int no_close_time=0;
int people_num=0;
int num = 0;               //設定數碼管會用到的整數
int numdisplay = 0;
int dig1 = 0;  
int dig2 = 0;  
int dig3 = 0;  
int dig4 = 0;  

void setup() {
  Serial.begin(9600);
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}

void loop() {
  delay(500); //每次間格1秒
  no_close_time =0;//設計時器
  distance = ultrasonic.read(); //不加參數就是輸出CM，可用read(INC)輸出英寸
  while( distance > 20 ){     //若未關門或沒有人進出
    no_close_time = no_close_time + 1 ; //計數器++
    delay( 1000 );        //delay
    Serial.print( "no_close_time:" );
    Serial.println( no_close_time );
    if ( no_close_time >= 6 ){
      close_the_fucking_door();
    }
    distance = ultrasonic.read(); //不加參數就是輸出CM，可用read(INC)輸出英寸
  }
  if ( distance < 20){
    people_num++;
    show_num;
  }
  c
  Serial.print( " Distance in CM: ");
  Serial.println( distance );
}
void show_num(){
  num = people_num;                             //用數碼管顯示距離
  Serial.println(num);
  numdisplay = num; 
  dig4 = numdisplay / 1000;
  numdisplay = numdisplay - (dig4 * 1000);
  dig3 = numdisplay / 100; 
  numdisplay = numdisplay - (dig3 * 100);
  dig2 = numdisplay / 10; 
  dig1 = numdisplay - (dig2 *10);
  tm1637.display(0,dig4);       //千位數
  tm1637.display(1,dig3);       //百位數
  tm1637.display(2,dig2);       //十位數
  tm1637.display(3,dig1);       // 個位數
  delay(100);  
}
void close_the_fucking_door(){
  tone(7 , 3000 , 100);
  delay(100);
}