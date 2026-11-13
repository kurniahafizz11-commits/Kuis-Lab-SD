#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

struct Node {
    int id;
    Node *kiri, *kanan;
};

Node* insertBST(Node* r, int id) {
    if (!r) return new Node{id, NULL, NULL};
    if (id < r->id) r->kiri = insertBST(r->kiri, id);
    else if (id > r->id) r->kanan = insertBST(r->kanan, id);
    return r;
}

void tampilBST(Node* r, int tipe) { // 1: Pre, 2: In, 3: Post
    if (!r) return;
    if (tipe == 1) cout << r->id << " ";
    tampilBST(r->kiri, tipe);
    if (tipe == 2) cout << r->id << " ";
    tampilBST(r->kanan, tipe);
    if (tipe == 3) cout << r->id << " ";
}

int main() {
    queue<string> antrean;
    stack<string> riwayat;
    Node* root = NULL;
    int pilih;

    do {
        cout << "\n=== MENU PERPUSTAKAAN ===\n"
             << "1. Antrean Pinjam (Queue)\n"
             << "2. Riwayat Kembali (Stack)\n"
             << "3. Input & Lihat BST Buku\n"
             << "4. Cari ID Buku di BST\n"
             << "5. Keluar\nPilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: {
                int p; string nama;
                cout << "1. Daftar Antrean | 2. Layani & Cek Antrean: "; cin >> p;
                if (p == 1) {
                    cout << "Nama: "; cin >> nama;
                    antrean.push(nama);
                } else if (p == 2) {
                    if (antrean.empty()) { cout << "Antrean belum diinput!\n"; break; }
                    cout << "Dilayani (FIFO): " << antrean.front() << endl;
                    antrean.pop();
                } else cout << "Pilihan tidak valid!\n";
                break;
            }
            case 2: {
                int p; string buku;
                cout << "1. Kembalikan Buku | 2. Lihat Riwayat: "; cin >> p;
                if (p == 1) {
                    cout << "Nama Buku: "; cin >> buku;
                    riwayat.push(buku);
                } else if (p == 2) {
                    if (riwayat.empty()) { cout << "Riwayat belum diinput!\n"; break; }
                    cout << "Terakhir dikembalikan (LIFO): " << riwayat.top() << endl;
                } else cout << "Pilihan tidak valid!\n";
                break;
            }
            case 3: {
                int id;
                cout << "Masukkan ID Buku (angka): "; cin >> id;
                root = insertBST(root, id);
                cout << "Pre-Order  : "; tampilBST(root, 1);
                cout << "\nIn-Order   : "; tampilBST(root, 2);
                cout << "\nPost-Order : "; tampilBST(root, 3); cout << endl;
                break;
            }
            case 4: {
                if (!root) { cout << "ID buku belum diinput!\n"; break; }
                int cari; cout << "Cari ID Buku: "; cin >> cari;
                Node* curr = root;
                while (curr && curr->id != cari)
                    curr = (cari < curr->id) ? curr->kiri : curr->kanan;
                cout << (curr ? "ID Ditemukan!\n" : "ID Tidak ditemukan!\n");
                break;
            }
            case 5: cout << "Selesai.\n"; break;
            default: cout << "Menu tidak valid!\n";
        }
    } while (pilih != 5);

    return 0;
}
