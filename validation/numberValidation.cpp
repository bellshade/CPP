#include <iostream>

int main() {
    int num;

    // Langkah 1 minta user untuk menginput angka
    std::cout << "Masukkan angka : ";

    /* Langkah 2 menerima inputnya dan cek jika
       yang dimasukkan adalah angka */
    if(!(std::cin >> num)){

        // Langkah 3 menjelaskan errornya
        std::cout << "Kesalahan, mohon masukkan angka.";

        // Langkah 4 membersihkan input sebelumnya
        std::cin.clear();

        // Langkah 5 menghapus input sebelumnya
        std::cin.ignore(123, '\n');

    } else {
        std::cout << "Angka yang anda masukkan adalah " << num;
    }
    return 0;
}
