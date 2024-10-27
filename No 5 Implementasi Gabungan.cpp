#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;


struct Buku {
    string ISBN;
    string judul;
    string pengarang;
    int tahunTerbit;
};


stack<string> riwayatPeminjaman;


queue<string> antrianPeminjaman;


const int MAKS_BUKU = 100;
Buku* daftarBuku[MAKS_BUKU];
int jumlahBuku = 0;


void tambahBuku() {
    if (jumlahBuku < MAKS_BUKU) {
        Buku* bukuBaru = new Buku;
        cout << "Masukkan ISBN: ";
        cin >> bukuBaru->ISBN;
        cout << "Masukkan Judul: ";
        cin.ignore();
        getline(cin, bukuBaru->judul);
        cout << "Masukkan Pengarang: ";
        getline(cin, bukuBaru->pengarang);
        cout << "Masukkan Tahun Terbit: ";
        cin >> bukuBaru->tahunTerbit;
        
        daftarBuku[jumlahBuku++] = bukuBaru;
        cout << "Buku berhasil ditambahkan.\n";
    } else {
        cout << "Kapasitas perpustakaan penuh.\n";
    }
}


void cariBuku(const string& ISBN) {
    for (int i = 0; i < jumlahBuku; ++i) {
        if (daftarBuku[i]->ISBN == ISBN) {
            cout << "Buku ditemukan:\n";
            cout << "ISBN: " << daftarBuku[i]->ISBN << "\n";
            cout << "Judul: " << daftarBuku[i]->judul << "\n";
            cout << "Pengarang: " << daftarBuku[i]->pengarang << "\n";
            cout << "Tahun Terbit: " << daftarBuku[i]->tahunTerbit << "\n";
            return;
        }
    }
    cout << "Buku dengan ISBN " << ISBN << " tidak ditemukan.\n";
}


void tampilkanBuku() {
    if (jumlahBuku == 0) {
        cout << "Tidak ada buku di perpustakaan.\n";
        return;
    }
    
    cout << "Daftar Buku:\n";
    for (int i = 0; i < jumlahBuku; ++i) {
        cout << "ISBN: " << daftarBuku[i]->ISBN << "\n";
        cout << "Judul: " << daftarBuku[i]->judul << "\n";
        cout << "Pengarang: " << daftarBuku[i]->pengarang << "\n";
        cout << "Tahun Terbit: " << daftarBuku[i]->tahunTerbit << "\n\n";
    }
}


void pinjamBuku(const string& ISBN) {
    for (int i = 0; i < jumlahBuku; ++i) {
        if (daftarBuku[i]->ISBN == ISBN) {
            antrianPeminjaman.push(ISBN);
            cout << "Buku dengan ISBN " << ISBN << " telah ditambahkan ke antrian peminjaman.\n";
            return;
        }
    }
    cout << "Buku dengan ISBN " << ISBN << " tidak ditemukan di perpustakaan.\n";
}


void kembalikanBuku() {
    if (antrianPeminjaman.empty()) {
        cout << "Tidak ada buku dalam antrian peminjaman.\n";
        return;
    }

    string ISBN = antrianPeminjaman.front();
    antrianPeminjaman.pop();
    riwayatPeminjaman.push(ISBN);
    cout << "Buku dengan ISBN " << ISBN << " telah dikembalikan dan ditambahkan ke riwayat peminjaman.\n";
}


void tampilkanRiwayat() {
    if (riwayatPeminjaman.empty()) {
        cout << "Belum ada riwayat peminjaman.\n";
        return;
    }

    cout << "Riwayat Peminjaman:\n";
    stack<string> tempStack = riwayatPeminjaman;
    while (!tempStack.empty()) {
        cout << "ISBN: " << tempStack.top() << endl;
        tempStack.pop();
    }
}

int main() {
    int pilihan;
    string ISBN;

    do {
        cout << "\nMenu Perpustakaan:\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Cari Buku\n";
        cout << "3. Tampilkan Semua Buku\n";
        cout << "4. Pinjam Buku\n";
        cout << "5. Kembalikan Buku\n";
        cout << "6. Tampilkan Riwayat Peminjaman\n";
        cout << "7. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahBuku();
                break;
            case 2:
                cout << "Masukkan ISBN untuk mencari buku: ";
                cin >> ISBN;
                cariBuku(ISBN);
                break;
            case 3:
                tampilkanBuku();
                break;
            case 4:
                cout << "Masukkan ISBN buku yang akan dipinjam: ";
                cin >> ISBN;
                pinjamBuku(ISBN);
                break;
            case 5:
                kembalikanBuku();
                break;
            case 6:
                tampilkanRiwayat();
                break;
            case 7:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (pilihan != 7);

    
    for (int i = 0; i < jumlahBuku; ++i) {
        delete daftarBuku[i];
    }

    return 0;
}
