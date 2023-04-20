struct Plant
{
    int sensor1;
    int sensor2;
    int pump;
    bool isOn;
} controllers[3];

void setup()
{
    for (int i = 1; i < 6; i += 2)
    {
        controllers[i].sensor1 = i;
        controllers[i].sensor2 = i + 1;
        controllers[i].pump = i + 2;
        pinMode(i, OUTPUT);
    }
    Serial.begin(9600);
}

void loop()
{
    if (analogRead(7) > 1020)
        digitalWrite(10, HIGH);
    else
        digitalWrite(10, LOW);

    for (int i = 0; i < 3; i++)
    {
        if (analogRead(controllers[i].sensor1) >= 800.0 || analogRead(controllers[i].sensor2) >= 800.0)
        {
            controllers[i].isOn = true;
        }

        if (analogRead(controllers[i].sensor1) <= 400.0 || analogRead(controllers[i].sensor2) <= 400.0)
        {
            controllers[i].isOn = false;
        }

        if (controllers[i].isOn = true)
        {
            digitalWrite(controllers[i].pump, HIGH);
        }
        Serial.print(i);
        Serial.print("1: ");
        Serial.print(analogRead(controllers[i].sensor1));
        Serial.print(" ");
        Serial.print(i);
        Serial.print("2: ");
        Serial.print(analogRead(controllers[i].sensor2));
        Serial.print(" ");
    }
    Serial.println();
    delay(500);
}