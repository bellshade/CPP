#include <iostream>
#include <vector>
#include <array>

using namespace std;
// Fungsi untuk menukar posisi dua elemen
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void PrintVec(vector<int>& val){ //gunakan referencing
    for(int print = 0; print < val.size(); print++){
        cout << val[print] << " ";
    }

}

void SelectionSort(vector<int>& val){  //gunakan referencing untuk menghindari banyak penggunaan variabel
    int i,j,min;
    /*
    Lakukan iterasi untuk setiap elemen vector dengan i sebagai indeks elemen pertama.
    Karena elemen terakhir secara otomatis sudah berada di posisi yang benar setelah semua iterasi,
    maka loop untuk i berhenti di val.size() - 1.
    */
    for(i = 0; i < val.size() - 1; i++){
        //asumsikan elemen minimum adalah element index pertama atau i(karena index dimulai dari 0)
        min = i;
        for(j = i + 1; j<val.size(); j++){
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
int main(){
    int value;
    int count;
    vector<int> val;
    // meminta user untuk memasukkan panjang data vector
    cout << "Masukkan panjang data: ";
    cin >> count;
    for(int i = 0; i <= count - 1 ; i++){
        cout << "Masukkan data ke " << i + 1 << ": ";
        cin >> value;
        val.push_back(value); //memasukkan nilai yg dimasukkan(value) ke vector val
    }

    SelectionSort(val);
    cout << "sesudah sorting " << endl;
    PrintVec(val);


    cin.get();
    return 0;

}