#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;
struct DataStatistic{
    float EvenMedian;
    float OddMedian;
    float mid;
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
void sort(vector<float>& val){
    for(int i = 0; i < val.size() - 1; i++){
        //asumsikan elemen minimum adalah element index pertama atau i(karena index dimulai dari 0)
        int min = i;
        for(int j = i + 1; j<val.size(); j++){
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
void mean(vector<float>& val,int &count){ //rata -rata
    float sum = 0;
    for(int i = 0; i < val.size(); i++){
        sum += val[i];
    }
        float ResultMean = (sum / val.size());
        cout << "\n";
        cout << "Nilai rata-rata: " << ResultMean << " \n"  << endl;
}

void range(vector<float>& val){
    float ResultRange = val[val.size() - val[0]] - 1;
    cout << "Nilai Range: " << ResultRange << "\n" << endl;
}
void IQR(vector<float>& val,int &count,DataStatistic& stats){
    float EvenQ3,EvenQ1;
    int size = val.size();
    if(count % 2 == 0){
        for(int i = 0; i <= int(size / 2) ; i++){
            float EvenQ1 = val[(size + 1)/2];
            for(int j = size; j >= stats.EvenMedian; j--){
                EvenQ3 = val[(size + 1)/2];
            }
        }
        float EvenIQR = EvenQ3 - EvenQ1;
        cout << "Nilai IQR: " << EvenIQR << endl;

    }else{
        float OddQ3,OddQ1;
        for(int i = 0; i <= int(size / 2);i++){
            OddQ1 = val[(size + 1)/2];
            for(int j = size; j >= stats.OddMedian; j--){
                OddQ3  = val[(size + 1)/2];
            }
        }
    float OddIQR = OddQ3 - OddQ1;
    cout << "Nilai IQR: " << OddIQR << endl;
    }
}

int main(){
    DataStatistic stats;
    int count,CountElement;
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
        sort(val);
        cout << "Data yang telah di sort: ";
        PrintData(val);
    } else {
        std::cout << "Data sudah terurut: ";
        PrintData(val);
    }
    mean(val,count);
    // cout << "Nilai Tengah(median) \n" << endl;
    median(val,count,stats);
    // cout << "Range \n" << endl;
    range(val);
    // cout << "Nilai IQR: \n" << endl;
    IQR(val,count,stats);
    
}