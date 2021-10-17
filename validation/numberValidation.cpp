#include <iostream>
using namespace std;

int main() {
    int num;

    // Langkah 1 minta user untuk menginput angka
    cout << "Masukkan angka : ";

    /* Langkah 2 menerima inputnya dan cek jika
       yang dimasukkan adalah angka */
    if(!(cin >> num)){

        // Langkah 3 menjelaskan errornya
        cout << "Kesalahan, mohon masukkan angka.";

        // Langkah 4 membersihkan input sebelumnya
        cin.clear();

        // Langkah 5 menghapus input sebelumnya
        cin.ignore(123, '\n');

    } else {
        cout << "Angka yang anda masukkan adalah " << num;
    }
    return 0;
}