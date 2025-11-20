#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

void cariNilaiAkhirTertinggi(StackMahasiswa S) {
    if (isEmpty(S)) {
        cout << "Stack masih kosong!" << endl;
        return;
    }

    float nilaiTertinggi = -1;
    int posisi = -1;
    Mahasiswa terbaik;

    for (int i = S.top; i >= 0; i--) {
        float hitungAkhir =
            (S.data[i].nilaiTugas * 0.20f) +
            (S.data[i].nilaiUTS   * 0.40f) +
            (S.data[i].nilaiUAS   * 0.40f);

        if (hitungAkhir > nilaiTertinggi) {
            nilaiTertinggi = hitungAkhir;
            posisi = S.top - i + 1;
            terbaik = S.data[i];
        }
    }

    cout << "\n=== Mahasiswa Dengan Nilai Akhir Tertinggi ===\n";
    cout << "Nama        : " << terbaik.nama << endl;
    cout << "NIM         : " << terbaik.nim << endl;
    cout << "Nilai Tugas : " << terbaik.nilaiTugas << endl;
    cout << "Nilai UTS   : " << terbaik.nilaiUTS << endl;
    cout << "Nilai UAS   : " << terbaik.nilaiUAS << endl;
    cout << "Nilai Akhir : " << nilaiTertinggi << endl;
    cout << "Urutan      : " << posisi << endl;
    cout << "=============================================\n";
}

int main() {
    StackMahasiswa S;
    createStack(S);

    cout << "========== DATA STACK MAHASISWA ==========\n";
    cout << "Kapasitas Maksimum : " << MAX_STACK << "\n\n";

    cout << "1. Stack berhasil dibuat.\n\n";

    cout << "2. Input data mahasiswa:\n";

    Mahasiswa a;
    a.nama = "Venti";
    a.nim = "11111";
    a.nilaiTugas = 75.7;
    a.nilaiUTS   = 82.1;
    a.nilaiUAS   = 65.5;
    push(S, a);
    cout << "   > Venti ditambahkan.\n";

    Mahasiswa b;
    b.nama = "Xiao";
    b.nim = "22222";
    b.nilaiTugas = 87.4;
    b.nilaiUTS   = 88.9;
    b.nilaiUAS   = 81.9;
    push(S, b);
    cout << "   > Xiao ditambahkan.\n";

    Mahasiswa c;
    c.nama = "Kazuha";
    c.nim = "33333";
    c.nilaiTugas = 92.3;
    c.nilaiUTS   = 88.8;
    c.nilaiUAS   = 82.4;
    push(S, c);
    cout << "   > Kazuha ditambahkan.\n";

    Mahasiswa d;
    d.nama = "Wanderer";
    d.nim = "44444";
    d.nilaiTugas = 95.5;
    d.nilaiUTS   = 85.5;
    d.nilaiUAS   = 90.5;
    push(S, d);
    cout << "   > Wanderer ditambahkan.\n";

    Mahasiswa e;
    e.nama = "Lynette";
    e.nim = "55555";
    e.nilaiTugas = 77.7;
    e.nilaiUTS   = 65.4;
    e.nilaiUAS   = 79.9;
    push(S, e);
    cout << "   > Lynette ditambahkan.\n";

    Mahasiswa f;
    f.nama = "Chasca";
    f.nim = "66666";
    f.nilaiTugas = 99.9;
    f.nilaiUTS   = 93.6;
    f.nilaiUAS   = 87.3;
    push(S, f);
    cout << "   > Chasca ditambahkan.\n\n";

    cout << "3. Isi stack saat ini:\n";
    view(S);
    cout << endl;

    cout << "4. Hapus (pop) 1 data teratas:\n";
    Mahasiswa keluar = pop(S);
    cout << "   > " << keluar.nama << " berhasil di-pop.\n\n";

    cout << "5. Isi stack setelah pop:\n";
    view(S);
    cout << endl;

    cout << "6. Update data pada posisi ke-3:\n";
    Mahasiswa ganti;
    ganti.nama = "Heizou";
    ganti.nim = "77777";
    ganti.nilaiTugas = 99.9;
    ganti.nilaiUTS   = 88.8;
    ganti.nilaiUAS   = 77.7;

    int posEdit = 3;
    int idxEdit = S.top - posEdit + 1;
    if (idxEdit >= 0 && idxEdit <= S.top) {
        S.data[idxEdit] = ganti;
        cout << "   > Data posisi " << posEdit << " berhasil diubah.\n\n";
    }

    cout << "7. Isi stack setelah update:\n";
    view(S);
    cout << endl;

    cout << "8. Cari mahasiswa dengan nilai akhir 85.5 - 95.5:\n";
    searchnilaiakhir(S, 85.5, 95.5);
    cout << endl;

    cout << "=== BAGIAN 3B ===\n";
    cariNilaiAkhirTertinggi(S);

    return 0;
}
