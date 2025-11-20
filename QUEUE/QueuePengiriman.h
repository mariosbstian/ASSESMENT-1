#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H

#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string KodeResi;       
    string NamaPengirirm;  
    int BeratBarang;       
    string Tujuan;         
} Paket;

const int MAX = 5; 

// Struktur antrian untuk mengelola daftar paket yang akan dikirim
typedef struct {
    Paket dataPaket[MAX];  // Array penyimpanan paket
    int Head;              // Penanda elemen terdepan
    int Tail;              // Penanda elemen terakhir
} QueueEkspedisi;

void createQueue(QueueEkspedisi &Q);

bool isEmpty(QueueEkspedisi Q);

bool isFull(QueueEkspedisi Q);

void enQueue(QueueEkspedisi &Q, Paket data);

void deQueue(QueueEkspedisi &Q);

void viewQueue(QueueEkspedisi Q);

int TotalBiayaPengiriman(QueueEkspedisi Q);

#endif