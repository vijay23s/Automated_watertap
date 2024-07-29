#define trig 5
#define echo 6
#define op 7
float Time,dis;

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(op, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
   digitalWrite(op, LOW);
   digitalWrite(trig, LOW);
   delayMicroseconds(2);
   digitalWrite(trig, HIGH);
   delayMicroseconds(10);
   digitalWrite(trig, LOW);

   Time=pulseIn(echo,HIGH);
   dis=(0.034/2)* Time;
   delay(100);
    while(dis>2 && dis<15)
      {
          digitalWrite(op,HIGH);
          digitalWrite(trig, LOW);
          delayMicroseconds(2);
          digitalWrite(trig, HIGH);
          delayMicroseconds(10);
          digitalWrite(trig, LOW);
  
          Time=pulseIn(echo,HIGH);
          dis=(0.034/2)* Time;
          Serial.println(dis);
          Serial.println("cm");
          delay(100);
      }
}
