## definisi kelas

blok pembangun c++ yang mengarah ke pemograman berorientasi objek adalah kelas. ini adalh tipe data yang ditentukan pengguna yang menyimpan anggota data dan fungsi anggotanya sendiri, yang dapat diakses dan digunakan dengan membat turunan dari kelas itu. kelas seperti cetak biru untuk suatu objek

- kelas adalah tipe data yang ditentukan pengguna yang memiliki anggota data dan fungsi anggota
- anggota data adalah variabel data dan fungsi anggota adalah fungsi yang digunakan untuk memanipulasi variabel-variabel ini dan bersama-sama anggota data ini dan fungsi anggota mendifinisikan properti dan perilaku objek di kelas

kita dapat mengatakan bahwa **kelas dalam c++** adalah etak biru ynag mewakii sekelompok objek yang berbagi beberapa properti dan perilaku umum

**objek**

objek adalah entitas yang dapat diidentfikasi dengan beberapa karaterisitik dan perilaku. objek adalh turunan dari kelas. ketika sebuah kelas didefinisikan, tidak ada memmori yang dialokasikan tetapi ketika itu dipakai (yaitu sebuah objek dibuat) memori dialokasikan.
```cpp
class Pelajar{
    char nama[20];
    int nomo_mhs;
public:
    void tentang_mhs(){
        // blok kode dari fungsi yang
        // berisikan barisan kode yang memuat
        // detail tentang mhs
    }
};

int main(){
    Pelajar mhs1;   // mhs1 adalah sebagai objek
}
```
objek mengambil ruang di memori dan memiliki alamt terkait seperti catatan dalam pascal atau struktur atau gabungan dalam C.

ketika sebuah program diekseskusi, objek beriteraksi dengan mengirim pesan satu sama lain.setiap objek berisi data dan kode untuk memanipulasi data.

objek dapat berintraksi tanpa harus mengetahui detail data atau kode satu sama lain, cukup mengetahui jenis pesan yang diterima dan jenis respon yang dikembalikan oleh objek.