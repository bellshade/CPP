#include <iostream>
#include <cstring>

void printBuku(struct Buku *buku);

struct Buku {
  char judul[30];
  char penulis[20];
  int id_buku;
};

int main() {
  struct Buku Buku1;
  struct Buku Buku2;

  // menggunakan strcpy untuk mengisi value dari struktur
  strcpy(Buku1.judul, "habis gelap terbitlah terang");
  strcpy(Buku1.penulis, "R.A Kartini");
  Buku1.id_buku = 82910;

  strcpy(Buku2.judul, "Konsep Healing");
  strcpy(Buku2.penulis, "levi ackerman");
  Buku2.id_buku = 92817;

  // print
  printBuku(&Buku1);
  
  printBuku(&Buku2);

  return 0;

}

void printBuku(struct Buku *buku) {
  std::cout<<"judul :"<<buku -> judul<<std::endl;
  std::cout<<"penulis :"<<buku -> penulis<<std::endl;
  std::cout<<"id buku :"<<buku -> id_buku<<std::endl;
}

