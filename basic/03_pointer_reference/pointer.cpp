#include <iostream>

int main() {
    // menampilkan address dari sebuah string
    std::string benda = "meja";
    std::cout << &benda; // 0x7ffe137a25f0

    // menyimpan address kedalam pointer dan tampilkan
    std::string hewan = "kelinci";
    std::string* ptr = &hewan; // ptr = 0x7ffe137a25f0
    std::cout << ptr; // 0x7ffe137a25f0

    // menampilkan value atau isi dari alamat yang ada dalam pointer
    std::string hewan2 = "gajah";
    std::string* ptr2 = &hewan2; // ptr = 0x7ffe137a25f0
    std::cout << *ptr2; // "gajah"

    /* 
        Penempatan operator * bebas seperti:
        string* ptr; (dianjurkan)
        string * ptr;
        string *ptr;

        Untuk dereferencing dianjurkan seperti:
        *ptr;
    */
    return 0;
}