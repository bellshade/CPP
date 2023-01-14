# inheritance

Salah satu konsep terpenting dalam pemograman berorientasi objek adalah pewarisan atau inheritance.warisan memungkinkan kita untuk medifinisikan kelas dalam istilah kelas lain, yang membuatnya lebih mudah untuk membuat dan melihara aplikasi. ini juga memberikan kesempatan untuk menggunakan kembali fungsionalitas kode dan waktu implementasi yang cepat.

## kelas dasar turunan

seubah kelas dapat diturunkan dari lebih dari satu kelas, yang berarti dapat mewarisi data dan gungsi dari bebrapa kelas dasar. untuk medifinisikan kelas turunan, kita menggukana daftar turunan kelas untuk menentukan kelas dasar. daftar derivasi kelas menamai satu atau lebih kelas dasar dan memiliki bentuk.

```
class derived-class: akses kelas_utama
```

```cpp
#include <iostream>

class Kecepatan{
    public:
        void setJarak(int j){
            jarak = j
        }
        void setWaktu(int w){
            waktu = w
        }
    protected:
        int jarak;
        int waktu;
};

class Kalkulasi: public Kecepatan{
    public:
        int getKecepatan(){
            return (jarak / waktu)
        }
};

int main(){
    Kecepatan kecepatan;
    kecepatan.setJarak(17);
    kecepatan.setWaktu(5);

    std::cout<<"total: "<<Kecepatan.getKecepatan()<<std::endl;

    return 0;
}
```