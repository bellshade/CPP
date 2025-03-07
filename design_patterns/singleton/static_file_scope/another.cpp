static int var = 5; // untuk pembuktian lebih lanjut kamu bisa hilangkan `static` keyword-nya,
                    // kemudian lakukan kompilasi ulang,
                    // maka akan muncul error, karena tidah boleh ada 2 global variable (real) 
                    // yang bernama sama.

// fungsi yang me-return nilai `var` di file ini
int getVar () {
  return var;
}
