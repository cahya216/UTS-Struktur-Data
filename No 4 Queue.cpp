#include <iostream>
#include <queue>
#include <vector>

using namespace std;


struct Pelanggan {
    int nomorAntrian;
    int waktuLayanan;
};


class Queue {
private:
    queue<Pelanggan> q;
public:
    void enqueue(const Pelanggan& pelanggan) {
        q.push(pelanggan);
    }

    Pelanggan dequeue() {
        Pelanggan pelanggan = q.front();
        q.pop();
        return pelanggan;
    }

    bool isEmpty() {
        return q.empty();
    }

    int size() {
        return q.size();
    }
};


void simulasiAntrian(Queue& antrian, int jumlahLoket) {
    vector<int> waktuTersedia(jumlahLoket, 0); 
    int waktuTotalTunggu = 0;
    int pelangganTerlayani = 0;

    while (!antrian.isEmpty()) {
        Pelanggan pelanggan = antrian.dequeue();
        int loketTersedia = 0;

       
        for (int i = 1; i < jumlahLoket; ++i) {
            if (waktuTersedia[i] < waktuTersedia[loketTersedia]) {
                loketTersedia = i;
            }
        }

        
        int waktuTunggu = max(0, waktuTersedia[loketTersedia]);
        waktuTotalTunggu += waktuTunggu;
        waktuTersedia[loketTersedia] += pelanggan.waktuLayanan;

        cout << "Pelanggan " << pelanggan.nomorAntrian
             << " dilayani di loket " << loketTersedia + 1
             << " dengan waktu layanan " << pelanggan.waktuLayanan
             << " menit dan waktu tunggu " << waktuTunggu << " menit.\n";

        pelangganTerlayani++;
    }

    
    cout << "\nStatistik Antrian:\n";
    cout << "Rata-rata waktu tunggu: " << (pelangganTerlayani ? waktuTotalTunggu / pelangganTerlayani : 0) << " menit\n";
    cout << "Jumlah pelanggan terlayani: " << pelangganTerlayani << "\n";
    cout << "Sisa antrian: " << antrian.size() << "\n";
}

int main() {
    Queue antrian;
    int jumlahLoket = 3;
    int jumlahPelanggan;

    cout << "Masukkan jumlah pelanggan dalam antrian: ";
    cin >> jumlahPelanggan;

    for (int i = 1; i <= jumlahPelanggan; ++i) {
        Pelanggan pelanggan;
        pelanggan.nomorAntrian = i;
        cout << "Masukkan waktu layanan (dalam menit) untuk pelanggan " << i << ": ";
        cin >> pelanggan.waktuLayanan;
        antrian.enqueue(pelanggan);
    }

    simulasiAntrian(antrian, jumlahLoket);

    return 0;
}
