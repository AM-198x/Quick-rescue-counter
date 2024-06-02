#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int IRpin = 8;
int IR2 = 7;
int IR3 = 9;
int i = 0;
int pinbaz = 10;

void setup() {
  pinMode(pinbaz, OUTPUT);
  pinMode(IRpin, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("people:  ");
  lcd.setCursor(0, 1);
  lcd.print("Inside: ");
  lcd.setCursor(7, 1);
  lcd.print(i);
 
}

void loop() {
  int readValue = digitalRead(IRpin);
  int readValue2 = digitalRead(IR2);
  int readValue3 = digitalRead(IR3);

  if (readValue3 == LOW) {
    tone(10, 5000);
    delay(1000);
    tone(10, 2000);
    delay(1000);
     tone(10, 5000);
    delay(1000);
    tone(10, 2000);
    delay(1000);
    noTone(pinbaz);
      lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Fire Alert");
    delay(1000);
    lcd.clear();
    lcd.print("Exit through the ");
    lcd.setCursor(0,1 );
    lcd.print("emergency door");
    delay(1000);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("people:  ");
  lcd.setCursor(0, 1);
  lcd.print("Inside: ");
  lcd.setCursor(7, 1);
  lcd.print(i);
  }
  if (readValue == LOW) {
    i++;
    lcd.setCursor(7, 0);
    lcd.print(i);
    lcd.setCursor(7, 1);
    lcd.print(i);
    delay(1000);
  }

  if (readValue2 == LOW) {
    if (i > 0) {
      i--;
      lcd.setCursor(7, 1);
      lcd.print(i);
      delay(1000);
    }}}