#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(39, 16, 2);
Servo Pengairan;
const int Analogpin = A1;
int kelembapan = 0;

void setup()
{ 
  lcd.init();
  lcd.backlight(); 
  Pengairan.attach(11);
  Serial.begin(9600); 
}

void loop()
{ kelembapan = analogRead(A1);
  lcd.setCursor(0,0);
  lcd.print("Nilai Kelembapan");
  lcd.setCursor(0,1);
  lcd.print(kelembapan);
  delay(1000);
 if(kelembapan <= 420)
 {Pengairan.write(0);
  delay(1500);}
 else
 {Pengairan.write(90);
  delay(1500);}
}