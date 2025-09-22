#include <LiquidCrystal.h>
#define echo 8
#define trig 9
long read;
int dist;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() { 
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(echo,INPUT);
   pinMode(trig,OUTPUT);
}


void loop() {
digitalWrite(trig,LOW);
  delayMicroseconds(2);
digitalWrite(trig,HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig,LOW);
  read = pulseIn(echo,HIGH);
  dist = (read/2)/29.1;
  if(dist>=100){ 
 Serial.println(dist);
  lcd.setCursor(0,0);
  lcd.print(dist);
  lcd.setCursor(3,0);
    lcd.print("Cm");
  }  
  else{
 Serial.println(dist);
  lcd.setCursor(0,0);
  lcd.print(dist);
  lcd.setCursor(2,0);
    lcd.print("Cm ");  
  
  
  
  } 
  
}