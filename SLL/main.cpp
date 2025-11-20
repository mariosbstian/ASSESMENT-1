#include "SLLInventory.h"

int main() {
    List L;
    createList(L);

    Product prod1 = {"Pulpen", "A001", 20, 2500.0, 0.0};
    Product prod2 = {"BukuTulis", "A002", 15, 5000.0, 10.0};
    Product prod3 = {"Penghapus", "A003", 30, 1580.0, 0.0};

    address P1 = allocate(prod1.Nama, prod1.SKU, prod1.Jumlah, prod1.HargaSatuan, prod1.DiskonPersen);
    address P2 = allocate(prod2.Nama, prod2.SKU, prod2.Jumlah, prod2.HargaSatuan, prod2.DiskonPersen);
    address P3 = allocate(prod3.Nama, prod3.SKU, prod3.Jumlah, prod3.HargaSatuan, prod3.DiskonPersen);

    insertLast(L, P1);
    insertLast(L, P2);
    insertLast(L, P3);

    cout << "Daftar produk yang tersimpan:\n";
    viewList(L);

    cout << "\nPencarian berdasarkan rentang harga akhir (2000 - 7000):\n";
    searchByFinalPriceRange(L, 2000.0, 7000.0);

    cout << "\nMelakukan update pada elemen kedua dalam list:\n";

    Product newProd = {"Stabilo", "A010", 40, 9000, 5.0};
    updateAtPosition(L, 1, newProd);

    viewList(L);

    cout << "\nProduk dengan harga akhir tertinggi:\n";
    MAXHargaAkhir(L);

    return 0;
}
