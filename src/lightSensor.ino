void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println(analogRead(5));
    delay(100);
}