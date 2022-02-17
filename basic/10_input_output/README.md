# basic input output

pustaka standar c++ menyediakan serangkaian kemampuan input / output yang luas.c++ I/O aterjadi dalam aliran, yang merupakan urutan byte. jika byte mnegalir dari perangkat seperti keyboard, disk drive, atau koneksi jaringan, dll. ke memori utama, ini disebut **operasi input** dan jika byte mengalir dari memori utama ke perangkat seperti layar tampilan, printer, drive, disk, atau koneksi jaringan, dll,. ini disebut dengan **operasi keluaran atau output**

1. **<iostream>**
    file ini mendifinisikan objek cin, cout, cerr, dan clog, yang masing-masing sesuai dengan aliran input standar, aliran output standar, aliran error standar tanpa buffer, dan aliran error standar buffer

2. **<iomanip>**
    file ini meyatakan layan yang berguna untuk melakukan I/O yang diformat dengan apa yang disebut dengan manipulator aliran **berparameter**, seperti **setw** dan **setprecision**

3. **<fstream>**
    file ini mendlakarasikan layanan untuk pemrosesan file yang dikontrol pengguna.


## aliran keluaran standar (cout)

Objek ditentukan sebelumnya cout adalah turunan dari ostream kelas. Objek cout dikatakan "terhubung ke" perangkat output standar, yang biasanya adalah tampilan layar. The cout digunakan bersama dengan operator aliran penyisipan, yang ditulis sebagai << yang dua kurang dari tanda-tanda seperti yang ditunjukkan dalam contoh berikut.

```cpp
#include <iostream>

int main(){
    char str[] = "bellshade cpp";
    std::cout<<str;
    return 0;
}
```

Kompiler C++ juga menentukan tipe data variabel yang akan dikeluarkan dan memilih operator penyisipan aliran yang sesuai untuk menampilkan nilainya. Operator << kelebihan beban untuk menampilkan item data dari tipe bawaan integer, float, double, string, dan nilai pointer.

## aliran input standar (cin)

Objek yang telah ditentukan cin adalah turunan dari kelas istream . Objek cin dikatakan dilampirkan ke perangkat input standar, yang biasanya adalah keyboard. The cin digunakan bersama dengan operator ekstraksi aliran, yang ditulis sebagai >> yang dua lebih besar dari tanda-tanda seperti yang ditunjukkan dalam contoh berikut.

```cpp
#include <iostream>

int main(){
    char merek_mobil[50];
    
    std::cout<<"masukkan nama merk mobil: ";
    std::cin>>merek_mobil;
    cout<<"wow "<<merek_mobil<<" keren!";
    
    return 0;
}
```

Kompiler C++ juga menentukan tipe data dari nilai yang dimasukkan dan memilih operator ekstraksi aliran yang sesuai untuk mengekstrak nilai dan menyimpannya dalam variabel yang diberikan.

## aliran error standar (cerr)

Objek yang telah ditentukan cerr adalah turunan dari kelas ostream . Objek cerr dikatakan dilampirkan ke perangkat kesalahan standar, yang juga merupakan layar tampilan tetapi objek cerr tidak di-buffer dan setiap penyisipan aliran ke cerr menyebabkan outputnya segera muncul.

```cpp
#include <iostream>

int main(){
    char str[] = "error pada aplikasi..!";
    cerr<<"problem: "<<str;

    return 0;
}
```

## aliran log standar (clog)

Object clog yang telah ditentukan sebelumnya adalah turunan dari kelas ostream . Objek clog dikatakan dilampirkan ke perangkat kesalahan standar, yang juga merupakan tampilan layar tetapi objek clog di -buffer. Ini berarti bahwa setiap penyisipan yang menyumbat dapat menyebabkan outputnya tertahan di buffer sampai buffer terisi atau sampai buffer.

```cpp
#include <iostream>

int main(){
    char str[] = "masalah pada aplikasi..";

    clog<<"log: "<<str;

    return 0;
}
```

Kamu tidak akan dapat melihat perbedaan apa pun dalam cout, cerr, dan clog dengan contoh-contoh kecil ini, tetapi saat menulis dan menjalankan program besar, perbedaannya menjadi jelas. Jadi itu adalah praktik yang baik untuk menampilkan pesan kesalahan menggunakan aliran cerr dan saat menampilkan pesan log lainnya maka clog harus digunakan.

contoh lebih lanjut dari fungsi input output bisa dilihat [disini](https://www.youtube.com/watch?v=-N-iONms8uw&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=13)