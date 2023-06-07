/**
 * @file variance.cpp
 * @brief Program untuk menghitung
 * Variance data (Var) dari banyaknya item
 *  dengan panjang data
*/

#include<iostream>
#include<vector>
/**
 * @brief Fungsi untuk menghitung Variansi data
 * dari sebuah data array biasa dan dibagi panjang
 * datanya sehingga bisa melihat karakteristik data
 * @param data adalah data berupa array biasa
 * @param n merupakan nama variabel dari panjang data
 * @return merupakan hasil dari perhitungan tersebut
*/

float variance(const std::vector<int>&data,int n){
    // kita buat variabel sum untuk
    // menampung hasil perjumlahan pada
    // data tersebut
    int sum=0;
    for(size_t i=0;i<n;i++){
        sum+=data.at(i);
    }
    // kemudian kita buat variabel mean
    // untuk menghitung rata-rata dengan
    // nama variabel tersebut mean
    float mean= static_cast<float> (sum) / n;
    // mari kita kalkulasi variance dengan
    // perulangan for loop

    // mari kita buat variabel variance
    // untuk menampung hasil kalkulasi
    // variance pada looping tersebut
    float variance=0.0;
    for(size_t i=0;i<n;i++){
        float diff=data.at(i)-mean;
        diff*=diff;
        variance+=diff;
    }
    // lalu kita bagi dengan decrement
    variance/=n;
    return variance;
}


int main(){
    std::vector<int> data;
    data={1,2,4};
    int n=data.size();
    std::cout<<"variasi"<<variance(data,n);
}