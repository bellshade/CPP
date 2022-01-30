#include <iostream>
#include <cstring>

struct Kendaraan {
  char merk[40];
  char pemilik[30];
  int nomor_mesin;
};

int main(){
  // membuat struct baru untuk memanggil struct Kendaraan
  struct Kendaraan Kendaraan1;
  struct Kendaraan Kendaraan2;

  // menggunakan fungsi strcpy untuk mengisi value dari tiap
  // attribut pada stuktur
  strcpy(Kendaraan1.merk, "BMW");
  strcpy(Kendaraan1.pemilik, "James arthur");
  Kendaraan1.nomor_mesin = 7261;
  
  // mengisi value dari tiap attribut pada Kendaraan2
  strcpy(Kendaraan2.merk, "Jaguar");
  strcpy(Kendaraan2.pemilik, "Bill foster");
  Kendaraan2.nomor_mesin = 9281;

  // print dari kedua struktur yang sudah di deklarasikan
  std::cout<<"merk kendaraan 1 :"<<Kendaraan1.merk<<std::endl;
  std::cout<<"pemilik :"<<Kendaraan1.pemilik<<std::endl;
  std::cout<<"nomor mesin :"<<Kendaraan1.nomor_mesin<<std::endl;

  std::cout<<"pemilik kendaraan 2 :"<<Kendaraan2.merk<<std::endl;
  std::cout<<"pemilik :"<<Kendaraan2.pemilik<<std::endl;
  std::cout<<"nomor mesin :"<<Kendaraan2.nomor_mesin<<std::endl;

  return 0;
}
