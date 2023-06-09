/**
 * @file mean_absoulte_eror.cpp
 * @brief Program ini merupakan untuk
 * menghitung Mean Absolute Error dari 
 * 2 array dengan panjang yang sama
*/
#include <iostream>
#include <vector>
#include <exception>
#include <cmath>
/**
 * @brief Fungsi mae untuk menghitung mean Absolute Error
 * yang bertujuan mengetahui berapa akurasi error pada model
 * data yang kita latih
 * 
*/
double mae(const std::vector<double> &predict,const std::vector<double>&actual){
    if (predict.size() != actual.size()){
        throw std::invalid_argument("panjang datanya tidak sama\ntolong check lagi");
    }
    double abs_sum=0.0;
    for(int i=0;i<predict.size();i++){
        double error_value=std::abs(actual[i] - predict[i]);
        abs_sum+=error_value;
    }
    return abs_sum/predict.size();
}


int main(){
    // mari kita check
    std::vector<double> predict;
    std::vector<double> actual;

    predict={1.2,3.1,2.1,0.2,3.1};
    actual={1,3.0,2.2,0.5,2.1};
    std::cout<<"MAE :"<<mae(predict,actual);
    try{
        predict = {7.5, 4.5, 3.2};
        actual = {7.1, 5.5};

        std::cout << "MAE: " << mae(predict, actual) << '\n';
    }
    catch (const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    return 0;
}