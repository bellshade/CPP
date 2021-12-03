#include <iostream>

class Tambah{
    // akses kelas
    public:
        // konstruktor
        Tambah(int i = 0){
            total = i;
        }

        // interface untuk diluar
        void tambahAngka(int angka){
            total += angka;
        }
        
        // interface untuk diluar
        int getTotal(){
            return total;
        };

    // akses kelas
    private:
        // data yang tidak bisa
        // diakses
        int total;
};

int main(){
    Tambah a;

    a.tambahAngka(10);
    a.tambahAngka(12);

    std::cout<<"total "<<a.getTotal()<<std::endl;

    return 0;
}