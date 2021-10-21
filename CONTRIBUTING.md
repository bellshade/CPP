# Panduan Berkontribusi
![Contributor](https://shields.io/github/contributors/bellshade/CPP?style=for-the-badge&logo=appveyor&label=Kontributor)
![forks](https://img.shields.io/github/forks/bellshade/CPP?style=for-the-badge&logo=appveyor)

## Persyaratan Kontribusi

Terima kasih atas minat anda untuk berkontribusi dalam pengembangan repositori CPP
di Bellshade. Di sini, semua orang boleh berkontribusi sesuai dengan kapasitasnya dengan persyaratan sebagai berikut:

- Seluruh hasil perkerjaan dibuat secara pribadi. Tidak ada toleransi untuk pelanggaran hak cipta dan plagiarisme
- Seluruh hasil kontribusi yang berhasil di `merged` ke dalam repositori CPP Bellshade berlisensi [MIT](LICENSE). 
- Penulisan kode mengikuti standar dan tata cara penulisan yang telah ditentukan
- Dilarang menggunakan *library* eksternal kecuali jika sangat diperlukan dan telah didiskusikan pada [issue](https://github.com/bellshade/CPP/issues).


## Tentang Bellshade CPP

### Introduksi
Bellshade CPP adalah repositori algoritma yang diimplementasikan menggunakan bahasa C++. Bellshade CPP merupakan bagian dari project Bellshade
yang dipelopori oleh para admin komunitas discord [Web Programming Unpas](http://discord.gg/S4rrXQU). Bellshade CPP bertujuan memperkenalkan berbagai
algoritma komputer dalam bahasa indonesia yang singkat, padat, dan mudah dimengerti. 

### Apa itu Algoritma?

Dalam ilmu komputer, algoritma dapat didefinisikan sebagai seperangkat perintah terdefinisi yang berfungsi untuk mencapai suatu pekerjaan. Umumnya, perintah dibuat sedemikian rupa agar pekerjaan dapat dilakukan secara efektif dan efisien.


## Informasi Perubahan dan Penambahan Kode

### Prosedur Pelaksanaan Kontribusi
Secara umum, kontribusi yang dilakukan dapat berupa penambahan algoritma dan perbaikan/perubahan kode. <br>
Berikut adalah langkah - langkah yang perlu dilakukan untuk menambahkan algoritma:
1. Memeriksa *pinned* [issue](https://github.com/bellshade/CPP/issues) untuk mendapatkan informasi mengenai daftar algoritma yang akan diimplementasi
2. Memberikan *comment* pada issue yang terkait bahwa kalian akan membuat algoritma tersebut
3. Fork repositori `bellshade/CPP` ke akun pribadi kalian `userkalian/CPP`
4. Membuat kode sesuai dengan persyaratan dan tata cara yang sesuai
5. Melakukan `Pull Request` pada `branch` yang telah disediakan sesuai dengan issue yang dikerjakan dan sertakan `link` issue pada judul `Pull Request`
6. Lakukan revisi sesuai dengan review yang diberikan oleh *maintainer*
7. Apabila `Pull Request` dinilai telah memenuhi persyaratan, maka `Pull Requst` akan di `merged` dan proses kontribusi selesai.

Perbaikan atau perubahan kode dapat dilakukan apabila ditemukan kesalahan pada repositori. Untuk melakukannya, berikut
langkah - langkah yang perlu dilakukan:
1. Membuat [issue](https://github.com/bellshade/CPP/issues) sesuai dengan format yang telah ditentukan
2. Lakukan langkah 3 - 7 pada prosedur penambahan algoritma

### Persyaratan Teknis
- Pastikan file ekstensi berupa ``*.cpp``
- Tidak menggunakan ``bits/stdc++.h`` karena ini cukup spesifik untuk linux dan memperlambat proses kompilasi
- Gunakan snake_case (underscore_snake_case) dalam nama file
- Kami menggunakan [CMake](https://cmake.org/) untuk testing, jadi pastikan kode kalian testing menggunakan CMake


## Issues

### Informasi Umum
`Issues` adalah media komunikasi utama seluruh kontributor `bellshade/CPP`. Issue mempermudah kita untuk melakukan *tracking* terhadap seluruh pekerjaan yang sudah, sedang, dan akan dilakukan. GitHub Issue memungkinkan para kontributor untuk melakukan *cross-reference* antara `Issues`, `Pull Requests`, dan `branches`. GitHub issue juga memungkinkan untuk maintainer melakukan *assessment* terhadap pekerjaan - pekerjaan yang terkait. 

### Format Issue
Agar komunikasi menggunakan `Issues` menjadi efektif dan efisien, maka format berikut harus digunakan. Kegagalan memberikan informasi yang cukup akan menyebabkan `Issues` akan langsung ditutup oleh maintainer.

Berikut adalah format standar pembuatan `Issues` pada repositori ini.
> #### General Information
> Berisi informasi umum mengenai problem atau fitur yang ingin dibahas. <br>
> General Information harus menyeluruh dan lengkap.
> #### Task / Development
> Berisi tindakan - tindakan yang perlu dilakukan untuk menyelesaikan masalah<br>
> yang dibahas pada general information
> #### Additional Information
> Berisi informasi tambahan yang tidak terkait langsung dengan masalah,<br>
> tetapi perlu diperhatikan


## Pull Request

### Pull Request Yang Baik

- Lakukan fork pada repository kami
- Setelah melakukan fork kalian dibebaskan untuk mengubah atau menambah algoritma
  - Untuk pull request merubah diusahakan kaliamn menerapkan algoritma yang lebih baik dan lebih mudah
- Setelah merubah, menambah, atau perbaikan dokumentasi, usahakan kalian membuat branch baru

```bash
git checkout -b <branch_name>
git add .
git commit -m "feat: menambahkan algoritma baru"
```

- Lakukan push ke branch kalian dan kemudian open pull request

### Pesan Commit

Pesan / message commit harus mengikuti conventional commit. Kami menggunakan bot label agar tidak susah dalam labeling.
Berikut adalah jenis-jenis pesan commit.

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
- Jika ada kendala atau masalah dalam pull request, kalian bisa laporkan masalah lewat [issue](https://github.com/bellshade/CppAlgorithm/issues)
- Jika ada test yang tidak lewat atau gagal, kami akan mengecek kembali perubahan.

Untuk pull request kami sarankan untuk menjelaskan secara detail yang kalian ubah atau tambahkan, dan bersikap sopan, serta selalu berterima kasih, itu salah satu bentuk tata krama yang baik terhadap sesama contributor dan programmer lainnya.Terima kasih sudah berkontribusi di **CppAlgorithm**.
