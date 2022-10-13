#include <iostream>

// membuat kelas persegi
class Persegi{
  // membuat akses
  // berupa publik sehingga bisa diakses
  // diluar kelas
  public:
    double panjang;
    double lebar;
};

int main(){
  // deklarasi objek baru dari kelas
  Persegi persegi1;
  Persegi persegi2;

  // membuat variabel hasil
  double hasil = 0.0;

  // mengisi value dari variabel
  // persegi1
  persegi1.panjang = 20;
  persegi1.lebar = 3;

  // mengisi value dari variabel
  // persegi2
  persegi2.panjang = 30;
  persegi2.lebar = 3;

  // menghitung hasil dari persegi1
  // dan menampilkan hasil
  hasil = persegi1.panjang * persegi1.lebar;
  std::cout << "hasil persegi1: " << hasil << std::endl;

  // menghitung hasil dari persegi2
  // dan menampilkan hasil
  hasil = persegi2.panjang * persegi2.lebar;
  std::cout << "hasil persegi2: " << hasil << std::endl;

  return 0;
}

