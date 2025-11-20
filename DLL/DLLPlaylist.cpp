#include "DLLplaylist.h"
#include <iomanip>
#include <cmath>

bool isEmpty(linkedlist L) {
    return L.head == Nil;
}

void createList(linkedlist &L) {
    L.head = Nil;
    L.tail = Nil;
}

address allocate(song S) {
    address P = new node;
    P->info = S;
    P->prev = Nil;
    P->next = Nil;
    return P;
}

void deallocate(address &P) {
    P->prev = Nil;
    P->next = Nil;
    delete P;
    P = Nil;
}

void insertFirst(linkedlist &L, address nodeBaru) {
    if (isEmpty(L)) {
        L.head = nodeBaru;
        L.tail = nodeBaru;
    } else {
        nodeBaru->next = L.head;
        L.head->prev = nodeBaru;
        L.head = nodeBaru;
    }
}

void insertLast(linkedlist &L, address nodeBaru) {
    if (isEmpty(L)) {
        L.head = nodeBaru;
        L.tail = nodeBaru;
    } else {
        nodeBaru->prev = L.tail;
        L.tail->next = nodeBaru;
        L.tail = nodeBaru;
    }
}

void insertAfter(linkedlist &L, address Q, address nodeBaru) {
    if (Q == Nil) return;
    if (Q == L.tail) {
        insertLast(L, nodeBaru);
    } else {
        nodeBaru->next = Q->next;
        nodeBaru->prev = Q;
        Q->next->prev = nodeBaru;
        Q->next = nodeBaru;
    }
}

void insertBefore(linkedlist &L, address Q, address nodeBaru) {
    if (Q == Nil) return;
    if (Q == L.head) {
        insertFirst(L, nodeBaru);
    } else {
        nodeBaru->prev = Q->prev;
        nodeBaru->next = Q;
        Q->prev->next = nodeBaru;
        Q->prev = nodeBaru;
    }
}

void deleteFirst(linkedlist &L, song &S) {
    if (isEmpty(L)) {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address p = L.head;
    S = p->info;
    if (L.head == L.tail) {
        L.head = Nil;
        L.tail = Nil;
    } else {
        L.head = p->next;
        L.head->prev = Nil;
    }
    cout << "Node " << S.Title << " berhasil dihapus dari posisi pertama." << endl;
    deallocate(p);
}

void deleteLast(linkedlist &L, song &S) {
    if (isEmpty(L)) {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address p = L.tail;
    S = p->info;
    if (L.head == L.tail) {
        L.head = Nil;
        L.tail = Nil;
    } else {
        L.tail = p->prev;
        L.tail->next = Nil;
    }
    cout << "Node " << S.Title << " berhasil dihapus dari posisi terakhir." << endl;
    deallocate(p);
}

void deleteAfter(linkedlist &L, address Q, song &S) {
    if (isEmpty(L)) {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if (Q == Nil || Q->next == Nil) {
        cout << "Node sebelumnya tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    address p = Q->next;
    S = p->info;
    if (p == L.tail) {
        deleteLast(L, S);
        return;
    }
    Q->next = p->next;
    p->next->prev = Q;
    cout << "Node " << S.Title << " berhasil dihapus setelah node " << Q->info.Title << "." << endl;
    deallocate(p);
}

void deleteBefore(linkedlist &L, address Q, song &S) {
    if (isEmpty(L)) {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if (Q == Nil || Q->prev == Nil) {
        cout << "Node setelahnya tidak valid atau tidak ada node sebelumnya!" << endl;
        return;
    }
    address p = Q->prev;
    S = p->info;
    if (p == L.head) {
        deleteFirst(L, S);
        return;
    }
    p->prev->next = Q;
    Q->prev = p->prev;
    cout << "Node " << S.Title << " berhasil dihapus sebelum node " << Q->info.Title << "." << endl;
    deallocate(p);
}

void deleteNode(linkedlist &L, address target) {
    if (isEmpty(L) || target == Nil) {
        cout << "Target tidak valid atau list kosong!" << endl;
        return;
    }
    if (target == L.head) {
        song tmp;
        deleteFirst(L, tmp);
    } else if (target == L.tail) {
        song tmp;
        deleteLast(L, tmp);
    } else {
        address Ls = target->prev;
        address Rs = target->next;
        Ls->next = Rs;
        Rs->prev = Ls;
        cout << "Node " << target->info.Title << " berhasil dihapus dari tengah list." << endl;
        deallocate(target);
    }
}

void updateAtPosition(linkedlist &L, int posisi, song newData) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }
    if (posisi <= 0) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }
    address p = getNodeAtPosition(L, posisi);
    if (p == Nil) {
        cout << "Posisi " << posisi << " tidak ditemukan!" << endl;
        return;
    }
    p->info = newData;
    cout << "Data pada posisi ke-" << posisi << " berhasil diupdate." << endl;
}

void updateBefore(linkedlist &L, address nodeNext) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }
    if (nodeNext == Nil || nodeNext->prev == Nil) {
        cout << "Node sebelumnya (prev) tidak valid!" << endl;
        return;
    }
    address p = nodeNext->prev;
    cout << "Masukkan update data node sebelum node " << nodeNext->info.Title << " : " << endl;
    cout << "Title : ";
    getline(cin, p->info.Title);
    cout << "Artist : ";
    getline(cin, p->info.Artist);
    cout << "DurationSec : ";
    cin >> p->info.DurationSec;
    cout << "PlayCount : ";
    cin >> p->info.PlayCount;
    cout << "Rating : ";
    cin >> p->info.Rating;
    cin.ignore();
    cout << "Data Berhasil Diupdate!" << endl;
}

