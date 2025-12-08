#include <stdio.h>

//float USDollarKurs = 1.2;
//float GBPKurs = 0.884; //887754 um auf den gleichen Wert wie in der Aufgabenstellung zu kommen
int Ausgangswaehrung = 0;
float Wechselbetrag = 0;
int wechselwaehrung = 0;
float euroToUS = 0, euroToGPB = 0, euroToJPN = 0;


int main(void)
{
    //Kursinformationen ausgeben
    printf("Wie viele US$ bekomme ich fuer 1 EURO ?");
    scanf("%f",&euroToUS);
    printf("Wie viele GBP bekomme ich fuer 1 EURO ?");
    scanf("%f",&euroToGPB);
    printf("Wie viele Japanische Yen bekomme ich fuer 1 EURO ?");
    scanf("%f",&euroToJPN);

    //printf("Fuer 1 EURO bekommst du %f US$ und %f GBP\n", 1 * USDollarKurs, 1 * GBPKurs);


    //Ausgangswaehrung einlesen
    printf("Was ist Ihre Ausgangswaehrung? 1=EURO, 2=US$, 3=GBP 4=Yen");
    scanf("%d", &Ausgangswaehrung);


    //Switch case um je nach eingabe verschiedenen Text auszugeben
    switch (Ausgangswaehrung)
        {
        case 1:
            printf("Welchen EURO-Betrag wollen Sie wechseln?");
            break;
        case 2:
            printf("Welchen US$-Betrag wollen Sie wechseln?");
            break;
        case 3:
            printf("Welchen GBP-Betrag wollen Sie wechseln?");
            break;
        case 4:
            printf("Welchen Japanischen Yen-Betrag wollen Sie wechseln?");
            break;
        default:
            break;
        }


    //Wechselbetrag als float Variable einlesen
    scanf("%f", &Wechselbetrag);


    //Betrag in Euro umrechnen Basiswaehrung
    switch (Ausgangswaehrung)
    {
        case 1:
            break;
        case 2:
            Wechselbetrag = Wechselbetrag / euroToUS;
            break;
        case 3:
            Wechselbetrag = Wechselbetrag / euroToGPB;
            break;
        case 4:
            Wechselbetrag = Wechselbetrag / euroToJPN;
        default:
            break;
    }


    //Ausgabe Waehrung waehlen
    printf("In welche Waehrung wollen Sie wechseln? 1=EURO, 2=US$, 3=GBP 4=Yen");
    scanf("%d", &wechselwaehrung);


    //Ausgabewaehrung berechnen und ausgeben
    switch (wechselwaehrung)
    {
        case 1:
            printf("Sie erhalten dafuer: %f EURO", Wechselbetrag);
            break;
        case 2:
            Wechselbetrag = Wechselbetrag * euroToUS;
            printf("Sie erhalten dafuer: %f US$", Wechselbetrag);
            break;
        case 3:
            Wechselbetrag = Wechselbetrag * euroToGPB;
            printf("Sie erhalten dafuer: %f GBP", Wechselbetrag);
            break;
        case 4:
            Wechselbetrag = Wechselbetrag * euroToJPN;
            printf("Sie erhalten dafuer: %f Japanische Yen", Wechselbetrag);
            break;
        default:
            break;
    }
    return 0;
}