/**
 * @brief hamming distance
 * penjelasan lebih lanjut tentang hamming distance
 * https://en.wikipedia.org/wiki/Hamming_distance
 */

#include <cassert>
#include <iostream>

namespace bit_manipulation{
    /**
     * @namespace hamming_distance
     * @brief fungsi utama dari implementasi
     * hamming distance
     * 
     */
    namespace hamming_distance{
        /**
         * @param nilai jumlah yang ingin dihitung 
         * jumlah bit yang ditetapkan
         * @return jumlah bit yang ditetapkan dalam nomor
         * yang diberikan
         */
        uint64_t bitCount(uint64_t value){
            uint64_t count = 0;
            while (value){
                // mengecek bit terendah
                if (value & 1){
                    count++;
                }
                // menghapus bit terendah
                value >>= 1;
            }
            return count;
        }

        /**
         * fungsi ini mengembalikan jarak hamming antara
         * dua bilangan bulat
         * @param a bilangan pertama
         * @param b bilangan kedua
         * @return jarak hamming antara a dan b
         */
        uint64_t hamming_distance(uint64_t a, uint64_t b){
            return bitCount(a ^ b);
        }

        /**
         * fungsi ini mengembalikan jarak hamming antara dua string
         * @param a string pertama
         * @param b string kedua
         * @return jarak hamming antara a dan b
         */
        uint64_t hamming_distance(const std::string& a, const std::string& b){
            assert(a.size() == b.size());
            size_t n = a.size();
            uint64_t count = 0;
            for (size_t i = 0; i < n; i++){
                count += (b[i] != a[i]);
            }
            return count;
        }
    }
        
}

static void test(){
    assert(bit_manipulation::hamming_distance::hamming_distance(11, 2) == 2);
}

int main(){
    test();
    uint64_t a = 11;
    uint64_t b = 200;

    std::cout<<bit_manipulation::hamming_distance::hamming_distance(a, b)<<std::endl;

    return 0;
}