float popularityScore(const song &s) {
    return 0.8f * float(s.PlayCount) + 20.0f * s.Rating;
}

void viewList(const linkedlist &L) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }
    address p = L.head;
    int idx = 1;
    cout << left << setw(4) << "No" << setw(30) << "Title" << setw(20) << "Artist" << setw(12) << "Duration" << setw(12) << "PlayCnt" << setw(8) << "Rating" << setw(12) << "PopScore" << endl;
    while (p != Nil) {
        cout << left << setw(4) << idx
             << setw(30) << p->info.Title
             << setw(20) << p->info.Artist
             << setw(12) << p->info.DurationSec
             << setw(12) << p->info.PlayCount
             << setw(8) << fixed << setprecision(1) << p->info.Rating
             << setw(12) << fixed << setprecision(2) << popularityScore(p->info)
             << endl;
        p = p->next;
        idx++;
    }
}

void searchByPopularityRange(const linkedlist &L, float minScore, float maxScore) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }
    address p = L.head;
    int idx = 1;
    bool found = false;
    while (p != Nil) {
        float score = popularityScore(p->info);
        if (score >= minScore && score <= maxScore) {
            if (!found) {
                cout << "Lagu dengan PopularityScore dalam rentang [" << minScore << "," << maxScore << "] :" << endl;
                cout << left << setw(4) << "No" << setw(30) << "Title" << setw(20) << "Artist" << setw(12) << "PopScore" << endl;
            }
            cout << left << setw(4) << idx << setw(30) << p->info.Title << setw(20) << p->info.Artist << setw(12) << fixed << setprecision(2) << score << endl;
            found = true;
        }
        p = p->next;
        idx++;
    }
    if (!found) {
        cout << "Tidak ditemukan lagu dengan PopularityScore dalam rentang tersebut." << endl;
    }
}

address getNodeAtPosition(const linkedlist &L, int posisi) {
    if (isEmpty(L) || posisi <= 0) return Nil;
    address p = L.head;
    int idx = 1;
    while (p != Nil) {
        if (idx == posisi) return p;
        p = p->next;
        idx++;
    }
    return Nil;
}