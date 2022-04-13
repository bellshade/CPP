#include <iostream>

class KelasSaya {
    public:
        void metodeSaya() {
            std::cout<<"bellshade";
        }
};

int main() {
    // membuat object dari kelas
    KelasSaya objectSaya;
    
    // memanggil method
    objectSaya.metodeSaya();
    
    return 0;
}