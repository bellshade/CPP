#include <cassert>
#include <iostream>

/**
 * Program sederhana untuk mengecek faktorial
 * Rumusnya adalah
 * n! = n *(n - 1)
 * Contoh sederhana
 * 5! = 5 x 4 x 3 x 2 x 1 = 120
*/

/**
 * Fungsi ``adalah_faktorial``
 * @param n angka faktorial yang ingin di cek
 * @return jika faktorial maka kembali nilai true
*/
bool adalah_faktorial(uint64_t n) {
    if (n <= 0) {
        return false;
    }
    for (uint32_t i = 1;; i++) {
        if (n % i != 0) {
            break;
        }
        n = n / i;
    }
    if (n == 1) {
        return true;
    } else {
        return false;
    }
}

void test() {
    /**
     * Fungsi ini adalah untuk mengetes hasil dari
     * fungsi ``adalah_faktorial()``
    */
    std::cout<<"test, angka = 50\n";
    assert(adalah_faktorial(50) == false);
    std::cout<<"pass\n";

    std::cout<<"test, angka = 479001600\n";
    assert(adalah_faktorial(479001600) == true);
    std::cout<<"pass\n";
}

int main() {
    test();
    return 0;
}

