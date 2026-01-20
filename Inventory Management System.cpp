#include <iostream>
#include <string>

using namespace std;

struct Baranginventaris {
    int kode;
    string nama;
    int jumlah;
    string satuan;
    double harga;
};

class Pengelolaaninventaris {
private:
    static const int MAKS_BARANG = 100;
    Baranginventaris inventaris[MAKS_BARANG];
    int jumlahbarang;
public:
    Pengelolaaninventaris() : jumlahbarang(0) {}

    void tambahbarang(int kode, string nama, int jumlah, string satuan, double harga){
        if (jumlahbarang < MAKS_BARANG) {
            inventaris[jumlahbarang].kode = kode;
            inventaris[jumlahbarang].nama = nama;
            inventaris[jumlahbarang].jumlah = jumlah;
            inventaris[jumlahbarang].satuan = satuan;
            inventaris[jumlahbarang].harga = harga;
            jumlahbarang++;
            cout << "Barang berhasil ditambahkan!" << endl;
        } else {
            cout << "Inventaris penuh. Tidak dapat menambahkan barang lebih banyak lagi." << endl;
        }
    }

    void hapusbarang(int kode){
        for (int i = 0; i < jumlahbarang; ++i){
            if (inventaris[i].kode == kode){
                for (int j = i; j < jumlahbarang - 1; ++j){
                    inventaris[j] = inventaris[j + 1];
                }
                jumlahbarang--;
                cout << "Barang berhasil di hapus." << endl;
                return;
            }
        }
        cout << "Barang dengan kode " << kode << " tidak ditemukan." << endl;
    }

    void ubahbarang (int kode, string nama, int jumlah, string satuan, double harga){
        for (int i = 0; i < jumlahbarang; ++i){
            if (inventaris[i].kode == kode) {
                inventaris[i].nama = nama;
                inventaris[i].jumlah = jumlah;
                inventaris[i].satuan = satuan;
                inventaris[i].harga = harga;
                return;
            }
        }
        cout << "Barang dengan kode " << kode << " tidak ditemukan." << endl;
    }

    void tampilkaninventaris() {
        cout << "Inventaris: " << endl;
        for (int i = 0; i < jumlahbarang; ++i){
            cout << "Kode: " << inventaris[i].kode << ", Nama: " << inventaris[i].nama << ", Jumlah: " << inventaris[i].jumlah << ", Satuan: " << inventaris[i].satuan << ", Harga: " << inventaris[i].harga << endl;
        }
    }

    void caribarang (int kode) {
        cout << "Inventaris: " << endl;
        for (int i = 0; i < jumlahbarang; ++i) {
            if (inventaris[i].kode == kode) {
                cout << "Barang ditemukan: " << endl;
                cout << "Kode: " << inventaris[i].kode << ", Nama: " << inventaris[i].nama << ", Jumlah: " << inventaris[i].jumlah << ", Satuan: " << inventaris[i].satuan << ", Harga: " << inventaris[i].harga << endl;
                return;
            }
        }
        cout << "Barang dengan kode " << kode << " tidak ditemukan." << endl;
    }
};

int main () {
    Pengelolaaninventaris pengelola;
    int pilihan;

    do {
        cout << "=== Sistem Pengelolaan Inventaris ===" << endl;
        cout << "1. Tambah barang" << endl;
        cout << "2. Hapus barang" << endl;
        cout << "3. Ubah barang" << endl;
        cout << "4. Tampilkan Inventaris" << endl;
        cout << "5. Cari barang" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan pilihan anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int kode, jumlah;
                string nama, satuan;
                double harga;
                cout << "Masukkan kode barang: ";
                cin >> kode;
                cout << "Masukkan nama barang: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan jumlah barang: ";
                cin >> jumlah;
                cout << "Masukkan satuan barang: ";
                cin >> satuan;
                cout << "Masukkan harga barang: ";
                cin >> harga;
                pengelola.tambahbarang(kode, nama, jumlah, satuan, harga);
                break;
            }

            case 2 : {
                int kode;
                cout << "Masukkan kode barang yang ingin dihapus: ";
                cin >> kode;
                pengelola.hapusbarang(kode);
                break;
            }

            case 3: {
                int kode, jumlah;
                string nama, satuan;
                double harga;
                cout << "Masukkan kode barang yang akan diubah: ";
                cin >> kode;
                cout << "Masukkan nama barang baru: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan jumlah barang baru: ";
                cin >> jumlah;
                cout << "Masukkan satuan barang baru: ";
                cin >> satuan;
                cout << "Masukkan harga barang baru: ";
                cin >> harga;
                pengelola.ubahbarang(kode, nama, jumlah, satuan, harga);
                break;
            }

            case 4: {
                pengelola.tampilkaninventaris();
                break;
            }

            case 5: {
                int kode;
                cout << "Masukkan kode barang yang ingin dicari: ";
                cin >> kode;
                pengelola.caribarang(kode);
                break;  
            }

            case 6: 
                cout << "Keluar dari program..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Harap masukkan angka antara 1 hingga 6." << endl;
            
        }
    } while (pilihan != 6);

    return 0;

}
