#include <iostream>

extern int getVar(); // deklarasi, memberitahu compiler bahwa fungsi ini di definisikan di file lain
                     
int var = 10; // intsialisasi global variable (real)

int main () {
  std::cout << "Nilai variable dengan name 'var': ";
  std::cout << var << std::endl;
  std::cout << "Nilai variable dengan name 'var' di file lain: ";
  std::cout << getVar() << std::endl;  // tidak bisa akses secara langsung variable `var` 
                                       // di file lain karena ekslusif untuk file tersebut saja
}
