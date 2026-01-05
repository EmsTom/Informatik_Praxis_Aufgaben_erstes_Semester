#include <stdio.h>
#include "achtdamen.h"

#define N 8
int brett[N];
int loesungen = 0;

void ausgabe(void) {
    printf("Loesung %d:\n", loesungen);
    for (int zeile = 0; zeile < N; zeile++)
    {
        for (int spalte = 0; spalte < N; spalte++)
        {
            printf(brett[spalte] == zeile ? "D " : ". ");
        }
        printf("\n");
    }
    printf("\n");
}

int bedroht(int spalte)
{
    int zeile = brett[spalte];
    for (int j = 0; j < spalte; j++)
    {
        int z = brett[j];
        // gleiche Zeile?
        if (z == zeile) return 1;
        // gleiche Diagonale?
        // Hauptdiagonale: (zeile - spalte) == (z - j)
        // Nebendiagonale: (zeile + spalte) == (z + j)
        if ((zeile - spalte) == (z - j)) return 1;
        if ((zeile + spalte) == (z + j)) return 1;
    }
    return 0;
}

void setze(int spalte)
{
    if (spalte == N)
    {
        loesungen++;
        ausgabe();
        return;
    }
    for (int zeile = 0; zeile < N; zeile++)
    {
        brett[spalte] = zeile;
        if (!bedroht(spalte)) {
            setze(spalte + 1);
        }
    }
}