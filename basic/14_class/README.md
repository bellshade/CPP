# kelas dan objek

Tujuan utama dari pemograman c++ adalah untuk menambahkan orientasi objek ke bahasa pemograman C dan kelas adalah fitur utama dari C++ yang mendukung pemograman berorientasi objek dan dsering disebut tipe yang ditentukan pengguna.

kelas digunakan untuk menetukan objek dan menggabungkan representasi data dan metode untuk memanipulasi data tersebut menjadi paket yang rapi. Data dan fungsi di dalam kelas disebut anggota kelas.

## definisi kelas c++

saat anda mendifinisikan kelas, kita dapat mendifinisikan cetak biru untuk tipe data. ini tidak benar mendifinisikan data apapun, tetapi mendifinisikan apa arti nama kelas, yaitu, apa yang akan terdiri dari objek kelas dan operasi apa yang dapat dilakukan pada objek semacam itu.

Definisi kelas dimulai dengan kata kunci kelas diikuti dengan nama kelas; dan badan kelas, diapit oleh sepasang kurung kurawal. Definisi kelas harus diikuti dengan titik koma atau daftar deklarasi. Sebagai contoh, kita mendefinisikan tipe data Box menggunakan kelas kata kunci sebagai berikut

```cpp
class Persegi{
  public:
    double panjang;
    double lebar;
};
```

## mengakses data anggota

Anggota data publik dari objek suatu kelas dapat diakses menggunakan oeprator akses anggota langsung ``(.)``. contoh

```cpp
#include <iostream>

class Persegi{
  // membuat akses publik sehingga
  // bisa diakses diluar persegi
  public:
    double panjang;
    double lebar;
};

int main(){
  // memanggil kelas Persegi
  Persegi persegi1;
  // membuat variabel hasil
  double hasil;

  // akses ke objek variabel tertentu
  // dan memberi value
  persegi1.panjang = 12;
  persegi1.lebar = 13;

  // menghitung hasil dari kedua variabel
  volume = persegi1.panjang * persegi1.lebar;

  // menampilkan hasil persegi
  std::cout<<"hasil dari hitung persegi panjang"<<std::endl;
  std::cout<<volume;

  return 0;
}
```
