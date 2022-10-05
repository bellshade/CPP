#include <iostream>
#include <vector>

void loop(std::vector <int> parameter){
    // Membaca nilai vector dari awal - akhir
    for(int i = 0; i < parameter.size(); i++){
        std::cout << parameter[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    // Penjabaran: vector <tipe_data> nama_variabel

    // Deklarasi Vector
    std::vector <int> v;

    // Menginisialisasikan Vector dengan angka = 1, 2, 3
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::cout << "Nilai Awal: ";
    // Memanggil Fungsi looping
    loop(v);
    
    // Index Vector 1 (2) akan di hapus
    // dan digantikan posisinya dengan Index Vector 2 (3)
    v.erase(v.begin() + 1, v.begin() + 2);
    std::cout << "Nilai Baru: ";
    loop(v);
    
    return 0;
}
