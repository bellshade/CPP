#include<iostream>


/**
 * @file relu.cpp
 * @brief program ini untuk menghitung
 * Relu yang merupakan salah satu dari fungsi aktivasi
 * yang digunakan pada project Machine Learning dan Deep Learning
 * cara kerja ini mengambil nilai 0 apabila input nilai
 * kurang dari sama dengan 0
*/
float relu(float n){
    /**
     * @brief Fungsi Relu untuk mengfilter inputnya
     * yang mana yang nilai lebih dari 0.0 dan mana yang
     * kurang dari 0.0
     * @param n ini merupakan variabel input nilai
    */

    // ini kondisi untuk mengfilter inputnya
    if (n > 0.0){
        return n;
    }else{
        return 0.0;
    }
}

int main(){
    // mari kita ujikan dengan lebih dari 0;
    std::cout<<relu(12.12)<<'\n';
    // mari kita uji dengan kurang dari 0
    std::cout<<relu(-1.12)<<'\n';
    // mari kita uji dengan 0
    std::cout<<relu(0.0)<<'\n';
    return 0;
}