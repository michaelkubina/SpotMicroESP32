#define LatchingRelay D2
void setup()
{
    pinMode(LatchingRelay,OUTPUT);
 
    
}
void loop()
{
    digitalWrite(LatchingRelay,LOW);
    delay(1000);
    digitalWrite(LatchingRelay,HIGH);
    delay(1000);
}
