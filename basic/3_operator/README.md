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

### Operator Unary

Operasi unary dapat dilakukan dengan hanya satu operand. Operator yang sering digunakan adalah increment (++) dan decrement (—).

| Operator | Nama Operasi | Contoh |
| - | - | - |
| `-` | Negatif | `-1` |
| `++` | Penambahan | `i++`, `++i` |
| `—` | Pengurangan | `i—`, `—i` |

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

## 3. Operator Logika

Operator logika digunakan untuk menggabungkan dua—atau lebih—kondisi

| Operator | Nama Operasi |
| - | - |
| `&&` | AND |
| `||` | OR |
| `!` | NOT |