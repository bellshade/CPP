# Daftar Isi

1. [Definisi open adressing](#definisi-open-adressing)  
2. [Requirements](#requirements)   
3. [Jenis Open Addressing](#jenis-open-addressing)  
   - [Linear Probing](#linear-probing)  
   - [Quadratic Probing](#quadratic-probing)  
   - [Double Hashing](#double-hashing)  

## 1.definisi open adressing
<p style="text-allign: justify;">
Open Adressing adalah metode  dimana semua element disimpan langsung didalam hash table itu sendiri,tanpa menggunakan data struktur eksternal seperti linked list.jika terjadi collision, maka algoritma akan mencari slot kosong lain didalam array berdasarkan aturan pencarian(probing).  
</p>

## 2.requirements
<p style="text-allign: justify">
Dibutuhkan prasyarat untuk Melankah ke linear probing diantaranya:

- memahami implementasi <code>Array</code>

- memahami implementasi <code>Circular Array</code>

- memahami implementasi dynamic array misal 
<code>doubling method</code> untuk memperbesar ukuran hash table

- memahami hash function misal <code>division method</code>

jika belum terlalu memahami requirements diatas,anda dapat
belajar pada

- [hash function](struktur_data/hash_table/hash_function)

- [dynamic array](https://www.geeksforgeeks.org/dsa/how-do-dynamic-arrays-work/)

- [circular array](https://www.geeksforgeeks.org/dsa/circular-array/)

- [array](https://www.geeksforgeeks.org/dsa/array-data-structure-guide/)
</p>

## 3.Jenis Open Adressing   
<p style="text-allign: justify">
    Jenis <code>open addressing</code> dibedakan dari metode mencari slot kosong pada array.Ada 3 jenis <code>open adressing</code> yaitu:
</p>

- ### Linear Probing

<p style="text-allign: justify">
    <code>Linear Probing</code> adalah salah satu teknik <code>open adressing</code> pada hash table untuk menangani <code>collision(tabrakan)</code>.Jika sebuah slot <code>index hash</code>,maka algoritma akan mencari slot kosong secara <code>linear</code> didalam array hash table.
</p>

$$h(k) = (h(k + 1)) \% \text{capacity} 

atau

$$h(k) = (h(k + 1)) \bmod \text{capacity}   