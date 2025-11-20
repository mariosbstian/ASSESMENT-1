#include "QueuePengiriman.h"
#include <iostream>
using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);
    int pilihan;

    cout << "======== APLIKASI ANTRIAN PENGIRIMAN PAKET ========\n\n";

    while (true) {
        cout << "Menu Pilihan:\n";
        cout << "1. Tambah Data Paket\n";
        cout << "2. Keluarkan Paket dari Antrian\n";
        cout << "3. Lihat Seluruh Antrian Paket\n";
        cout << "4. Hitung Total Biaya Pengiriman\n";
        cout << "5. Keluar Program\n";
        cout << "Masukkan pilihan Anda : ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {

            case 1: {
                if (isFull(Q)) {
                    cout << "Antrian sudah mencapai kapasitas maksimal. Tidak dapat menambahkan paket baru.\n\n";
                } else {
                    Paket paketBaru;

                    cout << "--- Form Input Paket ---\n";
                    cout << "Kode Resi        : ";
                    cin >> paketBaru.KodeResi;
                    cout << "Nama Pengirim    : ";
                    cin >> paketBaru.NamaPengirirm;
                    cout << "Berat Barang (kg): ";
                    cin >> paketBaru.BeratBarang;
                    cout << "Tujuan Pengiriman: ";
                    cin >> paketBaru.Tujuan;
                    cout << endl;

                    enQueue(Q, paketBaru);
                    cout << endl;
                }
                break;
            }

            case 2: {
                deQueue(Q);
                cout << endl;
                break;
            }

            case 3: {
                viewQueue(Q);
                break;
            }

            case 4: {
                int total = TotalBiayaPengiriman(Q);

                if (!isEmpty(Q)) {
                    cout << "\n========== RINCIAN TOTAL BIAYA ==========\n";
                    cout << "Total keseluruhan biaya pengiriman: Rp " << total << endl;
                    cout << "=========================================\n\n";
                }
                break;
            }

            case 5: {
                cout << "Program dihentikan. Terima kasih telah menggunakan layanan ini!\n";
                return 0;
            }

            default:
                cout << "Pilihan tidak tersedia. Silakan masukkan opsi yang benar.\n\n";
        }
    }

    return 0;
}