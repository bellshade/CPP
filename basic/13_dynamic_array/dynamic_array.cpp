#include <iostream>

int main(){
    int x, n;

    std::cout << "masukkan jumlah item: ";
    std::cin >> n;

    // membuat array dinammis
    int *arr = new int(n);

    // masukkan item pada array dinamis
    std::cout << n << " item" << std::endl;
    for(x = 0; x < n; x++){
        std::cin >> arr[x];
    }
    
    // tampilkan hasil
    std::cout << "kamu memasukkan: ";
    for (x = 0; x < n; x++){
        std::cout << arr[x];
    }

    return 0;
}