#include <iostream>
#include <vector>
#include <cmath>

int Z_Score(std::vector<int> data){
    //mean
    int mean = 0;
    for(int i = 0; i <= data.size() - 1;i++){
        mean += data[i];
    }

    std::cout << "Nilai rata-rata: " << mean << std::endl;

    //standart deviation
    int denominator = data.size() - 1;
    int numerator;
    int Standar_Dev;
    int sum_numerator = 0;
    for(int i = 0; i <= data.size() - 1;i++){
        numerator = static_cast<float>(sqrt(data[i] - mean));
        sum_numerator += numerator;
    }

    Standar_Dev = static_cast<double>(sum_numerator) / denominator;

}


int main(){
    int value,count;
    std::vector<int> data;
    std::cout << "Masukkan panjang data: ";
    std::cin >> count;

    for(int i = 0; i <= count - 1; i++){
        std::cout << "Masukkan data ke " << i + 1 << ": ";
        std::cin >> value;

        data.push_back(value);
    }

}