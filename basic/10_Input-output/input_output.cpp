#include <iostream>

int main(){
    // deklarasi variabel
    char nama_hewan[20];
    std::cout << "Nama hewan: ";

    // deklarasi input stream
    std::cin >> nama_hewan;
    // menampilkan output
    std::cout << "Nama hewan: " << nama_hewan << std::endl;

    return 0;
}