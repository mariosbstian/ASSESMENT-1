#include "DLLPlaylist.h"

int main() {
    linkedlist L;
    createList(L);

    song s1;
    s1.Title = "Senja di Kota";
    s1.Artist = "Nona Band";
    s1.DurationSec = 210;
    s1.PlayCount = 150;
    s1.Rating = 4.2f;

    song s2;
    s2.Title = "Langkahmu";
    s2.Artist = "Delta";
    s2.DurationSec = 185;
    s2.PlayCount = 320;
    s2.Rating = 4.8f;

    song s3;
    s3.Title = "Hujan Minggu";
    s3.Artist = "Arka";
    s3.DurationSec = 240;
    s3.PlayCount = 90;
    s3.Rating = 3.9f;

    insertLast(L, allocate(s1));
    insertLast(L, allocate(s2));
    insertLast(L, allocate(s3));

    cout << " Isi List Setelah Insert " << endl;
    viewList(L);
    cout << endl;

    song tmp;
    deleteLast(L, tmp);
    cout << endl;

    cout << " Isi List Setelah deleteLast " << endl;
    viewList(L);
    cout << endl;

    song newSong;
    newSong.Title = "Pelita";
    newSong.Artist = "Luna";
    newSong.DurationSec = 200;
    newSong.PlayCount = 260;
    newSong.Rating = 4.5f;

    updateAtPosition(L, 2, newSong);
    cout << endl;

    cout << " Isi List Setelah Update " << endl;
    viewList(L);
    cout << endl;

    address nodePos2 = getNodeAtPosition(L, 2);
    song beforeSong;
    beforeSong.Title = "Senandung";
    beforeSong.Artist = "Mira";
    beforeSong.DurationSec = 175;
    beforeSong.PlayCount = 120;
    beforeSong.Rating = 4.0f;

    insertBefore(L, nodePos2, allocate(beforeSong));
    cout << " Isi List Setelah insertBefore pada posisi 2 " << endl;
    viewList(L);
    cout << endl;

    updateBefore(L, nodePos2);
    cout << endl;

    cout << " Isi List Setelah updateBefore pada node posisi 2 " << endl;
    viewList(L);
    cout << endl;

    address nodePos3 = getNodeAtPosition(L, 3);
    deleteBefore(L, nodePos3, tmp);
    cout << endl;

    cout << " Isi List Setelah deleteBefore pada node posisi 3 " << endl;
    viewList(L);
    cout << endl;

    cout << " Hasil Searching PopularityScore " << endl;
    searchByPopularityRange(L, 150.0f, 300.0f);
    cout << endl;

    return 0;
}