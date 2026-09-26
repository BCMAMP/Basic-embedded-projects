#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(39, 16, 2);
int Tilt = 7, Kondisi;

void setup()
{
  pinMode(Tilt, INPUT);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop()
{
  int Kondisi = digitalRead(Tilt);
  lcd.setCursor(0,0);
  lcd.print("Posisi");
  if(Kondisi == HIGH)
  {
  lcd.setCursor(0,1);
  lcd.print("Tegak");
  }
  else{
  lcd.setCursor(0,1);
  lcd.print("Miring");
  }
}