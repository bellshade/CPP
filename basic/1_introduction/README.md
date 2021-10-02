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

**Catatan dalam penamaan file:**

- Disarankan untuk memberi nama file tanpa spasi
- Gunakan `_` atau `-` jika nama file lebih dari satu kata, misal `hello_world.cpp` atau `hello-world.cpp`

Selamat! Kamu sudah berhasil menulis program pertamamu.