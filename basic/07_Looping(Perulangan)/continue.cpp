#include <iostream>

int main(){
    // membuat perulangan dengan value i
    // dari 0 sampai dengan 50
    for(int i = 0; i < 50; i++){
        // jika i adalah 20
        if (i == 20){
            // maka akan melewati angka 20
            continue;
        }
        // menampilkan i
        // atau hasil perulangan
        std::cout << i << "\n";
    }
    return 0;
}