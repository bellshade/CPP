#include <iostream>
#include <vector>
#include <cmath>


bool Verification(std::vector<int>& data,int &x){
    for(int i = 0;i <= data.size() - 1; i++){
        if(x == data[i]){
            return true;
        }
    }
    return false;
}

void Z_Score(std::vector<int>& data,int &x){
    //mean
    int resultMean;
    int Sum = 0;
    for(int i = 0; i <= data.size() - 1;i++){
        Sum += data[i];
    }
    resultMean = Sum / data.size();
    std::cout << "Nilai rata-rata: " << resultMean << std::endl;

    //standart deviation
    int denominator = data.size() - 1;
    int numerator;
    float Standar_Dev;
    float sum_numerator = 0;
    for(int i = 0; i <= data.size() - 1;i++){
        int numerator = sqrt((data[i] - resultMean) * (data[i] - resultMean)); //sqrt(pow((data[i] - mean))); 
        sum_numerator += numerator;
    }

    Standar_Dev = static_cast<double>(sum_numerator) / denominator;
    std::cout << "nilai Standar Deviation: " << Standar_Dev << std::endl;



    // Z score
    double score;
    score = (x - resultMean) / Standar_Dev;
    std::cout << "Nilai Z-Score: " << score << std::endl;


}
int main(){
    int value,count,x;
    std::vector<int> data;
    std::cout << "Masukkan panjang data: "; //masukkan panjang data
    std::cin >> count;

    for(int i = 0; i <= count - 1; i++){ // for untuk memasukkan data satu per satu
        std::cout << "Masukkan data ke " << i + 1 << ": ";
        std::cin >> value;

        data.push_back(value); //masukkan data yang di input di variabel value;
    }
    std::cout << "Masukkan nilai data(x): ";
    std::cin >> x;

    if(Verification(data,x)){
        std::cout << "Nilai yang anda masukkan sudah benar! " << std::endl;
    }else{
        std::cout << "data yang anda masukkan salah! \n";
        std::cout << "Masukkan nilai kembali: ";
        std::cin >> x;
    }
    Z_Score(data,x);

}