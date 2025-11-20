#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

bool isEmpty(StackMahasiswa S) {
    return S.top == -1;
}

bool isFull(StackMahasiswa S) {
    return S.top == MAX_STACK - 1;
}

void initStack(StackMahasiswa &S) {
    S.top = -1;
}

void pushData(StackMahasiswa &S, Mahasiswa m) {
    if (!isFull(S)) {
        S.top++;
        S.data[S.top] = m;
    } else {
        cout << "Stack sudah penuh, data tidak bisa ditambahkan." << endl;
    }
}

Mahasiswa popData(StackMahasiswa &S) {
    Mahasiswa temp;
    if (!isEmpty(S)) {
        temp = S.data[S.top];
        S.top--;
        return temp;
    } else {
        cout << "Stack masih kosong, tidak ada data untuk dihapus." << endl;
        return temp;
    }
}

Mahasiswa editData(StackMahasiswa S) {
    Mahasiswa updated;
    int posisi;

    if (isEmpty(S)) {
        cout << "Stack masih kosong, tidak ada data untuk diperbarui." << endl;
        return updated;
    }

    cout << "Masukkan posisi yang ingin diubah (1 - " << S.top + 1 << "): ";
    cin >> posisi;

    if (posisi < 1 || posisi > S.top + 1) {
        cout << "Posisi tidak valid!" << endl;
        return updated;
    }

    int index = S.top - posisi + 1;

    cin.ignore();
    cout << "Nama baru      : ";
    getline(cin, updated.nama);

    cout << "NIM baru       : ";
    getline(cin, updated.nim);

    cout << "Nilai Tugas    : ";
    cin >> updated.nilaiTugas;

    cout << "Nilai UTS      : ";
    cin >> updated.nilaiUTS;

    cout << "Nilai UAS      : ";
    cin >> updated.nilaiUAS;

    S.data[index] = updated;

    return updated;
}

void tampil(StackMahasiswa S) {
    if (isEmpty(S)) {
        cout << "Stack masih kosong!" << endl;
        return;
    }

    cout << "\n=== Daftar Mahasiswa dalam Stack ===\n";
    cout << "-------------------------------------\n";

    for (int i = S.top; i >= 0; i--) {
        cout << "Posisi " << (S.top - i + 1) << ":\n";
        cout << "  Nama         : " << S.data[i].nama << endl;
        cout << "  NIM          : " << S.data[i].nim << endl;
        cout << "  Nilai Tugas  : " << S.data[i].nilaiTugas << endl;
        cout << "  Nilai UTS    : " << S.data[i].nilaiUTS << endl;
        cout << "  Nilai UAS    : " << S.data[i].nilaiUAS << endl;

        float akhir = S.data[i].nilaiTugas * 0.2 +
                       S.data[i].nilaiUTS * 0.4 +
                       S.data[i].nilaiUAS * 0.4;

        cout << "  Nilai Akhir  : " << akhir << endl;
        cout << "-------------------------------------\n";
    }
}

void cariNilaiAkhir(StackMahasiswa S, float batasMin, float batasMax) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
        return;
    }

    bool ketemu = false;

    cout << "\n=== Pencarian Nilai Akhir (" << batasMin << " - " << batasMax << ") ===\n";
    cout << "-------------------------------------\n";

    for (int i = S.top; i >= 0; i--) {
        float finalScore = S.data[i].nilaiTugas * 0.2 +
                           S.data[i].nilaiUTS * 0.4 +
                           S.data[i].nilaiUAS * 0.4;

        if (finalScore >= batasMin && finalScore <= batasMax) {
            ketemu = true;
            cout << "Nama         : " << S.data[i].nama << endl;
            cout << "NIM          : " << S.data[i].nim << endl;
            cout << "Nilai Akhir  : " << finalScore << endl;
            cout << "Posisi       : " << (S.top - i + 1) << endl;
            cout << "-------------------------------------\n";
        }
    }

    if (!ketemu) {
        cout << "Tidak ada mahasiswa dengan nilai akhir di rentang tersebut.\n";
    }
}
