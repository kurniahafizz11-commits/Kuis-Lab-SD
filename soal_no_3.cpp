#include <iostream>
#include <queue>
#include <stack>
using namespace std;

const int V = 6;
char namaVertex[V] = {'A', 'B', 'C', 'D', 'E', 'F'};

// Adjacency Matrix sesuai tabel bobot pada soal (6x6)
int graf[V][V] = {
    //A  B  C  D  E  F
    { 0, 4, 2, 0, 0, 0 }, // A
    { 4, 0, 1, 5, 3, 0 }, // B
    { 2, 1, 0, 8, 6, 0 }, // C
    { 0, 5, 8, 0, 2, 4 }, // D
    { 0, 3, 6, 2, 0, 3 }, // E
    { 0, 0, 0, 4, 3, 0 }  // F
};

// Ubah huruf A-F menjadi indeks 0-5
int keIndeks(char c) {
    c = toupper(c);
    if (c >= 'A' && c <= 'F') return c - 'A';
    return -1;
}

int main() {
    int pilih;

    do {
        cout << "\n=== MENU RUTE KAMPUS (A - F) ===\n"
             << "1. Tampilkan Adjacency Matrix\n"
             << "2. Penelusuran BFS\n"
             << "3. Penelusuran DFS\n"
             << "4. Cari Rute Terpendek (Dijkstra)\n"
             << "5. Keluar\n"
             << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
            case 1: {
                cout << "\nAdjacency Matrix:\n   A B C D E F\n";
                for (int i = 0; i < V; i++) {
                    cout << namaVertex[i] << "  ";
                    for (int j = 0; j < V; j++) cout << graf[i][j] << " ";
                    cout << endl;
                }
                break;
            }
            case 2: { // BFS
                char awal;
                cout << "Masukkan vertex awal (A-F): "; cin >> awal;
                int start = keIndeks(awal);
                if (start == -1) { cout << "Vertex tidak valid! Gunakan A sampai F.\n"; break; }

                bool dikunjungi[V] = {false};
                queue<int> q;
                dikunjungi[start] = true;
                q.push(start);

                cout << "Hasil BFS: ";
                while (!q.empty()) {
                    int curr = q.front(); q.pop();
                    cout << namaVertex[curr] << " ";
                    for (int i = 0; i < V; i++) {
                        if (graf[curr][i] > 0 && !dikunjungi[i]) {
                            dikunjungi[i] = true;
                            q.push(i);
                        }
                    }
                }
                cout << endl;
                break;
            }
            case 3: { // DFS
                char awal;
                cout << "Masukkan vertex awal (A-F): "; cin >> awal;
                int start = keIndeks(awal);
                if (start == -1) { cout << "Vertex tidak valid! Gunakan A sampai F.\n"; break; }

                bool dikunjungi[V] = {false};
                stack<int> s;
                s.push(start);

                cout << "Hasil DFS: ";
                while (!s.empty()) {
                    int curr = s.top(); s.pop();
                    if (!dikunjungi[curr]) {
                        dikunjungi[curr] = true;
                        cout << namaVertex[curr] << " ";
                        for (int i = V - 1; i >= 0; i--) {
                            if (graf[curr][i] > 0 && !dikunjungi[i]) s.push(i);
                        }
                    }
                }
                cout << endl;
                break;
            }
            case 4: { // Dijkstra
                char cAwal, cTujuan;
                cout << "Vertex awal (A-F)   : "; cin >> cAwal;
                cout << "Vertex tujuan (A-F) : "; cin >> cTujuan;
                int awal = keIndeks(cAwal), tujuan = keIndeks(cTujuan);

                if (awal == -1 || tujuan == -1) {
                    cout << "Vertex tidak valid! Masukkan huruf A sampai F.\n";
                    break;
                }

                int jarak[V], asal[V];
                bool selesai[V] = {false};
                for (int i = 0; i < V; i++) { jarak[i] = 9999; asal[i] = -1; }
                jarak[awal] = 0;

                for (int count = 0; count < V - 1; count++) {
                    int u = -1, minJarak = 9999;
                    for (int i = 0; i < V; i++) {
                        if (!selesai[i] && jarak[i] < minJarak) {
                            minJarak = jarak[i];
                            u = i;
                        }
                    }
                    if (u == -1) break;
                    selesai[u] = true;

                    for (int v = 0; v < V; v++) {
                        if (!selesai[v] && graf[u][v] > 0 && jarak[u] + graf[u][v] < jarak[v]) {
                            jarak[v] = jarak[u] + graf[u][v];
                            asal[v] = u;
                        }
                    }
                }

                // Tampilkan total jarak dan urutan rute
                cout << "Total jarak terpendek: " << jarak[tujuan] << endl;
                cout << "Rute yang dilalui   : ";
                int rute[V], idx = 0, curr = tujuan;
                while (curr != -1) { rute[idx++] = curr; curr = asal[curr]; }
                for (int i = idx - 1; i >= 0; i--) {
                    cout << namaVertex[rute[i]] << (i > 0 ? " -> " : "");
                }
                cout << endl;
                break;
            }
            case 5: cout << "Program selesai.\n"; break;
            default: cout << "Menu tidak valid! Pilih angka 1 sampai 5.\n";
        }
    } while (pilih != 5);

    return 0;
}
