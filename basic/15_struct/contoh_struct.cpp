#include <iostream>

struct Struct_saya{
    int angka_saya = 10;
    int angka_saya2 = 20;
};

int main(){
    Struct_saya objek_saya;
    
    std::cout<<"angka pertama "<<objek_saya.angka_saya<<std::endl;
    std::cout<<"angka kedua "<<objek_saya.angka_saya2<<std::endl;
}
