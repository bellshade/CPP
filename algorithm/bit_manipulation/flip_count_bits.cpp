/**
 * diberi dua angka A dan B, kemudian hitung jumlah
 * bit yang perlu dibalik untuk mengubah A menjadi B
 *
 * contoh
 * A = 01010
 * B = 10100
 * bit A yang perlu dibalik adalah 10100
 * jika dibalik maka mendapatkan 10100, yaitu B
 *
 * time kompleksitas terburuk: O(log n)
 * space kompleksitas: O(1)
 */
#include <cassert>
#include <cstdint>
#include <iostream>

namespace bit_manipulation {

namespace flip_count_bits {

std::uint64_t countBitsFlip(std::int64_t A, std::int64_t B) {
    // variabel hitung untuk menghitung jumlah
    // flip bit
    // angka A danB dalam mempresentasikan biner dari
    // angka 'n'
    int hitung = 0;
    A = A ^ B;
    while (A) {
        A = A & (A - 1);
        hitung++;
    }
    return hitung;
}
} // namespace flip_count_bits
} // namespace bit_manipulation

/**
 * membuat fungsi untuk mengetes fungsi dari
 * flup_count_bits
 */
static void test() {
    // A = 10 B = 20
    // maka dengan ini mengembalikan 4
    assert(bit_manipulation::flip_count_bits::countBitsFlip(10, 20) == 4);
    // A= 11 B = 8
    // maka dengan ini mengembalikan 2
    assert(bit_manipulation::flip_count_bits::countBitsFlip(11, 8) == 2);
}

int main() {
    // memanggil fungsi test
    test();
    return 0;
}
