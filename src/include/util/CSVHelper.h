#include <stdarg.h>
#include <string.h>

/**
 * @param n number of items to integrate
 * @return a string used to log to csv file (parsed by comma)
 */
String synLine(int n, ...)
{
    va_list varList;
    va_start(varList, n);

    String str;
    for (int i = 0; i < n; i++)
    {
        str += varList[i];
        if (i != n - 1)
            str += ", "
    }

    va_end(varList);
    return str;
}

String synLine(int n, int arry[])
{
    String str;
    for (int i = 0; i < n; i++)
    {
        itoa(arry[i], str);
        if (i != n - 1)
            str += ", ";
    }

    return str;
}