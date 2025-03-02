#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Batalyon {
    int id; 
    string nama_jenderal;
    string tipe_pasukan;
    int jumlah_pasukan;
};

vector<Batalyon> batalyons;
string daftar_tipe[] = {"Infantry", "Kavaleri", "Archer"};

bool cekTipePasukan(string tipe) {
    for (int i = 0; i < 3; i++) {
        if (daftar_tipe[i] == tipe) return true;
    }
    return false;
}

bool cekNamaJenderal(string nama) {
    for (auto &b : batalyons) {
        if (b.nama_jenderal == nama) return true;
    }
    return false;
}

void tambahBatalyon() {
    Batalyon b;
    cout << "Masukkan ID Batalyon: ";
    cin >> b.id;
    cin.ignore();

    cout << "Masukkan Nama Jenderal: ";
    getline(cin, b.nama_jenderal);
    if (cekNamaJenderal(b.nama_jenderal)) {
        cout << "Error: Nama jenderal sudah terdaftar!" << endl;
        return;
    }

    cout << "Masukkan Tipe Pasukan (Infantry/Kavaleri/Archer): ";
    getline(cin, b.tipe_pasukan);
    if (!cekTipePasukan(b.tipe_pasukan)) {
        cout << "Error: Tipe pasukan tidak valid!" << endl;
        return;
    }

    cout << "Masukkan Jumlah Pasukan: ";
    cin >> b.jumlah_pasukan;
    if (b.jumlah_pasukan < 1) {
        cout << "Error: Jumlah pasukan harus lebih dari 0!" << endl;
        return;
    }
    
    batalyons.push_back(b);
    cout << "Batalyon berhasil ditambahkan!" << endl;
}

bool compareBatalyon(Batalyon a, Batalyon b) {
    return a.nama_jenderal < b.nama_jenderal;
}

void cariBatalyon() {
    if (batalyons.empty()) {
        cout << "Tidak ada data batalyon." << endl;
        return;
    }
    
    sort(batalyons.begin(), batalyons.end(), compareBatalyon);
    
    string nama;
    cout << "Masukkan Nama Jenderal yang dicari: ";
    cin.ignore();
    getline(cin, nama);
    
    int kiri = 0, kanan = batalyons.size() - 1;
    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        if (batalyons[tengah].nama_jenderal == nama) {
            cout << "Batalyon ditemukan:\n";
            cout << "ID: " << batalyons[tengah].id << "\n";
            cout << "Nama Jenderal: " << batalyons[tengah].nama_jenderal << "\n";
            cout << "Tipe Pasukan: " << batalyons[tengah].tipe_pasukan << "\n";
            cout << "Jumlah Pasukan: " << batalyons[tengah].jumlah_pasukan << "\n";
            return;
        }
        if (batalyons[tengah].nama_jenderal < nama)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }
    cout << "Batalyon tidak ditemukan!" << endl;
}

int main() {
    int pilihan;
    do {
        cout << "\nMENU:\n1. Tambah Batalyon\n2. Cari Batalyon\n3. Keluar\nPilihan: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1: tambahBatalyon(); break;
            case 2: cariBatalyon(); break;
            case 3: cout << "Keluar dari program." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 3);
    return 0;
}
