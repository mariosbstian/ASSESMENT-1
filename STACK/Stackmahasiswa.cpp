#include "StackMahasiswa.h"

bool isEmpty(StackMahasiswa S) {
    return S.top == -1;
}

bool isFull(StackMahasiswa S) {
    return S.top == MAX_STACK - 1;
}

void createStack(StackMahasiswa& S) {
    S.top = -1;
}

void push(StackMahasiswa& S, Mahasiswa mhs) {
    if (isFull(S)) {
        cout << "Stack penuh!\n";
        return;
    }
    S.data[++S.top] = mhs;
}

Mahasiswa pop(StackMahasiswa& S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!\n";
        return {};
    }
    return S.data[S.top--];
}

void view(StackMahasiswa S) {
    if (isEmpty(S)) {
        cout << "Stack kosong.\n";
        return;
    }

    cout << "\n=== Data Mahasiswa (Dari Top ke Bottom) ===\n";
    for (int i = S.top; i >= 0; i--) {
        cout << i+1 << ". " << S.data[i].nama << " | " << S.data[i].nim
             << " | Tugas:" << S.data[i].nilaiTugas
             << " | UTS:" << S.data[i].nilaiUTS
             << " | UAS:" << S.data[i].nilaiUAS << endl;
    }
}

void searchnilaiakhir(StackMahasiswa S, float minA, float maxA) {
    cout << "\n=== Mahasiswa dengan Nilai Akhir di rentang " 
         << minA << " - " << maxA << " ===\n";

    bool found = false;

    for (int i = S.top; i >= 0; i--) {
        float akhir = S.data[i].nilaiTugas * 0.2f +
                      S.data[i].nilaiUTS * 0.4f +
                      S.data[i].nilaiUAS * 0.4f;

        if (akhir >= minA && akhir <= maxA) {
            found = true;
            cout << S.data[i].nama << " (" << akhir << ")\n";
        }
    }

    if (!found)
        cout << "Tidak ada data.\n";
}

void maxNilaiAkhir(StackMahasiswa S) {
    if (isEmpty(S)) {
        cout << "Stack kosong.\n";
        return;
    }

    int idxMax = 0;
    float maxAkhir = -1;

    for (int i = 0; i <= S.top; i++) {
        float akhir = S.data[i].nilaiTugas * 0.2f +
                      S.data[i].nilaiUTS * 0.4f +
                      S.data[i].nilaiUAS * 0.4f;

        if (akhir > maxAkhir) {
            maxAkhir = akhir;
            idxMax = i;
        }
    }

    cout << "\nMahasiswa nilai tertinggi: " << S.data[idxMax].nama 
         << " (" << maxAkhir << ")\n";
}