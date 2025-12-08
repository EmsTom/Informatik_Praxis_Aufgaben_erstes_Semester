
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "split.h"

int split(char *string ,char splitChar, char **parts, int maxParts, int maxLength)
{
    int iMerker = 0;
    int partsAnzahl = 1;
    //size_t ist der parameter welcher von strlen zurückgegeben wird
    size_t stringLen = strlen(string);
    //Durchlaufe ganzen String
    for (int i = 0; i < stringLen; i++)
    {
        //Prüfe ob aktuelles char das Trennzeichen oder Ende des Strings ist
        if (string[i] == splitChar || string[i] == '\0')
        {
            int currentPartLength = i - iMerker;

            if (partsAnzahl >= maxParts)
            {
                printf("Maximale Parts erreicht!\n");
                break;
            }
            else
            {
                // Überprüfe die maximale Länge des Teilstrings, falls er nicht leer ist
                if (currentPartLength > maxLength)
                {
                    printf("Teilstring zu gross! Abbruch.\n");
                    return partsAnzahl;
                }
                for (int j = 0; j < currentPartLength; j++)
                {
                    parts[partsAnzahl][j] = string[iMerker + j];
                }
                //Null-Terminierung
                parts[partsAnzahl][currentPartLength] = '\0';
                //Neuer Start wert für nächsten teilstring
                iMerker = i + 1;
                partsAnzahl++;
            }
        }
    }
    return partsAnzahl;
}








int split_ignore_empty(char *string ,char splitChar, char **parts, int maxParts, int maxLength)
{
    int iMerker = 0;
    int partsAnzahl = 0;
    int currentPartLength = 0;
    //size_t stringLen = strlen(string);
    //size_t stringLen = sizeof(string)+1;

    // Springe über führende Trennzeichen
    while (string[iMerker] != '\0' && string[iMerker] == splitChar)
    {
        iMerker++;
    }

    for (int i = iMerker; string[i+1] != '\0'; i++)
    {
        // Prüfe ob aktuelles char das Trennzeichen oder das Ende des Strings ist
        if (string[i] == splitChar || string[i] == '\0')
        //if (string[i] == splitChar)
        {
            currentPartLength = i - iMerker;

            // Ignoriere den Teilstring, wenn seine Länge 0 ist (aufeinanderfolgende splitChar)
            if (currentPartLength > 0)
            {


                if (currentPartLength > maxLength)
                {
                    printf("Teilstring zu gross! Abbruch.\n");
                    return partsAnzahl;
                }

                // Kopiere den Teilstring
                for (int j = 0; j < currentPartLength; j++)
                {
                    parts[partsAnzahl][j] = string[iMerker + j];
                }
                parts[partsAnzahl][currentPartLength] = '\0';
                partsAnzahl++;
                if (partsAnzahl >= maxParts)
                {
                    printf("Maximale Parts erreicht! Der Rest des Strings wird ignoriert.\n");
                    return partsAnzahl;
                }
            }

            // Neuer Startwert: Springe über alle weiteren aufeinanderfolgenden Trennzeichen
            iMerker = i + 1;
            while (string[iMerker] != '\0' && string[iMerker] == splitChar)
            {
                iMerker++;
            }

            // Setze i auf iMerker-1, um die Schleife an der korrekten Stelle fortzusetzen
            i = iMerker - 1;

        }
    }
    currentPartLength++;
    // Kopiere den letzten Teilstring
    for (int j = 0; j < currentPartLength; j++)
    {
        parts[partsAnzahl][j] = string[iMerker + j];
    }
    parts[partsAnzahl][currentPartLength] = '\0';
    partsAnzahl++;
    return partsAnzahl;
}