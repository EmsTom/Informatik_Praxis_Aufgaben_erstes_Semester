#include <stdio.h>
#include <stdlib.h>
#include "numberConvert.h"

int Ausgangszahl = 0;
int Zahlensystem = 0;
char ausgabe[33];



int main()
{
    printf("Geben Sie die Umzurechnene Dezimalzahl ein.\n");
    scanf("%d",&Ausgangszahl);
    printf("Geben sie ihr gewuenschtes Zahlensystem an! Binaer: 2, Octal: 8, Hexadezimal: 16\n");
    scanf("%d",&Zahlensystem);
    ConvertDec(Ausgangszahl, Zahlensystem, ausgabe);
    printf("%s", ausgabe);
    printf("\n");
    system("Pause");
    return 0;
}


