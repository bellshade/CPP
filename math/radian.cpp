/**
 * @file radian.cpp
 * @brief  program ini adalah untuk menghitung covert satuan
 * sudut seperti radian,degree dan gradian
*/

#include<iostream>
#include<cmath>
/**
 * @brief fungsi ini merupakan untuk mengubah dari
 * satuan radian kedalam bentuk satuan degree
 * @param radian parameter ini adalah nilai
 * input dalam bentuk satuan radian
*/

double radian_to_degree(float radian){
    return radian *(180/M_PI);
}
/**
 * @brief fungsi ini merupakan untuk mengubah dari
 * satuan derajat ke dalam radian
 * @param degree parameter ini merupakan nilai
 * input dalam bentuk satuan degree
*/

double degree_to_radian(float degree){
    return degree * (M_PI/180);
}

/**
 * @brief fungsi ini merupakan untuk mengubah dari
 * satuan radian kedalah bentuk gradian
 * @param radian merupakan input parameter dalam
 * satuan radian
*/

double radian_to_gradian(float radian){
    return radian * (200/M_PI);
}

int main(){
    // mari kita check
    std::cout<<"Convert dari radian ke degree"<< radian_to_degree(20.1)<<'\n';
    std::cout<<"Convert dari degree ke radian"<< degree_to_radian(12.0)<<'\n';
    std::cout<<"Convert dari radian ke gradian"<< radian_to_gradian(122.12)<<'\n';
    return 0;
}

