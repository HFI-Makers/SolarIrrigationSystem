struct Plant
{
    int sensor1, sensor2;
    int pump;
    bool isOn;
} controller[3];

int lightTimer = 0;

void setup()
{
    for (int i = 0; i < 3; i++)
    {
        controller[i].sensor1 = 2 * i + 1;
        controller[i].sensor2 = 2 * i + 2;
        controller[i].pump = 2 * i + 2;
        pinMode(2 * i + 2, OUTPUT);
    }
    Serial.begin(9600);
}

void loop()
{
    if (lightTimer == 10 * 60 * 2)
    {
        int readings = 0;
        for (int i = 0; i < 10; i++)
        {
            readings += analogRead(7);
            delay(100);
        }
        char *str;
        sprintf(str, "Brightness: %f", readings / 10.0);
        Serial.print(str);
        if ((double)readings / 10.0 >= 1020)
            digitalWrite(10, LOW);
        else
            digitalWrite(10, HIGH);
    }

    for (int i = 0; i <= 2; i++)
    {
        if (analogRead(controller[i].sensor1) > 900 || analogRead(controller[i].sensor2) > 900)
            controller[i].isOn = true;

        if (analogRead(controller[i].sensor1) < 700 || analogRead(controller[i].sensor2) < 700)
            controller[i].isOn = false;

        if (controller[i].isOn)
            digitalWrite(controller[i].pump, LOW);
        else
            digitalWrite(controller[i].pump, HIGH);
    }

    for (int i = 0; i <= 2; i++)
    {
        Serial.print(analogRead(controller[i].sensor1));
        Serial.print(" ");
        Serial.print(analogRead(controller[i].sensor2));
        Serial.print(" ");
        Serial.print(controller[i].isOn);
        Serial.print(" ");
    }
    Serial.println();

    lightTimer++;
    delay(500);
}