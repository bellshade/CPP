# Perulangan

Perulangan dilakukan ketika kamu ingin menjalankan sebuah blok secara berulang-ulang. Jika kamu ingin mencetak "Hello World" sebanyak 5 kali, kamu bisa menulisnya seperti berikut

```cpp
std::cout << "Hello World" << std::endl;
std::cout << "Hello World" << std::endl;
std::cout << "Hello World" << std::endl;
std::cout << "Hello World" << std::endl;
std::cout << "Hello World" << std::endl;
```

Akan tetapi, cara ini tidak mungkin digunakan jika harus mencetak sangat banyak. Karena itu, dibutuhkan sebuah perulangan agar kamu tidak perlu menuliskan code berulang-ulang.

## 1. For Loop

Perulangan dengan `for` biasanya digunakan ketika kita tahu berapa kali perulangan perlu dilakukan

```cpp
for (<kondisi_awal>; <kondisi_ulang>; <perubahan>) {
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
	std::cout << "Hello World" << std::endl;
}
```

Penjelasan:

- Saat pertama kali dijalankan, `i` bernilai 1.
- Lalu program memeriksa apakah kondisi terpenuhi. (`i<=5`)
- Karena kondisi terpenuhi, program akan menjalankan code di dalam blok, yaitu mencetak "Hello World"
- Setelah sampai di akhir blok, program akan mengeksekusi bagian `perubahan`, yaitu menambah `i` dengan 1, lalu kembali ke awal dari `for`
- Program akan kembali melakukan pengecekan dan mengulangi langkah di atas sampai kondisi tidak terpenuhi.

Contoh lebih lanjut dari operator ``for loop`` bisa dilihat di [Kelas terbuka - For Loop](https://www.youtube.com/watch?v=ZeqJewFm7zc&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=26)

## 2. While Loop
Perulangan `while` merupakan perulangan yang biasa digunakan apabila jumlah perulangannya belum diketahui. Proses perulangan akan terus berlanjut selama kondisinya bernilai benar (`true`) dan akan berhenti apabila kondisinya bernilai salah (`false`).

```cpp
<kondisi_awal>;
while (kondisi_ulang) {
	// lakukan sesuatu
	<perubahan>;
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
	std::cout << "Hello World" << std::endl;
	
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

Contoh lebih lanjut dari opeartor ``while loop`` bisa dilihat [Kelas Terbuka - While Loop](https://www.youtube.com/watch?v=Pzy3XWzORNw&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=25)

## 3. Do While Loop
Perulangan ini mirip dengan While Loop pada dasarnya. Perbedaannya, `do while` menjalankan aksinya terlebih dahulu kemudian mengecek persyaratan Looping.

```cpp
<kondisi_awal>;
do {
	// lakukan sesuatu
	<perubahan>;
} while(kondisi_ulang);
```

- `kondisi_awal`: dapat diisi dengan inisialisasi variabel untuk perulangan. Contoh: `int i=1`
- `kondisi_ulang`: biasanya berupa ekspresi yang menghasilkan `boolean`. Di bagian ini terdapat kondisi yang harus dipenuhi agar perulangan berjalan. Apabila kondisi tidak terpenuhi, perulangan akan dihentikan. Contoh: `i <= 5`
- `perubahan`: bagian yang dieksekusi pada akhir setiap siklus perulangan. Contoh: `i++`

Catatan: Pada perulangan `do while` aksi dijalankan terlebih dahulu. Jadi, meski persyaratan while bernilai `false` aksi yang ada di dalam `do` akan **berjalan setidaknya sekali** tanpa perlu memenuhi syarat while. Jika kondisi while bernilai `true`, maka aksi dalam `do` akan selalu dijalankan/dieksekusi.

Berikut cara menulis program sebelumnya menggunakan perulangan `do while`:

```cpp
int i = 1; // kondisi_awal
do {
	/* cetak "Hello World" sebanyak 1 + 4 kali
	mengapa sebanyak 1 + 4 kali?
	karena aksi pertama dijalankan tanpa persyaratan lalu melakukan perubahan dan kondisi_ulang
	*/
	std::cout << "Hello World" << std::endl;
	i++; // perubahan
} while (i <= 5); // kondisi_ulang
```

Penjelasan:

- Pertama, kita akan menginisialisasi variabel `i = 1`
- Kemudian, masuk kondisi `do` dengan `i` bernilai 1 dan melakukan aksinya tanpa persyaratan.
- Lalu program memelakukan perubahan terhadap `i` yaitu menamah nilainya dengan 1. Dengan demikian, nilai `i` sekarang menadi 2. (`i++`)
- Kemudian program melakukan pengecekan terhadap variable `i` jika nilainya sama dengan dan kurang dari 5, lakukan aksi dalam `do`. (`i <= 5`)
- Karena kondisi terpenuhi, program akan menjalankan code di dalam blok dengan mencetak "Hello World"
- Setelah sampai di akhir blok `do`, program akan kembali melakukan pengecekan terhadap `while` dan mengulangi aksi dalam `do` sampai kondisi tidak terpenuhi.

Contoh lebih lanjut dari operator ``do while`` bisa dilihat [Kelas Terbuka - Do While](https://www.youtube.com/watch?v=Pzy3XWzORNw&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=25)

## Keyword Spesial dalam Perulangan

### Break
break adalah statement dimana, digunakan untuk memberhentikan jika value dari looping sudah terpenuhi.

contoh
```cpp
for (int i = 0; i < 50; i++){
    if(i == 20){
        break
    }
    std::cout << i << "\n";
}
```
pada penjelasan diatas variabel ``i`` yang semula 0 akan bertambah berulang ``0 ke 49``, tetapi disini memliki kondisi dimana jika value dari i sudah mencapai 20 (``0 ke 19``) maka looping akan memberhentikan prosesnya


### Continue
continue adalah statement dimana, digunakan untuk melewati value yang spesifik dimana yang sudah dideklarasikan dalam sebuah kondisi.

contoh

```cpp
for (int i = 0; i < 50; i++){
    if(i == 20){
        continue;
    }
    std::cout << i << "\n";
}
```
pada penjelasan diatas variabel ``i`` yang semula 0 akan bertambah berulang ``0 ke 49``, tetapi disini memliki kondisi dimana jika value dari i sudah mencapai 20 (``0 ke 19``) maka value yang ``20`` akan dilewati
```
18
19
21
22
23
```

# FYI (For Your Information) / Reference
1. Contoh lebih lanjut dari operator ``for loop`` bisa dilihat di [Kelas terbuka - For Loop](https://www.youtube.com/watch?v=ZeqJewFm7zc&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=26)

2. Contoh lebih lanjut dari opeartor ``while loop`` bisa dilihat [Kelas Terbuka - While Loop](https://www.youtube.com/watch?v=Pzy3XWzORNw&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=25)

3. Contoh lebih lanjut dari operator ``do while`` bisa dilihat [Kelas Terbuka - Do While](https://www.youtube.com/watch?v=Pzy3XWzORNw&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=25)