#include "LedControl.h"
LedControl lc = LedControl(12, 11, 10, 1);
byte heart[] =
{
  B00111100,
  B01111110,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B01111110,
  B00111100
};
byte left[] =
{
  B00011000,
  B00110000,
  B01100000,
  B11111111,
  B11111111,
  B01100000,
  B00110000,
  B00011000
};

byte right[] =
{
  B00011000,
  B00001100,
  B00000110,
  B11111111,
  B11111111,
  B00000110,
  B00001100,
  B00011000
};
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4); 
const int flexpin = A0;
const int flexpin1 = A1;//센서와 연결된 아날로그 핀 설정
int sw = 9;       // 스위치(SW) 핀 설정
int led = 6;       // LED 핀 설정
int state = LOW;      // LED 상태
int reading;          // SW 상태
int previous = LOW;   // SW 이전 상태
long time = 0;        // LED가 ON/OFF 토글된 마지막 시간
long debounce = 100;  // Debounce 타임 설정

void setup()
{
  Serial.begin(9600);
  pinMode(sw, INPUT_PULLUP); // SW 를 설정, 아두이노 풀업저항 사용
  pinMode(led, OUTPUT);      // LED 설정
  pinMode(flexpin, INPUT);
  pinMode(flexpin1, INPUT);
 lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
   lc.shutdown(0, false);
  lc.setIntensity(0, 4);
  lc.clearDisplay(0);
  lcd.setCursor(5,0);
  lcd.print("riding");
}
void loop()
{
  reading = digitalRead(sw);  // SW 상태 읽음
  //SW 가 눌려졌고 스위치 토글 눌림 경과시간이 Debounce 시간보다 크면 실행
  if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    if (state == HIGH)    // LED 가 HIGH 면 LOW 로 바꿔준다.
      state = LOW;
    else                  // LED 가 LOW 면 HIGH 로 바꿔준다.
      state = HIGH;
    time = millis();
  }
  digitalWrite(led, state);
  previous = reading;
 int flexVal; //센서값을 저장할 변수 설정
  flexVal = analogRead(flexpin);
   Serial.print(flexVal);
   delay(100);
   Serial.print("\n");
   int flexVal1; //센서값을 저장할 변수 설정
  flexVal1 = analogRead(flexpin1);
   Serial.print(flexVal1);  
if(flexVal<350&&state==HIGH){
  if(flexVal1>350){
  lcd.setCursor(4,1);
  lcd.print("RIGHT!!!");
  display_heart(3); 
  display_heart(1);}
}
 else if(flexVal1<350&&state==HIGH){
  if(flexVal>350){
  lcd.setCursor(4,1);
  lcd.print("LEFT!!!");
  display_heart(3);
  display_heart(2);
  }
  }
  else{
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("riding");
  display_heart(0);}
}
void display_heart(int a)
{
  if (a == 0) {
    for (int i = 0; i < 8; i++)
    {
      lc.setRow(0, i,heart[i]);
    }
  }
  else if (a==1){
    for (int i = 0; i < 8; i++)
    {
      lc.setRow(0, i, right[i]);
    }
  }
  else if(a==2){
    for (int i = 0; i < 8; i++)
    {
      lc.setRow(0, i, left[i]);
    }
  }
  else {
    for (int i = 0; i < 8; i++)
    {
      lc.setRow(0, i, B00000000);
    }
  }   }
