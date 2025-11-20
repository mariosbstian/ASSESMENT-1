#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H

#include <iostream>
using namespace std;

#define Nil NULL

struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating;
};

typedef Song song;

typedef struct node *address;

struct node {
    song info;
    address prev;
    address next;
};

struct linkedlist {
    address head;
    address tail;
};

bool isEmpty(linkedlist L);
void createList(linkedlist &L);
address allocate(song S);
void deallocate(address &P);

void insertFirst(linkedlist &L, address nodeBaru);
void insertLast(linkedlist &L, address nodeBaru);
void insertAfter(linkedlist &L, address Q, address nodeBaru);
void insertBefore(linkedlist &L, address Q, address nodeBaru);

void deleteFirst(linkedlist &L, song &S);
void deleteLast(linkedlist &L, song &S);
void deleteAfter(linkedlist &L, address Q, song &S);
void deleteBefore(linkedlist &L, address Q, song &S);
void deleteNode(linkedlist &L, address target);

void updateAtPosition(linkedlist &L, int posisi, song newData);
void updateBefore(linkedlist &L, address nodeNext);

void viewList(const linkedlist &L);
void searchByPopularityRange(const linkedlist &L, float minScore, float maxScore);

float popularityScore(const song &s);

address getNodeAtPosition(const linkedlist &L, int posisi);

#endif