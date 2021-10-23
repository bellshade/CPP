# CPP Multidimensional Array
Dalam bahasa pemrograman C++ diizinkan untuk menggunakan Multidimensional Array, Berikut cara mendeklarasikan Multidimensional Array:

```
tipe_data nama_array[size1][size2]...[sizeN];
```

Contohnya:
```cpp
int tiga_dimensi[4][8][2];
```

## Two-Dimensional Array
Sebagai contoh sederhana, kita akan membahas Array Multidimensional yang gampang, pada dasarnya _Two-Dimensional Array_ ini merupakan sebuah list/daftar dari array satu dimensi, Cara mendeklarasikannya sebagai berikut:
```
tipe_data nama_array[baris][kolom]
```

- **tipe_data** - Bisa berupa tipe data apapun yang valid dalam bahasa pemrograman C++.
- **nama_array** - Nama atau Identifier untuk variable.

Array dua dimensi ini bisa di imajinasikan sebagai tabel yang memiliki baris dan kolom, Berikut contoh jika:
```cpp
int duaDim[3][4];
```
Maka bisa di referensikan seperti:

(Foto disini gan)

## Menginisialisasi Two-Dimensional Array
Multidimesional Array bisa di inisialisasikan dengan menuliskan kurung kurawal `{ }` untuk tiap barisnya, Berikut merupakan array dengan 3 baris yang memiliki 4 kolom.
```cpp
 // duaDim[baris][kolom]
int duaDim[3][4] = {
    {0, 1, 2 ,3}, // Baris index 0
    {4, 5, 6, 7}, // Baris index 1
    {8, 9, 10, 11} // Baris index 2
};
```

Atau cara kedua yaitu:
```cpp
 // duaDim[baris][kolom]
int duaDim[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
// Baris akan dipisahkan ketika kolomnya telah tercapai yaitu 4
// Maka saat array mencapai angka 3 atau 7, index kolom akan diulang ke 0
```

## Mengakses Two-Dimensional Array
Elemen yang terdapat dalam array dua dimensi bisa di akses menggunakan index dari baris dan index kolomnya, Misalnya:
```cpp
int duaDim[3][4] = {
    {0, 1, 2 ,3},
    {4, 5, 6, 7},
    {8, 9, 10, 11}
};

int val = duaDim[2][1];
// Pada statement diatas elemen yang terdapat pada
// array baris kedua dan kolom pertama akan disimpan kedalam variable val
// maka, val = 9
```
Catatan: index selalu dimulai dengan 0.

## Contoh penggunaan: Menambah angka
```cpp
#include <iostream>

int main(){
    // Mendeklarasikan dan menginisialisasikan array dua dimensi
    int angka[4][2] = {
        {0, 1},
        {2, 3},
        {4, 5},
        {6, 7}
    };

    // Mendeklarasikan angka yang akan ditambah
    int val = 5;

    // Simpan angka yang akan digunakan untuk menambah
    int tambahkan = angka[1][0]; // tambahkan = 2;

    // Menghitung totalnya
    int total = val + tambahkan;

    std::cout << "Hasil dari " << val << "+" << tambahkan << " adalah " << total;
    /* Expected Output:
    "Hasil dari 5+2 adalah 7"
}
```