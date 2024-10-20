#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;
struct DataStatistic{
    float EvenMedian;
    float OddMedian;
    float size;
    float IQR;
    float Q1;
    float Q3;
};
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void PrintData(vector<float>& val){
    for(int i = 0; i < val.size(); i++){
        cout << val[i] << " ";
    }
}

void PrintOutliers(vector<float>& val){
    for(float hasil: val){
        cout << hasil << " ";
    }
}
void sort(vector<float>& val, DataStatistic &stats){
    stats.size = val.size();
    for(int i = 0; i < stats.size - 1; i++){
        //asumsikan elemen minimum adalah element index pertama atau i(karena index dimulai dari 0)
        int min = i;
        for(int j = i + 1; j<stats.size; j++){
            /*jika angka kedua lebih kecil dari angka pertama maka update nilai min menjadi angka kedua(j)*/
            if(val[j] < val[i]){
                min = j;
            }
        }
        /*
        Jika elemen terkecil yang ditemukan (min) berbeda dengan elemen saat ini (i),
        maka tukar elemen pada posisi i dengan elemen terkecil yang ditemukan.
        Proses ini menempatkan elemen terkecil di posisi yang benar pada setiap iterasi.
        */
        if(min != i){
            swap(val[i],val[min]);
        }
    }
}
void median(vector<float>& val,int &count,DataStatistic &stats){
    if(val.size() % 2 == 0){
        stats.EvenMedian = (val[val.size() / 2 - 1] + val[val.size() / 2]) / 2.0;
        cout << "Nilai Median: " << stats.EvenMedian << "\n" << endl;
    }else if(val.size() % 2 != 0){
        stats.OddMedian = val[val.size() / 2];
        cout << "Nilai Median: " << stats.OddMedian << "\n" << endl;
    }else{
        cout << "Invalid Input " << endl;
    }
}
void mean(vector<float>& val,DataStatistic &stats){ //rata -rata
    float sum = 0;
    for(int i = 0; i < val.size(); i++){
        sum += val[i];
    }
        float ResultMean = (sum / val.size());
        cout << "\n";
        cout << "Nilai rata-rata: " << ResultMean << " \n"  << endl;
}

void range(vector<float>& val,DataStatistic &stats){
    float ResultRange = val[val.size() - val[0]] - 1;
    cout << "Nilai Range: " << ResultRange << "\n" << endl;
}
void IQR(vector<float>& val,DataStatistic& stats){
    stats.Q1 = val[val.size() / 4]; //// Elemen pada posisi 25% dari data
    stats.Q3 = val[3 * val.size() / 4];      // Elemen pada posisi 75% dari data
    stats.IQR = stats.Q3 - stats.Q1;
    cout << "Nilai IQR: " << stats.IQR << endl;
}

void outliers(vector<float> &val,DataStatistic &stats){
    float lower = stats.Q1 - (1.5 * stats.IQR);
    cout << "Nilai Lower: " << lower << endl;
    float upper = stats.Q3 + (1.5 * stats.IQR);
    cout << "Nilai Upper: " << upper << endl;
    for(int i = 0;i < val.size(); ){
        while(val[i] < lower || val[i] > upper){
            cout << "Terdapat outliers pada data " << val[i] << endl;
            val.erase(val.begin() + i);
        }
        // if(val[i] < lower || val[i] > upper){
        //     cout << "Terdapat outliers pada data " << val[i] << endl;
        //     val.erase(val.begin() + i);
        // }else{
        //     ++i;
        // }
            
    }
}


int main(){
    DataStatistic stats;
    int count;
    float value;
    vector<float> val;
    cout << "Masukkan panjang sample data: ";
    cin >> count;
    for(int i = 0; i <= count -1; i++){
        cout << "Masukkan data ke " << i + 1 << ": ";
        cin >> value;
        val.push_back(value);
    }
    cout << "Hasil Statistik dasar \n" << endl;
    // Flag untuk mengecek apakah vector terurut
    bool sorted = true;

    // Loop untuk mengecek apakah vector terurut
    for (int i = 0; i < val.size() - 1; ++i) {
        if (val[i] > val[i + 1]) {
            sorted = false;
            break; // Keluar dari loop jika ditemukan ketidakurutan
        }
    }

    if (!sorted) {
        cout << "Data tidak terurut!\n";
        sort(val,stats);
        cout << "Data yang telah di sort: ";
        PrintData(val);
    } else {
        std::cout << "Data sudah terurut: ";
        PrintData(val);
    }
    mean(val,stats);
    // cout << "Nilai Tengah(median) \n" << endl;
    median(val,count,stats);
    // cout << "Range \n" << endl;
    range(val,stats);
    // cout << "Nilai IQR: \n" << endl;
    IQR(val,stats);
    outliers(val,stats);
    PrintOutliers(val);
    
}