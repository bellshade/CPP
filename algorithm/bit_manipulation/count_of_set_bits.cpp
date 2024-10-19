/**
 * @file count_of_set_bits.cpp
 * @details Count of set bits
 * diberikan angka integer. kemudian kalkulasi angka dari bits
 */

#include <cassert>
#include <cstdint>

namespace bit_manipulation{
    namespace count_of_set_bits{
        std::uint64_t countSetbits(std::int64_t n){
            int count = 0;
            while (n != 0){
                ++count;
                n = (n & (n - 1));
            }
            return count;
        }
    }
}

static void test(){
    assert(bit_manipulation::count_of_set_bits::countSetbits(4) == 1);
}

int main(){
    test();
    
    return 0;
}
