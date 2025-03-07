# Operator

Sebelum mempelajari tentang operator, kamu harus sudah mengenal tentang "Ekspresi". Ekspresi terdiri dari dua komponen, yaitu **operator** dan **operand.**

- operator: simbol dari operasi yang akan dilakukan
- operand: nilai yang akan dioperasikan

**Contoh**: `a + b`
a dan b adalah operand
simbol `+` adalah operator


Selanjutnya, kita akan mempelajari tentang operasi dan operatornya.

## 1. Operator Numerik

Operasi numerik adalah operasi yang dilakukan pada bilangan. Operasi numerik juga dikenal dengan nama operasi aritmatika

| Operator | Nama Operasi |
| - | - |
| `+` | Penambahan |
| `-` | Pengurangan |
| `*` | Perkalian |
| `/` | Pembagian |
| `%` | Modulo |

**Hal-hal yang perlu diperhatikan:**

- Jika operand merupakan bilangan bulat, akan selalu menghasilkan bilangan bulat juga.
- Jika ada salah satu operand bertipe `float`, hasil akan berupa `float` juga.
- Operasi pembagian pada `integer` akan dibulatkan ke bawah
- Operasi modulo hanya bisa digunakan pada `integer`

contoh lebih lanjut dari operator numerik bisa dilihat [disini](https://www.youtube.com/watch?v=bxNqTu4N-Is&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=15)

### Operator Unary

Operasi unary dapat dilakukan dengan hanya satu operand. Operator yang sering digunakan adalah increment (++) dan decrement (—).

| Operator | Nama Operasi | Contoh |
| - | - | - |
| `-` | Negatif | `-1` |
| `++` | Penambahan | `i++`, `++i` |
| `--` | Pengurangan | `i--`, `--i` |

lebih lanjut dari operator unary bisa dilihat [disini](https://www.youtube.com/watch?v=cmKs-eEsHfY&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=23)

## 2. Operator Relasional

Operasi relasional yaitu membandingkan dua operand dan mengembalikan `boolean` (`true` atau `false`).

| Operator | Nama Operasi |
| - | - |
| `==` | Sama dengan |
| `!=`| Tidak sama dengan |
| `<` | Kurang dari |
| `>` | Lebih dari |
| `<=`| Kurang dari atau sama dengan |
| `>=` | Lebih dari atau sama dengan |

contoh lebih lanjut dari operator relasional bisa dilihat [disini](https://www.youtube.com/watch?v=rgdgn4yFg18&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=16)

## 3. Operator Logika

Operator logika digunakan untuk menggabungkan dua—atau lebih—kondisi

| Operator | Nama Operasi |
| - | - |
| `&&` | AND |
| `\|\|` | OR |
| `!` | NOT |

lebih lanjut dari operator logika bisa dilihat [disini](https://www.youtube.com/watch?v=k9nBTzvba34&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=17)

## 4. Operator Bitwise

Operator Bitwise adalah operator yang melakukan operasi pada level bit (biner) dari suatu nilai.
Operator ini bekerja dengan mengoperasikan bit per bit dari dua operand.

| Operator | Nama Operasi | Keterangan |
| - | - | - |
| `&` | AND | Menghasilkan 1 jika kedua bit bernilai 1 |
| `\|` | OR | Menghasilkan 1 jika salah satu bit bernilai 1 |
| `^` | XOR | Menghasilkan 1 jika kedua bit bernilai berbeda |
| `~` | NOT | Membalikkan semua nilai bit |
| `<<` | Left Shift | Menggeser bit ke kiri |
| `>>` | Right Shift | Menggeser bit ke kanan |

**Contoh penggunaan:**
```cpp
int a = 5;  // 00000101 dalam biner
int b = 3;  // 00000011 dalam biner

int c = a & b;  // 00000001 = 1
int d = a | b;  // 00000111 = 7
int e = a ^ b;  // 00000110 = 6
int f = ~a;     // 11111010 = -6
int g = a << 1; // 00001010 = 10
int h = a >> 1; // 00000010 = 2
```

Operator Bitwise sering digunakan dalam:
- Pemrograman sistem
- Optimasi kode
- Manipulasi flag dan state
- Enkripsi data sederhana
