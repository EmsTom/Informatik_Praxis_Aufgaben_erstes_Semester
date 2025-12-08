#include <stdio.h>
#include "Waitlist.h"
#define EOL '\n'

int main(void)
{
    struct Knoten * q = qinit();
    if (!q)
        return 1;
    int choice;

    do
    {
        printf("\nMenue zur Warteschlangenverwaltung:\n");
        printf("1. Anfuegen eines Elementes\n");
        printf("2. Loeschen und Ausgeben des ersten Elementes\n");
        printf("3. Ausgeben der Warteschlange\n");
        printf("4. Beenden des Programms\n");
        printf("Bitte geben Sie die Ziffer der gewuenschten Funktion ein: ");


        if (scanf("%d", &choice) != 1)
        {
            int c;
            while (c = getchar() != EOF && c != EOL);
            printf("Ungültige eingabe!\n");
            continue;
        }
        switch (choice)
        {
            case 1:
                printf("Geben sie das anzufuegende Element ein: ");
                int x;
                if (scanf("%d", &x) == 1)
                    enqueue(q,x);
                else
                {
                    printf("Ungültige eingabe!\n");
                    while (x = getchar() != EOF && x != EOL);
                }
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                printQueue(q);
                break;
            case 4:
                destroyQueue(q);
                break;
            default:
                break;
        }
    } while (choice != 4);




    printf("Hello, World!\n");
    return 0;
}