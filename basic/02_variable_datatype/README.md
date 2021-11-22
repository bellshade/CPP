# Variabel dan Tipe Data


## Variabel

Variabel adalah sebuah kontainer yang berfungsi dalam penyimpanan value sehingga dapat digunakan secara berulang kali. Variabel memetakan sebuah nama ke suatu nilai.

### Aturan Penamaan Variabel

Kamu bisa menamai variabel dengan nama apapun, tetapi ada beberapa aturan yang harus dipenuhi:

- Hanya terdiri dari huruf, angka, dan underscore (`_`)
- Tidak dimulai dengan angka
- Tidak boleh sama dengan *reserved word*. Contoh: `int`, `if`, `string`.

Contoh penamaan yang benar, seperti `hasil`, `jumlah_angka`, dan `namaSaya`. Perlu diperhatikan bahwa penggunaan huruf kapital akan berpengaruh (case sensitive). Variabel `angka` dan `Angka` akan dianggap berbeda.

> Dalam standar penamaan variabel, C++ menggunakan camelCase untuk penamaan pada variabel. Contoh: `angkaSaya`.
> 

### Deklarasi Variabel

Saat mendeklarasi sebuah variabel, kamu harus menyertakan tipe datanya. Tipe data dituliskan sebelum nama variabel, dipisahkan oleh spasi. Jika memiliki tipa data yang sama, kamu bisa mendeklarasikannya secara bersamaan

```cpp
<tipe_data> <nama_variabel> = <nilai>;
```

Variabel dapat dideklarasiikan dengan langsung memasukkan nilainya atau tanpa memberi nilai (nilai di-assign kemudian).

```cpp
// langsung memasukkan nilai
int angkaSaya = 15;

// hanya deklarasi nama
int angkaSaya;
angkaSaya = 15;

// deklarasi dengan tipe data sama
int nilai, jumlah;
double sisa = 1, hasil = 0;
```

### Menampilkan Nilai Variabel

Untuk menampilkan nilai variabel dalam C++, kamu bisa menggunakan perintah `cout` dengan menambahkan operator `<<`, seperti pada contoh di bawah ini.

```cpp
int angkaSaya = 30;
std::cout << "Angka Saya adalah " << angkaSaya; // 30
```

Kamu juga bisa mengganti nilai yang sebelumnya sudah terdapat pada variabel dengan cara

```cpp
int angkaSaya = 1;
angkaSaya = 30;
std::cout << "Angka saya sekarang adalah " << angkaSaya; // 30
```

Selain dengan perintah `cout`, kamu juga bisa menggunakan fungsi `printf`.

```cpp
int angkaSaya = 30;
printf("Angka Saya adalah %d", angkaSaya);
```

Berikut ini simbol-simbol untuk setiap tipe data. Penjelasan untuk masing-masing tipe data akan dijelaskan di bagian selanjutnya.

| Tipe data | Simbol |
| - | - |
| short | `%d` |
| unsigned short | `%u` |
| int | `%d` |
| unsigned int | `%u` |
| long long | `%lld` atau `%I64d` |
| unsigned long long | `%llu` atau `%I64u` |
| float | `%f` |
| double | `%lf` |
| char | `%c` |