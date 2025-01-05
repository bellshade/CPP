# Singleton
Adalah salah satu **Design Pattern** di kategori *Creational*. Sederhananya *pattern* ini hanya membolehkan sebuah *class* memiliki **hanya satu instance**, dan *instance* tesebut *Global Accessible* (artinya *instance* atau *object* tersebut dapat diakses oleh *unit* lain, atau katakanlah file `.cpp` lain dalam *projelt* yang sama). Terlepas dari baik dan buruknya *pattern* ini bisa dibilang banyak digunakan karena kesederhaannya dan kemudahannya dalam pengaplikasiannya.

## Kapan menggunakan Singleton ?
Saat kamu ingin suatu *object* dapat diakses secara global, dan tidak ada duplikasi dari *object* tersebut. 

## Cara kerja Singleton
Singleton memiliki `contructor` yang bersifat `private` atau `protected`, hal ini mencegah *class* tersebut dapat di-insialisasi (dibuat object) secara biasa (`Class objek;`), lalu bagaimana cara mengakses *object* atau *instance* dari *class* tersebut ?. Umumnya setiap Singleton memiliki 1 *function* public `static` dengan return datatype class nya sendiri. [contoh code](singleton_basic.cpp)

### mengenai `static` keyword
dalam CPP terdapat 3 kondisi `static` keyword, setiap kondisi dia bertingkah berbeda baik itu untuk variable ataupun untuk fingsi.
1. ketika digunakan di *file scope*, maka variable tersebut global namun hanya sebatas dalam file dimana ia di-deklarasikan. [contoh kode](static_file_scope/)
2. ketika digunakan di *function scope*, maka variable tersebut global, namun hanya bisa diakses oleh atau melalui fungsi tersebut saja. Contohnya seperti yang [awal-awal](singleton_basic.cpp) 
> [!NOTE]
> - variable tersebut belum akan di inisialisasi sampai fungsi tersebut dipanggil pertama kali. (bagus untuk menghemat resources, namun eksekusi task kamu akan butuh extra waktu saat eksekusi pertama kali)
> - tidak ada inisialisasi ulang, meskipun fungsi dipanggil beberapa kali
3. ketika digunakan di *struct* atau *class scope*, maka variable tersebut bukan sembarang member, melainkan member yang global, dapat diakses meskipun belum dibuat *object*-nya (tergantung level visibilitas), dan setiap *object* mendapatkan *share* akan variable tersebut (jika *object* kesatu mengubah nilai variable tersebut maka *object* kedua pun merasakan perubahannya). Sederhananya variable tersebut milik *class* dan bukan milik *object* [contoh code](static_class_scope.cpp)

## Catatan
Hindari penggunaan Singleton secara berlebihan, contoh saat kamu ingin cek apakah *Plane* yang dibuat itu memiliki bentuk *square*:
```cpp
class Plane {
    public: 
      Plane (int x0, int y0, int x1, int y1) {
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
      }
      int x0, y0, x1, y1;
};

class PlaneManager {
    private: 
      PlaneManager () = default;
    public:
      static PlaneManager& getInstance () { 
        static PlaneManager instance;
        return instance;
      }
      
      Plane* createPlane (int x0, int y0, int x1, int y1) {
        Plane* plane =  new Plane(x0, y0, x1, y1);
        return plane;
      }
      bool isSquareShaped (Plane& plane) {
        return (plane.x1 - plane.x0) == (plane.y1 - plane.y0);
      }
};
```
bagaiman kalau begini
```cpp
class Plane {
    public: 
      Plane (int x0, int y0, int x1, int y1) {
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
      }
      int x0, y0, x1, y1;
      
      bool isSquareShaped() {
        return (x1 - x0) == (y1 - y0);
      }
};
```
lalu insialisasi objek dengan cara yang biasa, lebih simple dan masalah terselesaikan.

## Contoh kode
- [basic singleton](singleton_basic.cpp)
- [basic singleton 2](singleton_another_example.cpp)
---
- static
  - [static di file scope](static_class_scope/)
  - [static di function scope](singleton_basic.cpp)
  - [static di class scope](static_class_scope.cpp)
