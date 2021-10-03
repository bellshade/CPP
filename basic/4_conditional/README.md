# Percabangan/Pengkondisian

Mari kita mulai dengan studi kasus.

Kamu sedang belajar untuk membedakan bilangan positif, nol, atau negatif. Sebuah bilangan dinyatakan positif apabila bilangan tersebut lebih dari nol. Karena itu, kamu akan menggunakan logika:

> **Jika** bilangan itu lebih dari 0, **maka** itu adalah bilangan positif.
**Jika** bilangan itu kurang dari 0, **maka** itu adalah bilangan negatif.
**Jika** bukan keduanya, **maka** bilangan itu adalah 0.
> 

Untuk menerapkan logika tersebut ke dalam program C++ kamu, kita akan mempelajari tentang beberapa struktur kondisional, seperti `if` dan `switch` statement.

## 1. If Statement

Statement ini digunakan untuk menguji kebenaran dari sebuah ekspresi.

```cpp
if (kondisi) {
	// lakukan sesuatu
}
```

Jika kondisi bernilai `true`, maka code atau perintah di dalam blok tersebut akan dijalankan. Contoh penggunakan `if` pada studi kasus sebelumnya:

> **Jika** bilangan itu lebih dari 0, **maka** itu adalah bilangan positif.
> 

```cpp
if (N > 0) {
	cout << "positif";
}
```

## 2. Else Clause

Sebelumnya, kamu sudah mencetak "positif" jika N lebih dari 0. Lalu bagaimana jika nilai N tidak lebih dari 0 atau kondisi bernilai `false`?

Kamu bisa menggunakan `else` statement untuk mengatasi itu. Statement `else` akan dijalankan ketika kondisi pada `if` bernilai `false`. Struktur penulisan `if...else` statement adalah:

```cpp
if (kondisi) {
	// lakukan sesuatu
} else {
	// lakukan sesuatu
}
```

Dengan statement ini, kamu bisa memodifikasi program sebelumnya.

> **Jika** bilangan itu lebih dari 0, maka itu adalah bilangan positif.
**Jika** **tidak**, maka itu bukan bilangan positif.
> 

```cpp
if (N > 0) {
	cout << "positif";
} else {
	cout << "bukan positif";
}
```

## 3. Else If Statement

Dalam studi kasus sebelumnya, kamu memiliki tiga kondisi:

> Jika bilangan itu lebih dari 0, maka itu adalah bilangan positif.
Jika bilangan itu kurang dari 0, maka itu adalah bilangan negatif.
Jika bukan keduanya, maka bilangan itu adalah 0.
> 

`if` dan `else` saja tidak akan cukup untuk membuat program tersebut berjalan sempurna. Di sinilah kamu harus menggunakan statement `else if`.

```cpp
if (kondisi) {
	// lakukan sesuatu
} else if (kondisi) {
	// lakukan sesuatu
} else {
	// lakukan sesuatu
}
```

Statement `else if` bisa digunakan setelah `if` dan sebelum `else`. Statement ini juga bisa digunakan berkali-kali.

```cpp
if (kondisi1) {
	// lakukan sesuatu
} else if (kondisi2) {
	// lakukan sesuatu
} else if (kondisi3) {
	// lakukan sesuatu
} else if (kondisi4) {
	// lakukan sesuatu
} else {
	// lakukan sesuatu
}
```

Jika `kondisi1` tidak terpenuhi, maka program akan memeriksa `kondisi2`. Jika masih belum terpenuhi, program akan memeriksa `kondisi3` dan seterusnya. Hal ini akan terus diulang sampai seluruh percabangan/kondisi habis. Jika tidak ada kondisi yang terpenuhi, maka program akan menjalankan perintah di dalam blok `else`. 

Sekarang kamu bisa menyempurnakan program sebelumnya menggunakan `else if`.

```cpp

#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	if (N > 0) {
		cout << "positif";
	} else if (N < 0) {
		cout << "negatif";
	} else {
		cout << "nol";
	}

	return 0;
}
```

## 4. Switch Statement

Statement `switch` adalah cara lain untuk melakukan pengkondisian, yang lebih mudah untuk ditulis dan dibaca. 

```cpp
switch(ekspresi) {
	case kondisi1:
		// lakukan sesuatu
		break;
	case kondisi2:
		// lakukan sesuatu
		break;
	default:
		// lakukan sesuatu
		break;
}
```

- `ekspresi` adalah variabel/nilai yang akan dibandingkan.
- `case` akan mengecek apakah ekspresi sesuai dengan kondisi yang diberikan.
- `break` digunakan untuk menghentikan blok `switch` jika kondisi terpenuhi.
- `default` akan dijalankan jika tidak ada kondisi yang terpenuhi (sama seperti `else`)

Kapan kamu bisa menggunakan `switch`? Lihat contoh program di bawah ini.

```cpp
if(x == 1) {
	cout << "satu";
} else if(x == 2) {
	cout << "dua";
} else if(x == 3) {
	cout << "tiga";
} else if(x == 4) {
	cout << "empat";
} else {
	cout << "pilih angka lain";
}
```

Pada program tersebut, ekspresi `x == N` ditulis berulang-ulang. Kamu bisa menulis ulang program tersebut dengan menggunakan `switch` statement.

```cpp
switch(x) {
	case 1:
		cout << "satu";
		break;
	case 2:
		cout << "dua";
		break;
	case 3:
		cout << "tiga";
		break;
	case 4:
		cout << "empat";
		break;
	default:
		cout << "pilih angka lain";
		break;
}
```

**Catatan:** Ketika menggunakan `switch`, kamu hanya bisa membandingkan satu ekspresi.