#include "../Constant.h"
#include <SPI.h>
#include <SD.h>
#include <stdarg.h>

double getAvg(int length, double arry[])
{
    int sum;
    for (int i = 0; i < length; i++)
        sum += arry[i];
    return (double)sum / (double)length;
}

double getAvg(int length, ...)
{
    va_list varList;
    va_start(varList, length);

    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += varList[i];
    }
    va_end(varList);

    return (double)sum / (double)length;
}

void callErr()
{
    digitalWrite(ERROR_PIN, HIGH);
}

void clearErr()
{
    digitalWrite(ERROR_PIN, LOW);
}

File setupSD(String filename)
{
    File file;
    while (!SD.begin(SPI_PIN))
        callErr();
    clearErr();

    while (!file)
    {
        file = SD.open(filename, FILE_WRITE);
        callErr();
    }
    clearErr();
    return file;
}