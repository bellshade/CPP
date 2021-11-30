#include <iostream>

class Pelajar{
    // membuat akses ke atribut
    public:
        int id_mhs;
        void detail_mhs(){
            // membuat fungsi yang akan menampilkan detail pelajar
            std::cout << "ID: " << id_mhs << std::endl;
        }
};

int main(){
    // memanggil kelas dan menjadikan sebagai objek
    Pelajar mhs1;
    Pelajar mhs2;

    // membuat akses ke atribut
    mhs1.id_mhs = 1;
    mhs2.id_mhs = 2;

    // memanggil fungsi
    mhs1.detail_mhs();
    mhs2.detail_mhs();
}