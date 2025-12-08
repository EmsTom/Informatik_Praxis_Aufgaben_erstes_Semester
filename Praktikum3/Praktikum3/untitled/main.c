#include <stdio.h>
#include <stdlib.h>
#include "split.h"

char String[256];
char splitChar;
int maxParts = 0;
int maxLength = 0;
int anzahlDerTeile = 0;

int main(void)
{
    printf("Bitte geben sie die zu zertrennende Zeichenkette an:\n");
    fgets(String, sizeof(String), stdin);

    printf("Geben sie das Zeichen an an welchem Zeichen die Zeichenkette getrennt werden soll:\n");
    splitChar = getchar();

    printf("Geben sie die Maximale Anzahl der moeglichen Teile der Zeichenkette an:\n");
    scanf("%d", &maxParts);

    printf("Geben sie die Maximale Groesse/Laenge eines der Teile der Zeichenkette an:\n");
    scanf("%d", &maxLength);

    char *ergebnisListe[maxParts];
    //Speicherreservierung während Laufzeit
    for (int i = 0; i < maxParts; i++)
    {
        // Reserviere Platz für maxLength Zeichen + Null-Terminator
        ergebnisListe[i] = (char *)malloc(maxLength + 1);
        if (ergebnisListe[i] == NULL)
        {
            printf("Speicherzuweisung fehlgeschlagen!\n");
            // Bereinigung des bereits zugewiesenen Speichers
            for (int j = 0; j < i; j++) {
                free(ergebnisListe[j]);
            }
            return 1;
        }
    }
    anzahlDerTeile = split_ignore_empty(String, splitChar, ergebnisListe, maxParts, maxLength);
    printf("In der Gesamten Zeichenketten waren: %d Teilstrings\n ", anzahlDerTeile);
    return 0;
}
