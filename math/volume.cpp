/**
 * @file volume.cpp
 * @brief file ini merupakan kumpulan
 * fungsi untuk melakukan perhitungan
 * volume bangunan
*/

#include<iostream>
#include<cmath>

double volume_kubus(float sisi){
    /**
     * fungsi untuk menghitung volume kubus
     * @param sisi merupakan input sisi yang
     * bertipe data double dengan panjang datanya
     * lebih besar
     * @return hasil pangkat dari sisi pangkat 3
    */
    return std::pow(sisi,3.0);
}

double volume_balok(double panjang,double lebar,double tinggi){
    /**
     * fungsi ini menghitung volume balok
     * @param panjang merupakan input panjang sebuah balok
     * @param lebar merupakan input lebar sebuah balok
     * @param tinggi merupakan input tinggi sebuah balok
     * @return hasil dari perkalian panjang,lebar dan tinggi
    */
    return panjang * lebar * tinggi;
}

double volume_kerucut(double area_dasar,double tinggi){
    /**
     * fungsi ini menghitung volume kerucut
     * @see [cone](https://en.wikipedia.org/wiki/Cone) 
     * @param area_dasar merupakan input area dasar sebuah kerucut
     * @param tinggi merupakan input lebar sebuah kerucut
     * @return hasil dari perkalian area dasar dan tinggi dibagi 3
    */
    return area_dasar * tinggi /3.0;
}
double volume_tabung(double jari_jari,double tinggi){
     /**
     * fungsi ini menghitung volume tabung
     * @see [cone](https://en.wikipedia.org/wiki/Cone) 
     * @param jari merupakan input jari jari pada luas area
     * @param tinggi merupakan input panjangnya tinggi tersebut
     * @return hasil dari perkalian luas lingkaran dan tinggi
    */
    return M_PI * pow(jari_jari,2.0) * tinggi;
}
double volume_bola(double jari){
    /**
     * fungsi ini menghitung volume bola
     * @param jari merupakan input dari jari-jari yang dimiliki bola
     * return hasil dari perkalian dengan rumus V = \frac{4}{3}\pi r^3 
     * */
    return (4/3) * M_PI * pow(jari,3.0);
}

int main(){
	std::cout<<"Volume Bola"<<volume_bola(10.22);
	std::cout<<"Volume tabung"<<volume_tabung(10.9,4.3);
    return 0;
}
