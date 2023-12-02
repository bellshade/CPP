# Function Rekursif
***Fungsi rekursif adalah fungsi yang memanggil dirinya sendiri selama proses eksekusi. Dalam konteks pemrograman, fungsi rekursif digunakan untuk memecah suatu masalah menjadi submasalah yang lebih kecil, dan solusi dari submasalah tersebut dihasilkan dengan cara memanggil fungsi itu sendiri.***

Fungsi rekursif terus memanggil dirinya sendiri hingga mencapai kasus dasar, di mana fungsi berhenti memanggil dirinya sendiri dan mulai mengembalikan nilai ke pemanggilnya. Ini membentuk suatu rantai pemanggilan fungsi yang terjadi secara berulang sampai solusi akhir ditemukan.

Dalam contoh code C++ yang telah Anda berikan sebelumnya, fungsi pangkat adalah contoh penggunaan fungsi rekursif. Pada setiap langkah rekursif, fungsi tersebut memecahkan masalah pemangkatan dengan cara memanggil dirinya sendiri hingga mencapai kondisi dasar (b <= 1) di mana fungsi berhenti memanggil dirinya sendiri dan mengembalikan nilai langsung.

**Contoh Kode** berikut merujuk pada kalimat:
- *Dengan menggunakan rekursif, anda dapat memanggil dirinya sendiri kemudian anda dapat memberikan kondisi.* 
- *Kondisi disini dibutuhkan untuk mencegah adanya kesalahan dalam perulanagan atau untuk menghentikan proses pemangilan dirinya sendiri.*

Berikut adalah demonstrasinya

```cpp
#include <iostream>
 // Fungsi untuk menghitung pangkat a^b secara rekursif
int pangkat(int a, int b)
{
    // Jika b lebih kecil atau sama dengan 1
    if (b <= 1)
    {
        // Kembalikan nilai a saja karena a pangkat 1 itu sama saja dengan a
        return a;
    }
    // Selain dari itu
    else
    {
        // a * fungsi pangkat (fungsi dirinya sendiri) dengan b dikurangi 1
        return a * pangkat(a, (b - 1));
    }
}

int main()
{
    // Inisialisasi nilai a dan b
    int a = 5, b = 2;
    int hasil;

    // Memanggil fungsi pangkat untuk menghitung a pangkat b
    hasil = pangkat(a, b);

    // Menampilkan hasil pangkat
    std::cout << "Hasil a dipangkat b : " << hasil << std::endl;

    return 0;
}
```
fungsi `pangkat` berfungsi untuk mencari hasil dari argument `a` dipangkat dengan argument `b` .

### Keuntungannya apa?
Penggunaan rekursif memiliki keuntungan seperti kode yang lebih ringkas, dibanding anda harus membuat 
kalkulasi atau perulangan yang lebih panjang dan tidak interaktif

**Contohnya** 
_Function_
```cpp
#include <iostream>

// Fungsi untuk menghitung pangkat a^b secara rekursif
int pangkat(int a, int b)
{
    // Jika b lebih kecil atau sama dengan 1
    if (b <= 1)
    {
        // Kembalikan nilai a saja karena a pangkat 1 itu sama saja dengan a
        return a;
    }
    // Selain dari itu
    else
    {
        // a * fungsi pangkat (fungsi dirinya sendiri) dengan b dikurangi 1
        return a * pangkat(a, (b - 1));
    }
}

int main()
{
    // Inisialisasi nilai a dan b
    int a = 5, b = 2;
    int hasil;

    // Memanggil fungsi pangkat untuk menghitung a pangkat b
    hasil = pangkat(a, b);

    // Menampilkan hasil pangkat
    std::cout << "Hasil a dipangkat b : " << hasil << std::endl;

    return 0;
}

```

**Contoh Tanpa Rekursif**

```cpp
// Fungsi untuk menghitung pangkat a pangkat b secara iteratif
int pangkat(int a, int b)
{
    int hasil = 1;

    // Loop sebanyak b kali
    for (int i = 0; i < b; ++i)
    {
        // Kalikan hasil dengan a pada setiap iterasi
        hasil *= a;
    }

    // Kembalikan hasil
    return hasil;
}

int main()
{
    // Inisialisasi nilai a dan b
    int a = 5, b = 2;
    int hasil;

    // Memanggil fungsi pangkat untuk menghitung a pangkat b
    hasil = pangkat(a, b);

    // Menampilkan hasil pangkat
    std::cout << "Hasil a dipangkat b : " << hasil << std::endl;

    return 0;
}
```

Jika tanpa rekursif seperti diatas, maka kalian harus menggunakan sebuah perulangan
untuk melakukan hal yang sama secara iteratif seperti contoh diatas.
