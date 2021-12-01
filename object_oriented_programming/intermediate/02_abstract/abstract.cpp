#include <iostrea>

class Tambah{
    public:
        // membuat konstruktor
        Tambah(int i = 0){
            total = i;
        }

        // interface dari luar
        void tambahAngka(int angka){
            total += angka;
        }

        int getTotal(){
            return total;
        }
    
    private:
        // membuat data yang bersifat non publik
        int total;
};

int main(){
    // memanggil kelas
    // dan membuat objek baru
    Adder a;
    
    // memanggil fungsi tambah angka
    a.tambahAngka(2);
    a.tambahAngka(3);
    a.tambahAngka(5);
    
    std::cout<<"total "<<a.getTotal()<<std::endl;

    return 0;
}