//CODE CREATED BY DOMINIK POWIRSKI
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  bool signal = false;
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(9, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0); 
  lcd.print("    REACTION GAME");
  lcd.setCursor(0,1); 
  lcd.print("   ARDUINO STATS:"); 
}
int ender = 1;
int x = 0; 
int z = 1;
unsigned long start = 0;
bool v = false;
unsigned long end = 0;
int xyz = 1;


void loop() {
  if(digitalRead(2) == 0 && z == 1 && v == true){
  x = 1;
  z = 0;
  digitalWrite(7, HIGH);
  end = millis() - start;
  digitalWrite(9, LOW);
  } 
  
  else if(digitalRead(4) == 0 && z == 1 && v == true){
  x = 2;
  z = 0;
  digitalWrite(6, HIGH);
  end = millis() - start;
  digitalWrite(9, LOW);
  }
  
  else if(digitalRead(8) == 0 && xyz == 1){
  start = millis();
  xyz = 0;
  digitalWrite(9, HIGH);
  v = true;
  } 
  
  else if(end != 0 && ender == 1){
    Serial.println(x);
    Serial.println(end);
    ender = 0;
    delay(100);
    show();
  }
  delay(5);

}

void show(){
  lcd.setCursor(0,2);
  lcd.print("PLAYER");
  lcd.setCursor(8,2);
  lcd.print(x); 
  lcd.setCursor(10,2); 
  lcd.print(" WON!!!");
  lcd.setCursor(0,3); 
  lcd.print("TIME:"); 
  lcd.setCursor(7,3); 
  lcd.print(end); 
  lcd.setCursor(14,3); 
  lcd.print("MILLIS"); 

}
