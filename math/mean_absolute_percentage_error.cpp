#include<iostream>
#include<cmath>
#include <vector>
double mean_absolute_percentage_error(const std::vector<float>&data_predict,const std::vector<float>&data_actual){
    // mengcheck panjang datanya
    if (data_predict.size() != data_actual.size())
    {
        throw std::invalid_argument("ukuran datanya harus sama ya!!\n");
    }
    double sum_abs=0.0;
    for (int i=0;i<data_predict.size();i++){
        // hitung dulu selisihnya
        double selisih= data_actual[i]-data_predict[i];
        // dibagi dengan nilai actualnya
        selisih/=data_actual[i];
        // lalu di absoulute
        sum_abs+=std::abs(selisih);
    }
    double hasil = sum_abs/data_predict.size();
    return hasil;
}

int main(){
    // mari kita ujikan
    std::vector<float> data_prediksi;
    std::vector<float> data_asli={1.2,3.1,2.11,3.1};
    data_prediksi={1.2,3.1,2.1,2.2};
    data_asli={1.2,3.1,2.11,3.1};
    // output
    std::cout<<"hasil MAPE adalah"<<mean_absolute_percentage_error(data_prediksi,data_asli)<<std::endl;

    try
    {
        /* code */
        data_prediksi={1.2,3.1,.1};
        data_asli={1.2,3.2};
        std::cout<<"MAPE ="<< mean_absolute_percentage_error(data_prediksi,data_asli)<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}