# Panduan Berkontribusi

## Kontributor

Kami sangat senang anda telah ikut berkontribusi dalam implementasi algortima, struktur data atau memperbaiki error.
Semua boleh ikut berkontribusi walaupun hal kecil dengan pengecualian sebagai berikut:

- Hasil pekerjaan kamu adalah buatan kamu sendiri dan tidak ada hak cipta dari orang lain
  - Jika kami menemukan kesamaan maka kami tidak `merged`.
- Hasil kerja kamu akan berlisensi [MIT](LICENSE) ketika permintaan pull kamu sudah di merged
- Hasil kerja kamu wajib mengikuti standar dan style koding dari kami
- Menghindari penggunaan library pada koding (jika dibutuhkan silahkan diskusikan di [issue](https://github.com/bellshade/CppAlgorithm/issues))

## Apa itu Algoritma?

Algoritma adalah langkah-langkah untuk menyelesaikan suatu pekerjaan dimana terdiri dari 3 bagian utama, yaitu:

- Input/masukan, sebelum menjalankan sebuah algoritma maka hal yang pertama harus dilakukan adalah menerima masukan, input dapat berasal dari pengguna ataupun dari langkah sebelumnya.
- Proses, bagian utama dari algoritma yang melakukan pengolahan input yang akan menghasilkan output.
- Output/keluaran, output adalah hasil dari bagian proses, output ini juga bisa digunakan untuk langkah selanjutnya (jika masih ada).

Algoritma harus dikemas sedemikian rupa sehingga memudahkan pembaca untuk memasukkannya ke dalam program yang lebih besar.

## Informasi Perubahan dan Penambahan Kode

### Persyaratan 
- Pastikan file ekstensi berupa ``*.cpp``
- Tidak menggunakan ``bits/stdc++.h`` karena ini cukup spesifik untuk linux dan memperlambat proses kompilasi
- Gunakan snake_case (underscore_snake_case) dalam nama file
- Kami menggunakan [CMake](https://cmake.org/) untuk testing, jadi pastikan kode kamu testing menggunakan CMake

## Pull Request

### Pull Request Yang Baik

- Lakukan fork pada repository kami
- Setelah melakukan fork kamu dibebaskan untuk mengubah atau menambah algoritma
  - Untuk pull request merubah diusahakan kamu menerapkan algoritma yang lebih baik dan lebih mudah
- Setelah merubah, menambah, atau perbaikan dokumentasi, usahakan kamu membuat branch baru

```bash
git checkout -b <branch_name>
git add .
git commit -m "add: menambahkan algoritma baru"
```

- Lakukan push ke branch kamu dan kemudian open pull request

### Pesan Commit

Pesan / message commit harus mengikuti conventional commit. Kami menggunakan bot label agar tidak susah dalam labeling.
Berikut adalah jenis - jenis pesan commit.

- `fix:` untuk memperbaiki bug (label `bug`).
- `feat:` untuk menambahkan algoritma terbaru (label `enhancement`).
- `docs:` untuk menambahkan dokumentasi (label `documentation`).
- `fix(UnknownScope):` memperbaiki algoritma yang sudah ada (label `fix`).

Referensi:
[Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/)

### Contoh Penggunaan 
```bash
git commit -m "docs: menambahkan dokumentasi"
```
```bash
git commit -m  "feat: menambahkan algoritma terbaru"
```

Pull request `merged` jika:

- Mengikuti standar dan arahan dari `CONTRIBUTING.md`
- Lulus test dan cek dari beberapa test yang sudah kami siapkan

### Tambahan
- Jika ada kendala atau masalah dalam pull request, kamu bisa laporkan masalah lewat [issue](https://github.com/bellshade/CppAlgorithm/issues)
- Jika ada test yang tidak lewat atau gagal, kami akan mengecek kembali perubahan.

Untuk pull request kami sarankan untuk menjelaskan secara detail yang kamu ubah atau tambahkan, dan bersikap sopan, serta selalu berterima kasih, itu salah satu bentuk tata krama yang baik terhadap sesama contributor dan programmer lainnya.Terima kasih sudah berkontribusi di **CppAlgorithm**.
