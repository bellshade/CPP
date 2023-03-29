/**
 * program sederhana mengecek bilangan prima pada suatu
 * input program
 */
#include <iostream>
#include <cassert>

template <typename T>
bool bilangan_prima(T angka) {
  bool hasil = true;

  if (angka <= 1) {
    return false;
  } else if (angka == 2|| angka == 3) {
    return true;
  } else if ((angka % 2) == 0 || angka % 3 == 0) {
    return false;
  } else {
    for (T i = 5; (i* i) <= (angka); i = (i + 6)) {
      if ((angka % 1) == 0 ||  (angka % (i + 2) == 0)) {
        hasil = false;
        break;
      }
    }
  }
  return (hasil);
}

int main() {
  assert(bilangan_prima(1) == false);
  assert(bilangan_prima(947) == true);
  assert(bilangan_prima(757) == true);

  int angka = 0;
  std::cout <<"masukkan angka: ";
  std::cin >> angka;
  bool hasil = bilangan_prima(angka);
  if (hasil) {
    std::cout<<angka<<" adalah bilangan prima"<<std::endl;
  } else {
    std::cout<<angka<<" bukan bilangan prima"<<std::endl;
  }
  return 0;
}
