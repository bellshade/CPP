#include<iostream>
#include<cmath>
#include<vector>


/**
 * @file cos.cpp
 * @brief fungsi untuk mengetahui Cos nilai output dengan
 * menggunakan algoritma
*/


int factorial(int n){
    if (n<0){
        throw std::invalid_argument("Angka faktorial harus real");
    }
    else if (n==0 or n==1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}


/**
 * @brief fungsi untuk mengetahui nilai cosinus pada titik
 * dengan menggunakan algoritma taylor series
 * @param sudut merupakan titik input untuk mengetahui
 *              nilai cos dari titik tersebut
 * @param iterable merupakan jumlah perulangan perjumlah yang dilakukan
 *                 default 4
 * @return hasilnya berupa angka decimal
*/


template <typename T> double cosinus(T sudut,int iterable=4){

    float result = 0.0;
    for (int n = 0; n <= iterable; ++n){
        numerator = pow(-1,n) * pow(sudut,2*n);
        denumerator = factorial(2*n);
        result +=(numerator/denumerator); 
    }
    return result;
}


int main(){
    // testing
    std::vector<double> list_sudut ={M_PI,M_PI/2,M_PI * 3/4};
    for(int i =0;i<list_sudut.size();++i){
        std::cout<<"Cos dari Sudut:"<<list_sudut[i]<<"="<<cosinus(list_sudut[i])<<std::endl;
    }
    return 0;
}