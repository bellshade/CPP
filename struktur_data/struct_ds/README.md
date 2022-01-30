# struct

struct atau struktur adalah tipe data yang ditentukan oleh pengguna dalma C/C++. strutur membuat tipe data yang dapat digunakan untuk mengelompokkan item dari tipe yang mungkin berbeda ke dalam satu tipe data lain.

## mendifinisikan struct

untuk mendifinisikan struktur, kita harus menggunakan pernyataan ``struct``.

```
struct nama_strukture {
  tipe1;
  tipe2;
  tipe3;
}
```

struktur dalam C++ dapat berisi dua jenis anggota

- anggota data
  
  anggota ini adalah variabel C++ normal. kita dapat membuat struktur dengan variabel dari tipe data yang berbeda di C++

- fungsi anggota

  anggota ini adalah fungsi C++ normal. seiring dengan variabel, kita juga dapat memasukkan fungsi di dalam deklarasi struktur.

```cpp
struct Kendaraan {
  char merek[50];
  char pemilik[50];
  int nomor_mesin;
} kendaraan;
```

## mengakses anggota struct

untuk mengakses setiap anggota struktur, kita menggunakan operator akses ``.`` . operator akses anggota dikodekan sebagai periode antara nama variabel struktur dan anggota struktur yang ingin kita akses. kita akan menggunakan kata kunci ``struct`` untuk mendifinisikan variabel tipe struktur.

```cpp
#include <iostream>
#include <cstring>

struct Kendaraan {
  char merk[20];
  char pemilik[50];
  int nomor_mesin;
};

int main() {
  struct Kendaraan Kendaraan1;
  struct Kendaraan Kendaraan2;

  strcpy(Kendaraan1.merk, "BMW");
  strcpy(Kendaraan1.pemilik, "Arthur");
  Kendaraan1.nomor_mesin = 4124;

  strcpy(Kendaraan2.merk, "Jaguar");
  strcpy(Kendaraan2.pemilik, "Anne");
  Kendaraan2.nomor_mesin = 4421;
  
  std::cout<<"pemilik kendaraan 1 :"<<Kendaraan1.pemilik<<std::endl;
  std::cout<<"merk kendaraan 1 :"<<Kendaran1.merk<<std::endl;
  std::cout<<"nomor mesin :"<<Kendaraan1.nomor_mesin<<std::endl;

  std::cout<<"pemilik kendaraan 2 :"<<Kendaraan2.pemilik<<std::endl;
  std::cout<<"merk kendaraan 2 :"<<Kendaraan2.merk<<std::endl;
  std::cout<<"nomor mesin :"<<Kendaraan2.nomor_mesin<<std::endl;

  return 0;
}
```

## struktur sebagai argumen fungsi

kita dapat meneruskan struktur sebagai argumen fungsi dengan cara yang sangat mirip saat kita meneruskan variabel atau penunjuk lainnya. kita akan mengakses variabel struktur dengan cara yang sama seperti yang anda akses pada contoh diatas

```cpp
#include <iostream>
#include <cstring>

void printKomputer(struct Komputer komputer);

struct Komputer {
  char pemilik[40];
  char tujuan_kirim[40];
  int jumlah;
};

int main() {
  struct Komputer Komputer1;
  struct Komputer Komputer2;

  strcpy(Komputer1.pemilik, "James arthur");
  strcpy(Komputer1.tujuan_kirim, "California");
  Komputer1.jumlah = 4;

  strcpy(Komputer2.pemilik, "Anne marie");
  strcpy(Komputer2.tujuan_kirim, "New york");
  Komputer1.jumlah = 5;

  printKomputer(Komputer1);
  
  printKomputer(Komputer2);
}

void printKomputer(struct Komputer komputer) {
  std::cout<<"pemilik :"<<komputer.pemilik<<std::endl;
  std::cout<<"tujuan kirim :"<<komputer.tujuan_kirim<<std::endl;
  std::cout<<"jumlah :"<<komputer.jumlah<<std::endl;
}
```

## pointer ke struktur

kita dapat mendifinisikan pointer ke struktur dengan cara yang sangat mirip seperti kita mendifinisikan pointer ke variabel lain sebagai berikut

```
struct Kendaraan *pointer_struktur;
```

sekarang kita dapat menyimpan alamt variabel struktur dalam variabel penunjuk yang ditentukan di atas. untuk menemukan alamat variabel struktur, tempatkan operator ``&`` sebelum nama struktur sebagai verikut

```
struct_pointer = &kendaraan;
```

untuk mengakses anggota struktur menggunakan pointer ke struktur itu, kita harus menggunakan operator ``->`` sebagai berikut

```
struct_pointer -> title_struct;
```

contoh

```cpp
#include <iostream>
#include <cstring>

void printKendaraan(struct Kendaraan *kendaraan);

struct Kendaraan {
  char merk[30];
  char pemilik[30];
  int nomor_mesin;
};

int main() {
  struct Kendaraan kendaraan1;
  struct Kendaraan kendaraan2;

  strcpy(Kendaraan1.pemilik, "Bill gates");
  strcpy(Kendaraan1.merk, "Harley");
  Kendaraan1.nomor_mesin = 4481;

  strcpy(Kendaraan2.pemilik, "Jeff bezos");
  strcpy(Kendaraan2.merk, "BMW");
  kendaraan2.nomor_mesin = 7125;

  printKendaraan(&Kendaaran1);
  
  printKendaraan(&Kendaraan2);

  return 0;

}

void printKendaraan(struct Kendaraan *kendaraan) {
  std::cout<<"merk kendaraan :"<<kendaraan -> merk<<std::endl;
  std::cout<<"pemilik :"<<kendaraan -> pemilik<<std::endl;
  std::cout<<"nomor mesin :"<<kendaraan -> nomor_mesin<<std::endl;
}

```

## kata kunci typedef

ada cara lebih mudah utuk mendifinisikan struct ata kita bisa "alias" jenis yang kita buat. misalnya

```cpp
typedef struct {
  char merk[30];
  char pemilik[20];
  int nomor_mesin;
} Kendaraan;
```

sekarang, kita dapat menggunakan _kendaraan_ secara langsung untuk menentukan variabel tipe kendaraan tanpa menggunakan kata kuncu struct. contoh

```
Kendaraan Kendaraan1, Kendaraan2;
```

kita dapat menggunakan kata kunci ``typedef`` untuk non-struct serta sebagai berikut

```cpp
typedef long int *pint32;

pint32 x, y, z;
```

