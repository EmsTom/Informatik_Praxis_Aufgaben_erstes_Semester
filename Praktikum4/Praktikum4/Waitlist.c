#include "Waitlist.h"

#include <stdio.h>
#include <stdlib.h>
// Erzeugen einer leeren Warteschlange. Sie besteht
//nur aus einem künstlichen Element, das immer auf das erste Element der eigentlichen Warteschlange zeigt.
struct Knoten * qinit(void)
{
    struct Knoten * q = (struct Knoten *)malloc(sizeof(struct Knoten));
    if (!q)
    {
        printf("Speicher konnte nicht reserviert werden!\n");
        return 0;
    }

    q->key = 0;
    q->next = NULL;
}
//Findet den letzten Teil der Schlange (tail)
static struct Knoten *find_tail(struct Knoten *schlange)
{
    struct Knoten *p = schlange;
    while (p->next != NULL) p = p->next;
    return p;
}
// Anfügen eines Elementes an die Warteschlange
void enqueue(struct Knoten * schlange, int element)
{
    if (!schlange)
        return;
    struct Knoten * neu = (struct Knoten *)malloc(sizeof(struct Knoten));
    if (!neu)
    {
        printf("Speicher konnte nicht reserviert werden!\n");
        return;
    }
    neu->key = element;
    neu->next = NULL;

    struct Knoten *tail = find_tail(schlange);
    tail->next = neu;
}
//Entfernen des ersten Elementes aus der Warteschlange
//-1 wenn schlange leer
int dequeue(struct Knoten * schlange)
{
    if (!schlange)
        return -1;
    struct Knoten *first = schlange->next;
    if (!first)
        return -1;
    int value = first->key;
    printf("\nDer Eintrag mit dem Wert %d wurde aus der Warteschlange entfernt.\n", value);
    //erstes element aus der verkettung entfernen
    schlange->next = first->next;
    free(first);
    return value;
}
//Rückgabe von 1, falls die Schlange leer ist, 0 sonst.
int isempty(struct Knoten * schlange)
{
    if (!schlange)
        return 1;
    return(schlange->next == NULL) ? 1 : 0;

}
// Ausgabe der in der Schlange gespeicherten Elemente.
void printQueue (struct Knoten * schlange)
{
    isempty(schlange);

    struct Knoten *p = schlange->next;
    printf("\n");
    while (p != NULL)
    {
        printf("%d;", p->key);
        p = p->next;
    }
    printf("\n");
}
//Gibt Speicher frei
void destroyQueue(struct Knoten * schlange)
{
    if (!schlange)
        return;
    struct Knoten *p = schlange->next;
    while (p)
    {
        struct Knoten *next = p->next;
        free(p);
        p = next;
    }
    free(schlange);
}

//
// Created by tvolm on 01.12.2025.
//