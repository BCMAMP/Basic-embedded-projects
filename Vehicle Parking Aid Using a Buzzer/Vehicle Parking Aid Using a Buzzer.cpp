int Buzzer = 9;
const int Trigger = 11, Echo = 10;
float Durasi, Jarak;

void setup()
{
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  
  Durasi = pulseIn(Echo, HIGH);
  Jarak = Durasi * 0.034/2;
  
  if (Jarak < 60)
  {digitalWrite(Buzzer, HIGH);
   delay(1000);}
  
  else
  {digitalWrite(Buzzer, LOW);
   delay(1000);}
}