//
// Created by tvolm on 01.12.2025.
//

#ifndef PRAKTIKUM4_WAITLIST_H
#define PRAKTIKUM4_WAITLIST_H
struct Knoten
{
    int key;
    struct Knoten *next;
};
struct Knoten * qinit();
void enqueue(struct Knoten * schlange, int element);
int dequeue(struct Knoten * schlange);
int isempty(struct Knoten * schlange);
void printQueue (struct Knoten * schlange);
void destroyQueue(struct Knoten * schlange);
int queueCounter(struct Knoten * schlange);

#endif //PRAKTIKUM4_WAITLIST_H