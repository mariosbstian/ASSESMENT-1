#include <iostream>
#include "StackMahasiswa.h"
using namespace std;

int main() {
    StackMahasiswa S;
    createStack(S);

    cout << "Kapasitas stack: " << MAX_STACK << endl;

    Mahasiswa a = {"Budi", "2211001", 80, 85, 90};
    Mahasiswa b = {"Sari", "2211002", 75, 88, 92};
    Mahasiswa c = {"Agus", "2211003", 90, 80, 87};

    push(S, a);
    push(S, b);
    push(S, c);

    view(S);

    cout << "\nPop 1 mahasiswa...\n";
    pop(S);

    view(S);

    cout << "\nCari nilai akhir 80 - 90:\n";
    searchnilaiakhir(S, 80, 90);

    cout << "\nMahasiswa nilai akhir tertinggi:\n";
    maxNilaiAkhir(S);

    return 0;
}