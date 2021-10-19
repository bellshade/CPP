# cpp break dan continue statement

## cpp break
break adalah statement dimana, digunakan untuk memberhentikan jika value dari looping sudah terpenuhi.

contoh
```cpp
for (int i = 0; i < 50; i++){
    if(i == 20){
        break
    }
    std::cout<<i<<"\n";
}
```
pada penjelasan diatas variabel ``i`` yang semula 0 akan bertambah berulang ``0 ke 49``, tetapi disini memliki kondisi dimana jika value dari i sudah mencapai 20 (``0 ke 19``) maka looping akan memberhentikan prosesnya


## cpp continue
continue adalah statement dimana, digunakan untuk melewati value yang spesifik dimana yang sudah dideklarasikan dalam sebuah kondisi.

contoh

```cpp
for (int i = 0; i < 50; i++){
    if(i == 20){
        continue;
    }
    std::cout<<i<<"\n";
}
```
pada penjelasan diatas variabel ``i`` yang semula 0 akan bertambah berulang ``0 ke 49``, tetapi disini memliki kondisi dimana jika value dari i sudah mencapai 20 (``0 ke 19``) maka value yang ``20`` akan dilewati
```
18
19
21
22
23
```
