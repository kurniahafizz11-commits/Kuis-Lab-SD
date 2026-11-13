#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nim, nama;
    int nilai;
    Node* next;
};

int main() {
    Node* head = NULL;
    int* arr = NULL;
    int n = 0, pilih;

    do {
        cout << "\n=== MENU NILAI MAHASISWA ===\n";
        cout << "1. Input Data\n";
        cout << "2. Urutkan Nilai (Insertion Sort)\n";
        cout << "3. Cari NIM (Linear Search)\n";
        cout << "4. Cari Nilai (Binary Search)\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
            case 1: {
                int tambah;
                cout << "Jumlah data: ";
                cin >> tambah;
                if (tambah <= 0) {
                    cout << "Jumlah data harus lebih dari 0!\n";
                    break;
                }

                // Perbesar ukuran array agar nilai lama tidak hilang
                int* arrBaru = new int[n + tambah];
                for (int i = 0; i < n; i++) {
                    arrBaru[i] = arr[i];
                }
                delete[] arr;
                arr = arrBaru;

                // Input data baru dan sambungkan ke head lama (tanpa head = NULL)
                for (int i = n; i < n + tambah; i++) {
                    Node* baru = new Node;
                    cout << "\nNIM   : "; cin >> baru->nim;
                    cout << "Nama  : "; cin >> baru->nama;
                    cout << "Nilai : "; cin >> baru->nilai;

                    arr[i] = baru->nilai;
                    baru->next = head;
                    head = baru;
                }
                n += tambah; // Tambahkan jumlah data baru ke total data
                break;
            }
            case 2: {
                if (n == 0 || head == NULL) {
                    cout << "Data belum diinput!\n";
                    break;
                }

                for (int i = 1; i < n; i++) {
                    int key = arr[i];
                    int j = i - 1;
                    while (j >= 0 && arr[j] > key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                cout << "Data Mahasiswa:\n";
                for (Node* p = head; p; p = p->next)
                    cout << p->nim << " | " << p->nama << " | " << p->nilai << endl;
                cout << "Nilai terurut: ";
                for (int i = 0; i < n; i++) cout << arr[i] << " ";
                cout << endl;
                break;
            }
            case 3: {
                if (n == 0 || head == NULL) {
                    cout << "Data belum diinput!\n";
                    break;
                }

                bool ketemu = false; // Reset status ketemu setiap kali mencari
                string cariNIM;
                cout << "Masukkan NIM: ";
                cin >> cariNIM;
                for (Node* p = head; p != NULL; p = p->next) {
                    if (p->nim == cariNIM) {
                        cout << "Ketemu! Nama: " << p->nama << ", Nilai: " << p->nilai << endl;
                        ketemu = true; 
                    }
                }
                if (!ketemu) {
                    cout << "Data Tidak ada\n";
                }
                break;
            }
            case 4: {
                if (n == 0 || head == NULL) {
                    cout << "Data belum diinput!\n";
                    break;
                }

                // Pastikan nilai diurutkan dulu agar Binary Search akurat
                for (int i = 1; i < n; i++) {
                    int key = arr[i], j = i - 1;
                    while (j >= 0 && arr[j] > key) { arr[j + 1] = arr[j]; j--; }
                    arr[j + 1] = key;
                }

                bool ketemu = false; // Reset status ketemu setiap kali mencari
                int cariNilai;
                cout << "Masukkan Nilai: ";
                cin >> cariNilai;
                int kiri = 0, kanan = n - 1;
                while (kiri <= kanan) {
                    int tengah = (kiri + kanan) / 2;
                    if (arr[tengah] == cariNilai) {
                        cout << "Nilai ditemukan pada urutan ke-" << tengah + 1 << endl;
                        ketemu = true;
                        break;
                    }
                    if (arr[tengah] < cariNilai) kiri = tengah + 1;
                    else kanan = tengah - 1;
                }
                if (!ketemu) {
                    cout << "Data Tidak ada\n";
                }
                break;
            }
            case 5: {
                cout << "Terima kasih\n";
                break;
            }
            default: {
                cout << "Menu tidak valid\n";
                break;
            }
        }
    } while (pilih != 5);
    
    return 0;
}
