#include <iostream>
#include <cstring>

void printKomputer(struct Komputer komputer);

struct Komputer {
  char pemilik[30];
  char tujuan[30];
  int  jumlah;
};

int main() {
  struct Komputer Komputer1;
  struct Komputer Komputer2;

  // menggunakan fungsi strcpy untuk mengisi value dari struct Kmomputer
  strcpy(Komputer1.pemilik, "James william");
  strcpy(Komputer1.tujuan, "Berlin");
  Komputer1.jumlah = 2;
  
  strcpy(Komputer2.pemilik, "Pace dean");
  strcpy(Komputer2.tujuan, "indonesia");
  Komputer2.jumlah = 4;

  // print struktur yang sudah dibuat
  printKomputer(Komputer1);
  
  printKomputer(Komputer2);

  return 0;
  
}

void printKomputer(const struct Komputer& komputer) {
  std::cout<<"pemilik :"<<komputer.pemilik<<std::endl;
  std::cout<<"tujuan :"<<komputer.tujuan<<std::endl;
  std::cout<<"jumlah :"<<komputer.jumlah<<std::endl;
}

