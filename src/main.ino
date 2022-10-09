#include <SD.h>
#include <SPI.h>
#include <Wire.h>
#include "include/Constant.h"
#include "include/util/utilities.h"
#include "include/util/CSVHelper.h"

File file;
bool togglePump = false;
int reading[4];

void setup()
{
    Serial.begin(9600);

    pinMode(ERROR_PIN, OUTPUT);
    pinMode(PUMP_PIN, OUTPUT);

    file = setupSD("data.csv");
    file.println(synLine(5, "Time", "Reading1", "Reading2", "Reading3", "Reading4"));
    file.close();
}

void loop()
{
    file = SD.open("data.csv", FILE_WRITE);
    if (!file)
    {
        callErr();
    }
    else
    {
        clearErr();
        for (int i = 0; i < 4; i++)
        {
            reading[i] = analogRead(SENSORS[i]);
        }
        if (getAvg(4, reading) > 600 && (!togglePump))
        {
            togglePump = true;
            digitalWrite(PUMP_PIN, HIGH);
        }
        if (getAvg(4, reading) < 400 && (togglePump))
        {
            togglePump = false;
            digitalWrite(PUMP_PIN, LOW);
        }
        file.println(synLine(5, millis(), arry[1], arry[2], arry[3], arry[4]));
        file.close();
    }

    delay(1000);
}