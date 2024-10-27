#include <iostream>
#include <string>
using namespace std;


struct Mahasiswa {
    string NIM;
    string nama;
    float IPK;
};


void tambahMahasiswa(Mahasiswa* mahasiswa[], int& jumlah) {
    if (jumlah < 10) {
        Mahasiswa* mhsBaru = new Mahasiswa;
        cout << "Masukkan NIM: ";
        cin >> mhsBaru->NIM;
        cout << "Masukkan Nama: ";
        cin.ignore();
        getline(cin, mhsBaru->nama);
        cout << "Masukkan IPK: ";
        cin >> mhsBaru->IPK;
        mahasiswa[jumlah++] = mhsBaru;
        cout << "Data mahasiswa berhasil ditambahkan.\n";
    } else {
        cout << "Data mahasiswa penuh!\n";
    }
}


void hapusMahasiswa(Mahasiswa* mahasiswa[], int& jumlah, const string& NIM) {
    int index = -1;
    for (int i = 0; i < jumlah; i++) {
        if (mahasiswa[i]->NIM == NIM) {
            index = i;
            break;
        }
    }
    
    if (index != -1) {
        delete mahasiswa[index];
        for (int i = index; i < jumlah - 1; i++) {
            mahasiswa[i] = mahasiswa[i + 1];
        }
        mahasiswa[--jumlah] = nullptr;
        cout << "Data mahasiswa berhasil dihapus.\n";
    } else {
        cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan.\n";
    }
}


void tampilMahasiswa(Mahasiswa* mahasiswa[], int jumlah) {
    cout << "Daftar Mahasiswa:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "NIM: " << mahasiswa[i]->NIM 
             << ", Nama: " << mahasiswa[i]->nama 
             << ", IPK: " << mahasiswa[i]->IPK << endl;
    }
}


void urutkanMahasiswa(Mahasiswa* mahasiswa[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < jumlah; j++) {
            if (mahasiswa[j]->IPK > mahasiswa[maxIndex]->IPK) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            Mahasiswa* temp = mahasiswa[i];
            mahasiswa[i] = mahasiswa[maxIndex];
            mahasiswa[maxIndex] = temp;
        }
    }
    cout << "Data mahasiswa diurutkan berdasarkan IPK.\n";
}

int main() {
    Mahasiswa* mahasiswa[10] = {nullptr};
    int jumlah = 0;
    int pilihan;
    string nim;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Hapus Mahasiswa\n";
        cout << "3. Tampilkan Mahasiswa\n";
        cout << "4. Urutkan Mahasiswa berdasarkan IPK\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahMahasiswa(mahasiswa, jumlah);
                break;
            case 2:
                cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
                cin >> nim;
                hapusMahasiswa(mahasiswa, jumlah, nim);
                break;
            case 3:
                tampilMahasiswa(mahasiswa, jumlah);
                break;
            case 4:
                urutkanMahasiswa(mahasiswa, jumlah);
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    
    for (int i = 0; i < jumlah; i++) {
        delete mahasiswa[i];
    }

    return 0;
}
