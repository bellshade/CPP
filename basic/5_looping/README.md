# Perulangan

Perulangan dilakukan ketika kamu ingin menjalankan sebuah blok secara berulang-ulang. Jika kamu ingin mencetak "Hello World" sebanyak 5 kali, kamu bisa menulisnya seperti berikut

```cpp
std::cout<<"Hello World"<<endl;
std::cout<<"Hello World"<<endl;
std::cout<<"Hello World"<<endl;
std::cout<<"Hello World"<<endl;
std::cout<<"Hello World"<<endl;
```

Akan tetapi, cara ini tidak mungkin digunakan jika harus mencetak sangat banyak. Karena itu, dibutuhkan sebuah perulangan agar kamu tidak perlu menuliskan code berulang-ulang.

## 1. For Loop

Perulangan dengan `for` biasanya digunakan ketika kita tahu berapa kali perulangan perlu dilakukan

```cpp
for (kondisi_awal; kondisi_ulang; perubahan) {
	// lakukan sesuatu
}
```

- `kondisi_awal`: dapat diisi dengan inisialisasi variabel untuk perulangan. Contoh: `int i=1`
- `kondisi_ulang`: biasanya berupa ekspresi yang menghasilkan `boolean`. Jika kondisi tidak terpenuhi, perulangan akan dihentikan. Contoh: `i <= 5`
- `perubahan`: bagian yang dieksekusi pada akhir setiap siklus perulangan. Contoh: `i++`

Catatan: Variabel yang dideklarasikan di dalam `for` (`kondisi_awal`) hanya bisa digunakan dalam blok `for` (variabel lokal).

Berikut cara menulis program sebelumnya menggunakan perulangan `for`:

```cpp
// mencetak "Hello World" sebanyak 5 kali
for (int i = 1; i <= 5; i++) {
	std::cout << "Hello World" << endl;
}
```

Penjelasan:

- Saat pertama kali dijalankan, `i` bernilai 1.
- Lalu program memeriksa apakah kondisi terpenuhi. (`i<=5`)
- Karena kondisi terpenuhi, program akan menjalankan code di dalam blok, yaitu mencetak "Hello World"
- Setelah sampai di akhir blok, program akan mengeksekusi bagian `perubahan`, yaitu menambah `i` dengan 1, lalu kembali ke awal dari `for`
- Program akan kembali melakukan pengecekan dan mengulangi langkah di atas sampai kondisi tidak terpenuhi.