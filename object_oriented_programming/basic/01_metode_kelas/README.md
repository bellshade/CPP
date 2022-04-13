## class method

Metode adalah fungsi yang dimiliki oleh kelas

ada dua cara untuk mendifinisikan fungsi yang termasuk dalam kelas:
- block di dalam kelas
- block di luar kelas

## inner class

ketika kita mengakses sebuah atribut yang terdapat dalam kelas, maka kita menggunakan fungsi titik ``.``: contoh

```cpp
class KelasSaya {
    public:
        void methodSaya() {
            std::cout<<"bellshade";
        }
};

int main() {
    KelasSaya objectSaya;
    objectSaya.methodSaya();
    
    return 0;
}
```

## outer class

untuk mendifinisikan fungsi di luar kelas, kita harus mendklarasikannya di dalam kelas dan kemudian mendifinisikannya di luar kelas. ini dilakukan dengan menentukan nama kelas, diikuti operator ``::`` dan diikuti dengan nama fungsi

```cpp
class KelasSaya {
    public:
        void methodSaya();
};

// mendklarasikan kembali
void KelasSaya::methodSaya() {
    std::cout<<"bellshade";
}

int main() {
    KelasSaya objectSaya;
    objectSaya.methodSaya();

    return 0;
}
```