#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(39, 16, 2);

const int trigPin = 11;
const int echoPin = 10;
float Durasi,Jarak;
int ledmerah = 12,ledhijau = 13;
int pshbtnstate = 0;

Servo servogate;

void setup()
{
  lcd.init();
  lcd.backlight();
 
  pinMode(ledhijau, OUTPUT);
  pinMode(ledmerah, OUTPUT);
  pinMode(2, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  servogate.attach(5);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  Durasi = pulseIn(echoPin, HIGH);
  
  Jarak = Durasi * 0.034/2;
  
  if (Jarak < 60)
 { 
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Silakan Ambil Karcis");
  
  pshbtnstate = digitalRead(2);
    
  if(pshbtnstate == HIGH)
   {
     digitalWrite(ledhijau, HIGH);
     digitalWrite(ledmerah, LOW);
     servogate.write(90);
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Terima Kasih");
     delay(5000);
   } 
    else
   {
    digitalWrite(ledhijau, LOW);
    digitalWrite(ledmerah, HIGH);
    servogate.write(0);
   }   
    int i=0;
    for( i = 0; i < 45; i++);
    {lcd.scrollDisplayRight();
    delay(200);}
    int a=0;
    for( a = 0; a < 45; a++);
    {lcd.scrollDisplayLeft();
    delay(200);}    
  }
  else
 {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Selamat Datang");
  servogate.write(0);
  digitalWrite(ledhijau, LOW);
  digitalWrite(ledmerah, HIGH);  
 }
  delay(1000);  
}