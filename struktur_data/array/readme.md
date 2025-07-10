# Array

`Array` adalah salah satu struktur data dasar yang digunakan untuk `menyimpan sekumpulan elemen` dengan tipe data yang sama. `Array` termasuk struktur data statis karena ukurannya tetap setelah dialokasikan. Namun, konsep array juga dapat direpresentasikan secara dinamis, seperti pada [array dinamis](struktur_data/array/dynamic_array/readme.md), yang memungkinkan ukuran array bertambah saat runtime.

nah,disini kita akan membahas dulu Array Statis,kita belajar tanpa menggunakan Library sama
sekali untuk menguatkan fundamental
## 1.Mendeklarasikan Array
Untuk mendeklarasikan `array` statis di C++, kita harus menentukan kapasitas (jumlah elemen maksimal) array sejak awal. Kapasitas ini tidak bisa diubah setelah array dibuat.
```cpp
int main(){
    //type_data nama_array [panjang_array].
    int arr[10];
    return 0;
}
```
diatas adalah contoh untuk mendeklarasikan sebuah array dengan tipe data int dan dengan kapasitas
berjumlah 10
## 2.Menginialisasikan nilai Array

Ada dua cara untuk menginialisasikan Array,yaitu dengan cara Manual dan Menggunakan loop

### a.Manual

menginialisasikan nilai dengan cara manual,dilakukan bersamaan saat mendeklarasikan sebuah arr
ex:
```cpp
int main(){
    //type_data nama_array [panjang_array] = {a1,a2,...an} dengan n = kapasitas
    int arr[10] = {1,2,3,4,5,6,6,7,8,9,1};
    return 0;
}
```
### b.Menggunakan Loop

untuk menginisialisasi nilai dengan loop,kita terlebih dahulu harus menentukan berapa element
yang ingin di inisialisasi bisa dengan manual atau input user
ex:
```cpp
int main(){
    int arr[10];
    int n;//banyak element yang ingin di insert 
    std::cout << "Masukkan Banyak Element yang ingin di Insert: ";
    std::cin >> n;
    std::cin.get();
    return 0;
}
```
setelah itu kita dapat langsung menginisialisasi nilai dengan loop
ide nya adalah
1.Lakukan loop mulai dari 0 sampai n - 1;
2.input nilai
3.Simpan nilai input ke dalam array pada indeks saat ini
ex:
```cpp
int main(){
    int arr[10];
    int n;//banyak element yang ingin di insert 
    std::cout << "Masukkan Banyak Element yang ingin di Insert: ";
    std::cin >> n;
    for(size_t i = 0;i < n;i++){
        int data; //deklarasikan variabel menyimpan data sementara
        std::cin >> data;
        arr[i] = data;
    }
    std::cin.get();
    return 0;
}
```
Jika Anda ingin melihat implementasinya dalam bentuk `source code`, silakan lihat di:  
[Array.cpp](struktur_data/array/array.cpp)


Sebenarnya, kita tidak wajib menginisialisasi seluruh elemen array hingga kapasitas maksimal. 
Kita bisa saja hanya mengisi sebagian elemen — misalnya 1, 2, atau beberapa elemen saja sesuai kebutuhan.

Namun perlu diperhatikan bahwa jika kita hanya mengisi sebagian dari kapasitas array secara manual,
maka **sisa elemen yang tidak diisi tidak otomatis bernilai 0**. Nilai dari elemen-elemen tersebut akan berisi 
**nilai acak (garbage value)** jika tidak diinisialisasi secara eksplisit.
ex
```cpp
int main(){
    int arr[10] = {1,2,3,4};
    int size = sizeof(arr) / sizeof(arr[0]);
    for(size_t i = 0;i < size;i++){
        std::cout << arr[i] <<  " ";
    }
}
```
output:
```bash
1  2  3  4  0  0  0  0  0 0
```
Saat kita mendeklarasikan array int arr[10] = {1, 2, 3, 4};, artinya kita hanya menginisialisasi elemen pertama hingga keempat (indeks 0 sampai 3) dengan nilai tertentu.
Sisa elemen (indeks 4 hingga 9) otomatis akan diisi dengan nilai 0 sesuai aturan partial initialization di C++.

Untuk Implementasi Seperti Delete Element Array,Insert memakai index,dll akan dibahas penuh di [array dinamis](struktur_data/array/dynamic_array/readme.md),sementara anda baru dapat melihat untuk [source code ](struktur_data/array/dynamic_array/array_dinamis.cpp)
