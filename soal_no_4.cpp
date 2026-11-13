#include <iostream>
#include <string>
using namespace std;

const int SIZE = 20;

struct HashItem {
    long long nim;     // Key (pakai long long agar muat NIM panjang)
    string nama;       // Value
    int status;        // 0 = Kosong, 1 = Terisi, 2 = Pernah Dihapus (Deleted)
};

int hash1(long long key) {
    return key % 20;
}

int hash2(long long key) {
    return 19 - (key % 19);
}

int main() {
    HashItem tabel[SIZE];
    for (int i = 0; i < SIZE; i++) tabel[i].status = 0; // Set semua kosong

    int pilih, jumlahData = 0;

    do {
        cout << "\n=== MENU HASH TABLE MAHASISWA ===\n"
             << "1. Insert Data Mahasiswa\n"
             << "2. Search NIM\n"
             << "3. Remove NIM\n"
             << "4. Display Hash Table\n"
             << "5. Keluar\n"
             << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
            case 1: { // INSERT
                if (jumlahData >= SIZE) {
                    cout << "Hash Table sudah penuh (maksimal 20 data)!\n";
                    break;
                }
                long long nim;
                string nama;
                cout << "Masukkan NIM (angka) : "; cin >> nim;
                cout << "Masukkan Nama        : "; cin >> nama;

                int h1 = hash1(nim);
                int h2 = hash2(nim);
                int i = 0, idx;

                while (i < SIZE) {
                    idx = (h1 + i * h2) % SIZE;
                    if (tabel[idx].status == 1 && tabel[idx].nim == nim) {
                        cout << "NIM sudah terdaftar di indeks " << idx << "!\n";
                        break;
                    }
                    if (tabel[idx].status != 1) { // Kosong atau bekas dihapus
                        tabel[idx] = {nim, nama, 1};
                        jumlahData++;
                        cout << "Data disimpan di indeks ke-" << idx;
                        if (i > 0) cout << " (terjadi collision " << i << "x)";
                        cout << endl;
                        break;
                    }
                    i++;
                }
                break;
            }
            case 2: { // SEARCH
                if (jumlahData == 0) {
                    cout << "Data belum diinput! Silakan pilih menu 1 dulu.\n";
                    break;
                }
                long long cari;
                cout << "Masukkan NIM yang dicari: "; cin >> cari;

                int h1 = hash1(cari), h2 = hash2(cari), i = 0;
                bool ketemu = false;

                while (i < SIZE) {
                    int idx = (h1 + i * h2) % SIZE;
                    if (tabel[idx].status == 0) break; // Berhenti jika ketemu slot murni kosong
                    if (tabel[idx].status == 1 && tabel[idx].nim == cari) {
                        cout << "Ditemukan di indeks ke-" << idx << " -> Nama: " << tabel[idx].nama << endl;
                        ketemu = true;
                        break;
                    }
                    i++;
                }
                if (!ketemu) cout << "NIM tidak ditemukan!\n";
                break;
            }
            case 3: { // REMOVE
                if (jumlahData == 0) {
                    cout << "Data belum diinput! Silakan pilih menu 1 dulu.\n";
                    break;
                }
                long long hapus;
                cout << "Masukkan NIM yang akan dihapus: "; cin >> hapus;

                int h1 = hash1(hapus), h2 = hash2(hapus), i = 0;
                bool terhapus = false;

                while (i < SIZE) {
                    int idx = (h1 + i * h2) % SIZE;
                    if (tabel[idx].status == 0) break;
                    if (tabel[idx].status == 1 && tabel[idx].nim == hapus) {
                        tabel[idx].status = 2; // Tandai sebagai Deleted (Tombstone)
                        jumlahData--;
                        cout << "Data NIM " << hapus << " di indeks ke-" << idx << " berhasil dihapus.\n";
                        terhapus = true;
                        break;
                    }
                    i++;
                }
                if (!terhapus) cout << "NIM tidak ditemukan, gagal menghapus!\n";
                break;
            }
            case 4: { // DISPLAY
                cout << "\n--- ISI HASH TABLE (SIZE 20) ---\n";
                for (int i = 0; i < SIZE; i++) {
                    cout << "Index [" << i << "] : ";
                    if (tabel[i].status == 1) {
                        cout << tabel[i].nim << " - " << tabel[i].nama << endl;
                    } else if (tabel[i].status == 2) {
                        cout << "[DELETED]\n";
                    } else {
                        cout << "[KOSONG]\n";
                    }
                }
                break;
            }
            case 5: {
                cout << "Program selesai. Terima kasih!\n";
                break;
            }
            default: {
                cout << "Menu tidak valid! Silakan pilih angka 1 sampai 5.\n";
                break;
            }
        }
    } while (pilih != 5);

    return 0;
}
