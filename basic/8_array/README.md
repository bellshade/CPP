# cpp array
arraydigunakan untuk menyimpan dan menghasilkan beberapa atau banyak value dalam satu variabel, untuk mendkalarasikan array, deklarasikan berupa tipe data dari array, nama variabel dari array, dan jumlah value yang diinginkan yang dimasukkan di dalam tutup kurung kotak ``[]``, contoh

```cpp
string nama_siswa[5];
```
contoh deklarasi value dari array
```cpp
string nama_siswa[3] = {"erik", "mark", "spencer"};
```
kita bisa mengakses element pada array seperti pada contoh dibawah ini
```cpp
string nama_siswa[3] = {"erik", "mark", "spencer"};
std::cout<<nama_siswa[0];
```
pada penjelasan diatas kita mengakses element pertama dari siswa yaitu ``erik``, array dimulai dari index 0 dan kemudian berlanjut ``0 1 2...n``

kita juga bisa mengubah value dari element tersebut dengan cara memilih elemen yang ingin kita ubah dan menggantinya dengan yang sesuai
```cpp
string nama_siswa[3] = {"erik", "mark", "spencer"};
nama_siswa[1] = "james";
std::cout<<nama_siswa[1];
```
contoh pada value integer
```cpp
int nilai_siswa[3] = {90, 50, 70};
std::cout<<nilai_siswa[2];
```

## memanggil array
kita bisa memanggil semua value dari array dengan cara menggunakan looping sebagai contoh
```cpp
string nama_siswa[3] = {"erik", "mark", "spencer"};
for (int i = 0; i<3; i++){
    std::cout<<nama_siswa[i]<<"\n";
}
```
pada penjelasan diatas, perulangan diulang sebanyak 3 kali dimana sesuai denagan jumlah element dari array, kemudian menampilkan output dari nama siswa dari perulangan tersebut sehingga mengeluarkan output
```
erik
mark
spencer
```

contoh lain
```cpp
string nama_siswa[3] = {"erik", "mark", "spencer"};
for (int i = 0; i<3; i++){
    std::cout<<i[nama_siswa]<<"\n";
}
```