#include <iostream>
#include <vector>
using namespace std;
//fungsi untuk menampilkan vector setelah sort secara Ascending(terkecil)
void tampilkanAscending(vector<int>& value){
    for(int i = 0; i < value.size(); i++){
        cout << value[i] << " ";
    }
}
//fungsi untuk menampilkan vector setelah sort secara Descending(terbesar)
void tampilkanDescending(vector<int>& value){
    for(int i = 0; i < value.size(); i++){
        cout << value[i] << " ";
    }
}
void InsertionSortAscending(vector<int>& value, int &key){  //insertion sort menaik
    for(int i = 1;i < value.size(); i++){
        key = value[i]; //inialisasi bilangan kedua merupakan key(kunci)
        int j = i - 1;  //inialisasi j adalah bilangan pertama
        while(j >= 0 && value[j] > key){ //operator logika AND akan true jika kedua input true
            /*jka bilangan lebih besar dari 0 dan bilangan lebih besar dari key maka while akan berjalan*/
            value[j + 1] = value[j];  // Geser elemen
            j = j - 1;    //Pindah ke elemen berikutnya di kiri
        }
        value[j + 1] = key; // Masukkan key pada posisi yang benar
    }
}
void InsertionSortDescending(vector<int>& value) { //insertion sort menurun
    for(int i = 1; i < value.size(); i++) {
        int key = value[i]; // key adalah elemen yang akan disisipkan
        int j = i - 1;
        // Geser elemen-elemen yang lebih kecil dari key ke kanan
        while(j >= 0 && value[j] < key) {
            value[j + 1] = value[j]; // Geser elemen
            j = j - 1; // Pindah ke elemen berikutnya di kiri
        }
        value[j + 1] = key; // Masukkan key pada posisi yang benar
    }
}
int main(){
    int count,input,key;
    vector<int> value;
    //meminta user untuk memasukkan panjang data(vector)
    cout << "Masukkan panjang data: ";
    cin >> count;
    for(int i = 0;i <= count - 1 ; i++){
        cout << "Masukkan data ke " << i + 1 << ": ";
        cin >> input;
        value.push_back(input);
    }
    //menampilkan vector setelah sorting
    InsertionSortAscending(value,key);
    cout << "Data setelah di urut mulai dari terkecil ";
    tampilkanAscending(value);
    InsertionSortDescending(value);
    cout << "\ndata setelah di urut mulai terbesar ";
    tampilkanDescending(value);
    cin.get();
    return 0;
}