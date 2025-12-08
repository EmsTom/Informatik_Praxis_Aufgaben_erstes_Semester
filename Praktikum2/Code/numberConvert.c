#include <string.h>
#include <math.h>
#include "numberConvert.h"

const char hexsymbole[] = "0123456789ABCDEF";


void ConvertDec(int zahl, int system, char ausgabe[])
{
    //Abbruch Bedingung, falls kein gueltiges Zahlensystem eingegeben wurde
    if (system !=2 && system != 8 && system != 16)
    {
        strcpy(ausgabe, "Fehler: Ungueltiges Zahlensystem.");
        return;
    }

    int exponent = 0;
    //Exponenten finden
    while ((int)pow(system, exponent + 1) <= zahl)
    {
        exponent++;
    }

    int i = 0;
    int startExponent = exponent;
    for (i = 0; i <= startExponent; i++)
    {
        int ziffer = (int)(zahl / pow(system, exponent));

        ausgabe[i] = hexsymbole[ziffer]; // Zuweisung ist jetzt korrekt

        zahl -= ziffer * (int)pow(system, exponent);
        exponent--;
    }
    ausgabe[i] = '\0';
}