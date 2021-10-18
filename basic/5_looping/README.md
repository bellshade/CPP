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

## 2. While Loop
Perulangan `while` merupakan perulangan yang biasa digunakan apabila jumlah perulangannya belum diketahui. Proses perulangan akan terus berlanjut selama kondisinya bernilai benar (`true`) dan akan berhenti apabila kondisinya bernilai salah (`false`).

```cpp
kondisi_awal;
while (kondisi_ulang) {
	// lakukan sesuatu
	perubahan;
}
```

- `kondisi_awal`: dapat diisi dengan inisialisasi variabel untuk perulangan. Contoh: `int i=1`
- `kondisi_ulang`: biasanya berupa ekspresi yang menghasilkan `boolean`. Di bagian ini terdapat kondisi yang harus dipenuhi agar perulangan berjalan. Apabila kondisi tidak terpenuhi, perulangan akan dihentikan. Contoh: `i <= 5`
- `perubahan`: bagian yang dieksekusi pada akhir setiap siklus perulangan. Contoh: `i++`

Catatan : Perulangan `while` sangat berkaitan dengan variabel boolean karena penentuan kapan suatu blok kode akan diulang-ulang ditinjau dari (`true`) atau (`false`) dari suatu pernyataan logika pada `kondisi_ulang`. jika suatu kondisi itu selalu benar, maka perulangannya pun akan selalu dieksekusi.

Berikut cara menulis program sebelumnya menggunakan perulangan `while`:

```cpp
int i = 1; //kondisi_awal
while (i <= 5) { //kondisi_ulang
	// mencetak "Hello World" sebanyak 5 kali
	std::cout << "Hello World\n";
	
	i++; //perubahan
}
```

Penjelasan:

- Pertama, kita akan menginisialisasi variabel `i = 1`
- Kemudian, masuk kondisi while loop dengan `i` bernilai 1. 
- Lalu program memeriksa apakah kondisi terpenuhi. (`1 <= 5`)
- Karena kondisi terpenuhi, program akan menjalankan code di dalam blok dengan mencetak "Hello World"
- Kemudian di bagian `perubahan`, program juga akan menambah nilai variabel `i` dengan 1. Dengan demikian, nilai `i` sekarang menjadi 2
- Setelah sampai di akhir blok, program akan kembali ke awal dari `while`
- Program akan kembali melakukan pengecekan dan mengulangi langkah-langkah di atas sampai kondisi tidak terpenuhi.

## 3. Do While Loop
Perulangan ini mirip dengan While Loop pada dasarnya, tetapi perbedaannya `do while` ini menjalankan aksinya terlebih dahulu kemudian mengecek persyaratan Looping.

```cpp
kondisi_awal;
do {
	// Aksi
	perubahan;
} while(kondisi_ulang);
```

- `kondisi_awal`: dapat diisi dengan inisialisasi variabel untuk perulangan. Contoh: `int i=1`
- `kondisi_ulang`: biasanya berupa ekspresi yang menghasilkan `boolean`. Di bagian ini terdapat kondisi yang harus dipenuhi agar perulangan berjalan. Apabila kondisi tidak terpenuhi, perulangan akan dihentikan. Contoh: `i <= 5`
- `perubahan`: bagian yang dieksekusi pada akhir setiap siklus perulangan. Tapi berbeda dengan `do while`, perubahan di lakukan terlebih dahulu seblum `kondisi_ulang`. Contoh: `i++`

Catatan : Pada perulangan `do while` menjalankan aksinya terlebih dahulu jadi, meski persyaratan while adalah (`false`) aksi yang ada didalam `do` akan **berjalan setidaknya sekali** tanpa perlu memenuhi syarat while, jika kondisi while bernilai (`true`) maka aksi dalam `do` akan di selalu di jalankan/eksekusi.

Berikut cara menulis program sebelumnya menggunakan perulangan `do while`:

```cpp
int i = 1; // kondisi_awal
do {
	/* cetak "Hello World" sebanyak 1 + 4 kali
	mengapa sebanyak 1 + 4 kali?
	karena aksi pertama dijalankan tanpa persyaratan lalu melakukan perubahan dan kondisi_ulang
	*/
	std::cout << "Hello World\n";
	i++; // perubahan
} while (i <= 5); // kondisi_ulang
```

Penjelasan:

- Pertama, kita akan menginisialisasi variabel `i = 1`
- Kemudian, masuk kondisi do dengan `i` bernilai 1 dan melakukan aksinya tanpa persyaratan. 
- Lalu program memelakukan perubahan terhadap `i` yaitu menamah nilainya dengan 1. Dengan demikian, nilai `i` sekarang menadi 2. (`i++`)
- Kemudian program melakukan pengecekan terhadap variable `i` jika nilainya sama dengan dan kurang dari 5, lakukan aksi dalam `do`. (`i <= 5`)
- Karena kondisi terpenuhi, program akan menjalankan code di dalam blok dengan mencetak "Hello World"
- Setelah sampai di akhir blok `do`, program akan kembali melakukan pengecekan terhadap `while` dan mengulangi aksi dalam `do` sampai kondisi tidak terpenuhi.