#include "SLLInventory.h"
#include <iostream>
using namespace std;

bool isEmpty(List List) {
    return (List.first == NULL);
}

void createList(List &List) {
    List.first = NULL;
}

address allocate(string nama, string sku, int jumlah, float hargaSatuan, float DiskonPersen) {
    address nodeBaru = new node;
    nodeBaru->info.Nama = nama;
    nodeBaru->info.SKU = sku;
    nodeBaru->info.Jumlah = jumlah;
    nodeBaru->info.HargaSatuan = hargaSatuan;
    nodeBaru->info.DiskonPersen = DiskonPersen;
    nodeBaru->next = NULL;
    return nodeBaru;
}

void deallocate(address &node) {
    node->next = NULL;
    delete node;
}

void insertFirst(List &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(List &List, address nodeBaru, address Prev) {
    if (Prev != NULL) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak ditemukan.\n";
    }
}

void insertLast(List &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address last = List.first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = nodeBaru;
    }
}

void deleteFirst(List &List, address &nodeHapus) {
    if (!isEmpty(List)) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = NULL;
    } else {
        nodeHapus = NULL;
        cout << "Tidak ada data untuk dihapus.\n";
    }
}

void deleteAfter(List &List, address &nodeHapus, address Prev) {
    if (Prev != NULL && Prev->next != NULL) {
        nodeHapus = Prev->next;
        Prev->next = nodeHapus->next;
        nodeHapus->next = NULL;
    } else {
        nodeHapus = NULL;
        cout << "Penghapusan gagal: node sebelumnya tidak valid.\n";
    }
}

void deleteLast(List &List, address &nodeHapus) {
    if (isEmpty(List)) {
        nodeHapus = NULL;
        cout << "List kosong, tidak ada elemen yang bisa dihapus.\n";
        return;
    }

    if (List.first->next == NULL) {
        nodeHapus = List.first;
        List.first = NULL;
    } else {
        address curr = List.first;
        address prev = NULL;

        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }

        nodeHapus = curr;
        prev->next = NULL;
    }
}

void updateAtPosition(List &List, int posisi, dataProduct dataBaru) {
    if (isEmpty(List)) {
        cout << "List kosong.\n";
        return;
    }

    address curr = List.first;
    int index = 0;

    while (curr != NULL && index < posisi) {
        curr = curr->next;
        index++;
    }

    if (curr != NULL) {
        curr->info = dataBaru;
    } else {
        cout << "Posisi yang diminta tidak tersedia.\n";
    }
}

void viewList(List List) {
    if (isEmpty(List)) {
        cout << "List masih kosong.\n";
        return;
    }

    address curr = List.first;
    int index = 1;

    while (curr != NULL) {
        cout << "Data produk #" << index << "\n";
        cout << "Nama          : " << curr->info.Nama << "\n";
        cout << "SKU           : " << curr->info.SKU << "\n";
        cout << "Jumlah        : " << curr->info.Jumlah << "\n";
        cout << "Harga Satuan  : " << curr->info.HargaSatuan << "\n";
        cout << "Diskon        : " << curr->info.DiskonPersen << "%\n";
        cout << "---------------------------\n";

        curr = curr->next;
        index++;
    }
}

void searchByFinalPriceRange(List List, float minPrice, float maxPrice) {
    if (isEmpty(List)) {
        cout << "List kosong.\n";
        return;
    }

    address curr = List.first;
    bool ditemukan = false;

    while (curr != NULL) {
        float finalPrice = curr->info.HargaSatuan * (1 - curr->info.DiskonPersen / 100);

        if (finalPrice >= minPrice && finalPrice <= maxPrice) {
            cout << "Produk sesuai kriteria:\n";
            cout << "Nama: " << curr->info.Nama << "\n";
            cout << "SKU: " << curr->info.SKU << "\n";
            cout << "Jumlah: " << curr->info.Jumlah << "\n";
            cout << "Harga Akhir: " << finalPrice << "\n";
            cout << "---------------------------\n";
            ditemukan = true;
        }
        curr = curr->next;
    }

    if (!ditemukan) {
        cout << "Tidak ditemukan produk dalam rentang harga tersebut.\n";
    }
}

void MAXHargaAkhir(List List) {
    if (isEmpty(List)) {
        cout << "List kosong.\n";
        return;
    }

    address curr = List.first;
    address maxNode = curr;

    float maxPrice = curr->info.HargaSatuan * (1 - curr->info.DiskonPersen / 100);
    curr = curr->next;

    while (curr != NULL) {
        float finalPrice = curr->info.HargaSatuan * (1 - curr->info.DiskonPersen / 100);

        if (finalPrice > maxPrice) {
            maxPrice = finalPrice;
            maxNode = curr;
        }

        curr = curr->next;
    }

    cout << "Produk dengan harga akhir tertinggi:\n";
    cout << "Nama: " << maxNode->info.Nama << "\n";
    cout << "SKU: " << maxNode->info.SKU << "\n";
    cout << "Jumlah: " << maxNode->info.Jumlah << "\n";
    cout << "Harga Akhir: " << maxPrice << "\n";
}
