#include <iostream>
#include <vector>

void loop(std::vector <int> parameter){
    std::cout << "\nData Vector berisikan: ";
    for(int i = 0; i < parameter.size(); i++){
        std::cout << "[" << parameter[i] << "] ";
    }
}

int main()
{
    // Deklarasi Vector
    std::vector <int> v;

    // 1. push_back
    // Menginisialisasikan Vector dengan angka = 1, 2, 3
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    loop(v);

    // 2. pop_back
    v.pop_back();
    loop(v);

    // 3. at
    std::cout << "\nNilai pencarian: [" << v.at(1) << "]";

    v.at(1) = 3;
    loop(v);

    // 4. clear
    v.clear();
    loop(v);
    
    return 0;
}
