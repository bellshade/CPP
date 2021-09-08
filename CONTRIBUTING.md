# Contributing

**contributor**

Kami sangat senang anda telah ikut berkontribusi dalam implementasi algortima, struktur data atau memperbaiki error.
semua boleh ikut berkontribusi walaupun hal kecil dengan pengecualian sebagai berikut:

- hasil pekerjaan kamu adalah buatan kamu sendiri dan tidak ada hak cipta dari orang lain
  - jika kami menemukan kesamaan maka kami tidak `merged`.
- hasil kerja kamu akan berlisensi [MIT](LICENSE) ketika permintaan pull kamu sudah di merged
- hasil kerja kamu wajib mengikuti standar dan style koding dari kami
- menghindari penggunaan library pada koding (jika dibutuhkan silahkan diskusi di [issue](https://github.com/bellshade/CppAlgorithm/issues))

**apa itu algoritma?**

Algoritma adalah langkah-langkah untuk menyelesaikan suatu pekerjaan dimana terdiri dari 3 bagian utama, yaitu:

- Input/masukan, sebelum menjalankan sebuah algoritma maka hal yang pertama harus dilakukan adalah menerima masukan, input dapat berasal dari pengguna ataupun dari langkah sebelumnya.
- Proses, bagian utama dari algoritma yang melakukan pengolahan input yang akan menghasilkan output.
- Output/keluaran, output adalah hasil dari bagian proses, output ini juga bisa digunakan untuk langkah selanjutnya (jika masih ada).

Algoritma harus dikemas sedemikian rupa sehingga memudahkan pembaca untuk memasukkannya ke dalam program yang lebih besar.

## Informasi perubahan dan penambahan
**persyaratan perubahan atau penambahan kode**
- pastikan file ekstensi berupa ``*.cpp``
- tidak menggunakan ``bits/stdc++.h`` karena ini cukup spesifik untuk linux dan memperlambat proses kompilasi
- gunakan snake_case (underscore_snake_case) dalam nama file
- kami menggunakan [CMake](https://cmake.org/) untuk testing, jadi pastikan kode kamu testing menggunakan CMake

## Pull request
**Pull request yang baik**
- lakukan fork pada repositori kami
- setelah melakukan fork kamu dibebaskan untuk mengubah atau menambah algoritma
    - untuk pull request merubah diusahakan kamu menerapkan algoritma yang lebih baik dan lebih mudah
- setelah merubah,menambah, atau perbaikan dokumentasi, usahakan kamu membuat branch baru
```bash
git checkout -b <branch_name>
git add .
git commit -m "add: menambah algoritma terbaru"
```
- lakukan push ke branch kamu dan kemudian pull request

**Saran pessan commit**
- ``add`` untuk menambah algoritma atau tambahan lainnya
- ``fix`` untuk mengubah algoritma yang sudah ada atau memperbaiki
- ``docs`` untuk mengubah atau membuat dokumentasi
- ``style`` untuk mengubah atau memperbaiki style kode untuk contohnya bisa dilihat pada commit yang diatas

pull request ``merged`` jika:
- mengikuti standar dan arahan dari ``CONTRIBUTING.md``
- lulus test dan cek dari beberapa test yang sudah kami siapkan

**tambahan**
- jika ada kendala atau masalah dalam pull request, kamu bisa laporkan masalah pada issue
- jika ada test yang tidak lewat atau gagal, kami akan mengecek kembali perubahan.

untuk pull request kami sarankan untuk menjelaskan secara detail yang kamu ubah atau tambahkan, dan bersikap sopan, serta selalu berterima kasih, itu salah satu bentuk tata krama yang baik terhadap sesama contributor dan programmer lainnya.terima kasih sudah berkontribusi di **CppAlgorithm**
