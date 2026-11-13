# Kuis_Lab_SD_Kurnia_251401008

## Identitas
- **Nama** : Kurnia Hafiz Arrasyid
- **NIM** : _251401008_

## Struktur Folder
```
Kuis-Lab-SD/
├── README.md
├── soal_no_1.cpp   # Soal 1
├── soal_no_2.cpp   # Soal 2
├── soal_no_3.cpp   # Soal 3
└── soal_no_4.cpp   # Soal 4
```

## Deskripsi Program

### Soal 1 - Sistem Pengelolaan Nilai Mahasiswa (`soal_no_1.cpp`)
Program mengelola data mahasiswa (NIM, Nama, Nilai).
- **Single Linked List** menyimpan data mahasiswa. Data baru disisipkan di bagian depan list (`head`).
- **Dynamic Array** menyimpan kumpulan nilai. Setiap kali data ditambah, dibuat array baru berukuran `n + tambah`, data lama disalin, lalu array lama dihapus dengan `delete[]` sehingga nilai lama tidak hilang.
- **Insertion Sort** mengurutkan nilai dari terkecil ke terbesar, lalu menampilkan data mahasiswa dan nilai yang sudah terurut.
- **Linear Search** mencari mahasiswa berdasarkan NIM pada linked list.
- **Binary Search** mencari nilai tertentu pada array. Array diurutkan otomatis terlebih dahulu agar hasil pencarian akurat, lalu program menampilkan posisi (urutan ke-) nilai yang ditemukan.
- Terdapat validasi: menu pencarian dan pengurutan menolak proses jika data belum diinput, serta jumlah data harus lebih dari 0.

### Soal 2 - Sistem Antrean dan Pengelolaan Buku Perpustakaan (`soal_no_2.cpp`)
Program membantu pengelolaan peminjaman dan pengembalian buku.
- **Queue** (`queue<string>`) untuk antrean mahasiswa peminjam dengan prinsip FIFO: mendaftar antrean dan melayani mahasiswa terdepan.
- **Stack** (`stack<string>`) untuk riwayat pengembalian buku dengan prinsip LIFO: menyimpan buku yang dikembalikan dan menampilkan buku yang terakhir dikembalikan.
- **Binary Search Tree** untuk menyimpan ID buku (ID duplikat diabaikan). Setiap kali ID ditambahkan, program menampilkan traversal **Pre-Order**, **In-Order**, dan **Post-Order**. Terdapat juga fitur pencarian ID buku pada BST.
- Terdapat validasi: antrean, riwayat, dan BST yang masih kosong akan ditolak saat diproses.

### Soal 3 - Sistem Pencarian Rute di Lingkungan Kampus (`soal_no_3.cpp`)
Program memodelkan kampus sebagai graph tidak berarah berbobot dengan 6 vertex (A-F) menggunakan **Adjacency Matrix** sesuai tabel jarak pada soal.
- **BFS** menggunakan queue dari vertex awal pilihan pengguna.
- **DFS** menggunakan stack (iteratif) dari vertex awal pilihan pengguna.
- **Dijkstra** mencari jarak terpendek dari vertex awal ke vertex tujuan, lalu menampilkan total jarak dan rute yang dilalui (direkonstruksi dari array `asal`).
- Input vertex divalidasi (hanya A-F, huruf kecil juga diterima).

### Soal 4 - Sistem Pengelolaan Data Mahasiswa dengan Hash Table (`soal_no_4.cpp`)
Program menyimpan data mahasiswa dengan NIM sebagai key dan nama sebagai value.
- Ukuran tabel 20, penanganan collision dengan **Double Hashing**:
  `Hash1(key) = key % 20` dan `Hash2(key) = 19 - (key % 19)`.
- Setiap slot memiliki status: `0` kosong, `1` terisi, `2` dihapus (DELETED), sehingga pencarian tetap benar setelah penghapusan.
- Fitur **Insert** (menampilkan indeks penyimpanan dan jumlah collision, serta menolak NIM yang sudah terdaftar), **Search**, **Remove**, dan **Display**.
- NIM disimpan sebagai `long long` agar muat untuk NIM yang panjang.
- Terdapat validasi: tabel penuh (20 data) menolak insert, dan search/remove menolak proses jika data masih kosong.

## Cara Menjalankan

**Gunakan program lewat menu.** Setiap program menampilkan menu angka. Ketik nomor menu lalu tekan Enter, ikuti perintah input yang muncul, dan pilih menu terakhir (Keluar) untuk mengakhiri program. Menu akan muncul kembali setelah satu proses selesai.

