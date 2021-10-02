# cpp variabel
variabel dalah sebuah kontainer yang berfungsi dalam penyimpanan value sehingga dapat digunakan secara berulang kali

## deklarasi variabel
cpp menggunakan camelCase untuk sebuah penamaan pada variabel sperti contoh

```cpp
int AngkaSaya = 15;
cout<<AngkaSaya;
```
atau bisa juga dengan tidak assign operatornya terlebih dahulu
```cpp
int AngkaSaya
AngkaSaya = 15;
cout<<AngkaSaya;
```

## menampilkan variabel
menampilkan variabel bisa menggunakan dengan cara menambahkan lagi operator ``<<`` seperti contoh dibawah ini
```cpp
int AngkaSaya = 30;
cout<<"Angka Saya adalah "<<AngkaSaya;
```
kita juga bisa menggatikan valua yang sebelumnya sudah terdapat pada variabel dengan cara
```cpp
int AngkaSaya = 1;
AngkaSaya = 30;
cout<<"angka saya sekarang adalah "<<AngkaSaya;
```
maka otomatis variabel yang ingin digantikan akan terganti dengan value yang sebelumnya sudah kita tambahkan

