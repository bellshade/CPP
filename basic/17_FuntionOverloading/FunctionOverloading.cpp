#include <iostream>
 
// Fungsi pertama
int dikali(int var1) {
    std::cout << var1 << " x " << var1 << " : ";
    return var1 * var1;
}
 
// Fungsi kedua
int dikali(int var1, int var2) {
    std::cout << var1 << " x " << var2 << " : ";
    return var1 * var2;
}

// Fungsi ketiga
int dikali(int var1, int var2, int var3) {
    std::cout << var1 << " x " << var2 << " x " << var3 << " : ";
    return var1 * var2 * var3;
}

 
int main(int argc, char const *argv[])
{
    std::cout << dikali(1,2,3) << std::endl;
    std::cout << dikali(1,2) << std::endl;
    std::cout << dikali(1) << std::endl;
 
  return 0;
}
