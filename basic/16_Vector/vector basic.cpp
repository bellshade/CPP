#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{

    // Deklarasi Vector
    std::vector <int> v;

    // Menginisialisasikan Vector dengan angka = 1, 2, 3
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    
    std::cout << "Nilai Awal: ";
    std::cout << v[0] << v[1] << v[2] << std::endl;
    
    return 0;
}
