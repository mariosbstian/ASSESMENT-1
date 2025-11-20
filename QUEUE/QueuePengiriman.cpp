#include "QueuePengiriman.h"

void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

bool isEmpty(QueueEkspedisi Q) {
    return (Q.Head == -1 && Q.Tail == -1);
}

bool isFull(QueueEkspedisi Q) {
    return (Q.Tail == MAX - 1);
}

void enQueue(QueueEkspedisi &Q, Paket data) {
    if (isFull(Q)) {
        cout << "Antrian sudah penuh, data baru tidak dapat dimasukkan." << endl;
    } else {
        if (isEmpty(Q)) {
            Q.Head = 0;
        }
        Q.Tail++;
        Q.dataPaket[Q.Tail] = data;
        cout << "Paket berhasil dimasukkan ke dalam antrian." << endl;
    }
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Tidak ada paket dalam antrian, proses penghapusan gagal." << endl;
    } else {
        cout << "Paket dengan nomor resi " << Q.dataPaket[Q.Head].KodeResi
             << " telah diproses dan dikeluarkan dari antrian." << endl;
        
        Q.Head++;

        // Jika seluruh elemen sudah terambil
        if (Q.Head > Q.Tail) {
            Q.Head = -1;
            Q.Tail = -1;
        }
    }
}

void viewQueue(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Tidak ada paket yang sedang menunggu di antrian." << endl;
    } else {
        cout << "\n========== DAFTAR PAKET DALAM QUEUE ==========" << endl;
        cout << "No | Resi | Pengirim | Berat(kg) | Tujuan" << endl;
        cout << "==============================================" << endl;

        int nomor = 1;
        for (int i = Q.Head; i <= Q.Tail; i++) {
            cout << nomor << "  | " << Q.dataPaket[i].KodeResi << " | "
                 << Q.dataPaket[i].NamaPengirirm << " | "
                 << Q.dataPaket[i].BeratBarang << " | "
                 << Q.dataPaket[i].Tujuan << endl;
            nomor++;
        }

        cout << "==============================================\n" << endl;
    }
}

int TotalBiayaPengiriman(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Tidak ada paket, total biaya pengiriman = 0." << endl;
        return 0;
    }

    int totalBiaya = 0;
    int tarifPerKg = 8250;

    for (int i = Q.Head; i <= Q.Tail; i++) {
        totalBiaya += Q.dataPaket[i].BeratBarang * tarifPerKg;
    }

    return totalBiaya;
}