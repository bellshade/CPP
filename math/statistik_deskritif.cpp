#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct DataStatistic{
    float EvenMedian;
    float OddMedian;
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
        int min = i;
        for(int j = 0;j < val.size(); j++){
            if(val[j] < val[i]){
                min = j;
            }
        }
        if(min != i){
            swap(val[i],val[min]);
        }
    }
}
void median(vector<float>& val,int &count,DataStatistic &stats){
    if(count % 2 == 0){
        stats.EvenMedian = (val[count / 2] + val[(count / 2) + 1]) / 2;
        cout << stats.EvenMedian << endl;
    }else if(count % 2 == 1){
        stats.OddMedian = val[(count + 1)/2];
        cout << stats.OddMedian << endl;
    }
}
void mean(vector<float>& val,int &count){
    float jumlah;
    for(int i = 0; i <= val.size(); i++){
        jumlah =+ val[i];
        float ResultMean = (jumlah / count);
        cout << ResultMean << endl;
    }
}

void range(vector<float>& val,int &count){
    float ResultRange = abs(val[count] - val[0]);
    cout << ResultRange << endl;
}
void IQR(vector<float>& val,int &count,DataStatistic& stats){
    float EvenQ3,EvenQ1;
    if(count % 2 == 0){
        for(int i = 0; i <= int(count / 2) ; i++){
            float EvenQ1 = val[(count + 1)/2];
            for(int j = count; j >= stats.EvenMedian; j--){
                EvenQ3 = val[(count + 1)/2];
            }
        }
        float EvenIQR = EvenQ3 - EvenQ1;
    }else{
        float OddQ3,OddQ1;
        for(int i = 0; i <= int(count / 2);i++){
            OddQ1 = val[(count + 1)/2];
            for(int j = count; j >= stats.OddMedian; j--){
                OddQ3  = val[(count + 1)/2];
            }
        }
    float OddIQR = OddQ3 - OddQ1;
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
    cout << "Hasil Statistik dasar \n";
    sort(val);
    cout << "Data ter-urut " << endl;
    PrintData(val);
    cout << "Rata-rata \n" << endl;
    mean(val,count);
    cout << "Nilai Tengah(median) \n" << endl;
    median(val,count,stats);
    cout << "Range \n" << endl;
    range(val,count);
    cout << "Nilai IQR: \n" << endl;
    IQR(val,count,stats);
    
}