**Soal 1 - Nilai Mahasiswa**

| Menu | Fungsi |
|------|--------|
| 1 | Input data (jumlah data, lalu NIM, Nama, Nilai) |
| 2 | Urutkan nilai (Insertion Sort) dan tampilkan data |
| 3 | Cari NIM (Linear Search) |
| 4 | Cari nilai (Binary Search) |
| 5 | Keluar |

Alur yang disarankan:
1. Pilih `1`, masukkan jumlah data (misal 3), lalu isi NIM, Nama, dan Nilai untuk setiap mahasiswa.
2. Pilih `2` untuk mengurutkan nilai dan melihat data mahasiswa.
3. Pilih `4` lalu masukkan nilai yang ingin dicari (Binary Search).
4. Pilih `3` lalu masukkan NIM yang ingin dicari (Linear Search).
5. Pilih `5` untuk keluar.

**Soal 2 - Perpustakaan**

| Menu | Fungsi |
|------|--------|
| 1 | Antrean pinjam (Queue): 1 daftar antrean, 2 layani antrean (FIFO) |
| 2 | Riwayat kembali (Stack): 1 kembalikan buku, 2 lihat riwayat terakhir (LIFO) |
| 3 | Input ID buku ke BST dan tampilkan Pre-Order, In-Order, Post-Order |
| 4 | Cari ID buku di BST |
| 5 | Keluar |

Alur yang disarankan:
1. Pilih `1` lalu `1`, masukkan nama mahasiswa. Ulangi beberapa kali untuk mengisi antrean.
2. Pilih `1` lalu `2` untuk melayani mahasiswa terdepan (FIFO).
3. Pilih `2` lalu `1`, masukkan nama buku yang dikembalikan. Ulangi beberapa kali, lalu pilih `2` lalu `2` untuk melihat buku terakhir yang dikembalikan (LIFO).
4. Pilih `3` dan masukkan ID buku (angka). Ulangi beberapa kali, traversal akan tampil setiap kali ID ditambahkan.
5. Pilih `4` lalu masukkan ID buku yang ingin dicari.
6. Pilih `5` untuk keluar.

**Soal 3 - Rute Kampus**

| Menu | Fungsi |
|------|--------|
| 1 | Tampilkan adjacency matrix |
| 2 | Penelusuran BFS (pilih vertex awal A-F) |
| 3 | Penelusuran DFS (pilih vertex awal A-F) |
| 4 | Cari rute terpendek dengan Dijkstra (pilih vertex awal dan tujuan A-F) |
| 5 | Keluar |

Graph sudah terisi otomatis sesuai tabel soal, jadi tidak perlu input data. Input vertex berupa huruf A-F (huruf besar maupun kecil).

Alur yang disarankan:
1. Pilih `1` untuk melihat adjacency matrix.
2. Pilih `2` lalu masukkan vertex awal (misal A) untuk BFS.
3. Pilih `3` lalu masukkan vertex awal (misal A) untuk DFS.
4. Pilih `4` lalu masukkan vertex awal (misal A) dan vertex tujuan (misal F) untuk Dijkstra.
5. Pilih `5` untuk keluar.

**Soal 4 - Hash Table**

| Menu | Fungsi |
|------|--------|
| 1 | Insert data mahasiswa (input NIM dan Nama) |
| 2 | Search berdasarkan NIM |
| 3 | Remove berdasarkan NIM |
| 4 | Display seluruh isi hash table (indeks 0-19) |
| 5 | Keluar |

Alur yang disarankan:
1. Pilih `1`, masukkan NIM dan Nama. Ulangi beberapa kali, gunakan NIM yang indeks hash-nya sama (misal `2024001` dan `2024021`) untuk mencoba collision.
2. Pilih `4` untuk melihat isi hash table.
3. Pilih `2` lalu masukkan NIM yang ingin dicari.
4. Pilih `3` lalu masukkan NIM yang ingin dihapus, kemudian pilih `4` lagi untuk melihat slot berstatus DELETED.
5. Pilih `5` untuk keluar.

## Catatan
- Semua program ditulis dalam C++ standar dan masing-masing berdiri sendiri (satu file per soal).
- Input teks (Nama dan nama buku) menggunakan `cin >>`, sehingga ditulis tanpa spasi (contoh: `Budi` atau `Budi_Santoso`).

## Video Penjelasan
YouTube: https://youtu.be/tKYo0iUeEg4?si=uoR3uzNyPBNkVE4W
