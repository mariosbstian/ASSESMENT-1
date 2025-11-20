#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float nilaiTugas;
    float nilaiUTS;
    float nilaiUAS;
};

const int MAX_STACK = 6;

struct StackMahasiswa {
    Mahasiswa data[MAX_STACK];
    int top;
};

bool isEmpty(StackMahasiswa S);
bool isFull(StackMahasiswa S);
void createStack(StackMahasiswa& S);
void push(StackMahasiswa& S, Mahasiswa mhs);
Mahasiswa pop(StackMahasiswa& S);
Mahasiswa update(StackMahasiswa S);
void view(StackMahasiswa S);
void searchnilaiakhir(StackMahasiswa S, float minNilaiAkhir, float maxNilaiAkhir);
void maxNilaiAkhir(StackMahasiswa S);

#endif