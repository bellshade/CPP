# Pengenalan C++

C++ adalah bahasa pemrograman yang dibuat pada tahun 1979. Seperti namanya, C++ adalah bahasa turunan dari bahasa C. C++ menyempurnakan konsep OOP yang tidak terdapat dalam bahasa C.

Sama seperti bahasa pada umumnya, program C++ dijalankan baris per baris, dari atas ke bawah, dan dari kiri ke kanan.

Struktur dari C++ adalah sebagai berikut:

```cpp
#include <iostream>

int main() {
	// program kamu berada di sini
}
```

- `#include <iostream>` adalah library yang digunakan
- `int main()` adalah function yang menampung semua program kamu

## Menulis Program C++ Pertamamu

Program C++ disimpan dengan ekstensi `.cpp`, yang berarti "C Plus Plus". Silakan buka code editor favorit kamu lalu tulis code di bawah ini dan simpan filenya dengan nama `hello_world.cpp`.

```cpp
#include <iostream>
using namespace std;

int main() {
	cout << "Hello World!";
	return 0;
}
```

Penjelasan tentang code ini dapat dilihat [di sini](hello_world.cpp).

## Namespace

Namespace berguna untuk memperpendek kode jika kita menggunakan suatu library yang telah ada,
jika kita bandingkan kode di atas dan dibawah maka akan ada perbedaan penggunaan `cout` dan `std::cout` (tanpa menggunakan `using namespace std;` )

```cpp
#include <iostream>

int main() {
	std::cout << "Hello World!";
	return 0;
}
```

## Komentar

Komentar pada kode sangat berguna dalam menerangkan/menginformasikan kode yang kita tulis, komentar yang ditulis pada kode tidak akan dieksekusi oleh mesin.
Terdapat 2 cara dalam menulisan kode pada C++ yaitu komentar 1 baris menggunakan simbol `//`, dan komentar multiline yang diapit oleh simbol `/*` dan `*/`

```cpp
#include <iostream>

int main() {
	// Komentar 1 baris, komentar ini tidak akan di eksekusi oleh mesin

	/*
			ini komentar multiline
			yang berisi lebih dari 1 baris
	*/
}
```

**Catatan dalam penamaan file:**

- Disarankan untuk memberi nama file tanpa spasi
- Gunakan `_` atau `-` jika nama file lebih dari satu kata, misal `hello_world.cpp` atau `hello-world.cpp`

Selamat! Kamu sudah berhasil menulis program pertamamu.
