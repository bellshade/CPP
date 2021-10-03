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

## 2.  While

Perulangan dengan `while` biasanya digunakan untuk melakukan proses perulangan yang belum diketahui jumlahnya. Untuk pengecekan kondisi akan dilakukan terlebih dahulu, jika kondisi masih bernilai true, maka proses perulangan akan terus berlanjut. Berbeda dengan perulangan `for` yang dapat mengetahui jumlah dari proses perulangannya.

```cpp
while (kondisi){
    // lakukan sesuatu
}
```

- `kondisi`: dapat diisi dengan inisialisasi suatu kondisi.

Berikut cara menulis program menggunakan perulangan `while`:

```cpp
// mencetak "Hello World" sebanyak 5 kali
int i=1;
while (i<=5) {
	std::cout << "Hello World"<< endl;
	i++;
}
```

Penjelasan:
- Saat pertama kali meinisialisasi nilai awal dari variabel i `int i=1`
- Lalu program memeriksa apakah nilai dari variabel `i<=5` ? Jika nilainya benar maka akan dicetak kalimat "Hello World"
- Setelah sampai di akhir blok, program akan mengeksekusi bagian `perubahan`, yaitu menambah `i` dengan 1, lalu kembali ke awal dari `while`
- Program akan kembali melakukan pengecekan lagi apakah kondisi variabel i, apakah masih memiliki nilai `<=5` jika kondisi niali dari variabel i bernilai benar, maka kalimat akan trus dicetak kalimat "Hello World", hingga nilai variabel i lebih dari 5. maka kondisi bernilai false dan perulangan while akan berhenti.


