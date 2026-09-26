#include LiquidCrystal_I2C.h
#include Servo.h
#include Keypad.h

int ledh = 10;
int ledm = 11;
int pshbtn = 0;

LiquidCrystal_I2C lcd(39, 16, 2);

Servo kunci;

#define panjang_sandi 5
char Data[panjang_sandi];
char Sandi[panjang_sandi] = 1234;
char unikKey;

byte data_count =0;

const byte Row = 4;
const byte Column = 4;

char keys[Row][Column]=
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'', '0', '#', 'D'}
};
byte columnPins[Column] = {6, 7, 8, 9};
byte rowPins[Row] = {2, 3, 4, 5};

bool pintu = true ;

Keypad unikKeypad(makeKeymap(keys), rowPins, columnPins, Row, Column);

void setup() {
  
pinMode(ledh, OUTPUT);
pinMode(ledm, OUTPUT);
pinMode(12, INPUT);  
  
lcd.init();
lcd.backlight();
 
kunci.attach(13);
Serial.begin(9600);
}

void loop(){
pshbtn = digitalRead(12);  
if (pshbtn == HIGH)
  {kunci.write(0);
   lcd.clear();
   lcd.print(terkunci);
   delay(1500);
   pintu = 1;}
   
if(pintu == 0)
  {unikKey = unikKeypad.getKey();}
  
else open();
}

void clearData()
{while (data_count != 0){Data[data_count--] = 0;}
  return;}

void open()
{ lcd.setCursor(0,0);
  lcd.print(masukan password);
  kunci.write(0);
  digitalWrite(ledh,LOW);
  digitalWrite(ledm,HIGH);
  unikKey = unikKeypad.getKey();
 if (unikKey)
   {Data[data_count]=unikKey;
    lcd.setCursor(data_count, 1);
    lcd.print(Data[data_count]);
    data_count++;}
 if (data_count == panjang_sandi - 1)
   {if(!strcmp(Data, Sandi))
    {lcd.clear();
     lcd.print(Terbuka);
     digitalWrite(ledh, HIGH);
     digitalWrite(ledm, LOW);
     kunci.write(90);  
     pintu = 0;
     clearData();
     }
    else{
     lcd.clear();
     lcd.print(sandi salah);
     delay(2500);
     pintu = 1;
     clearData();
    }
   }
}
