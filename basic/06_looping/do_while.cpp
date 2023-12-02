#include <iostream>

int main()
{
    // membuat perulangan menggunakan do while

    /*
        do while :
        adalah perulangan di mana perulangan akan dilakukan
        minimal sekali walau kondisi tidak terpenuhi
    */

    int i = 1; // variabel awal / nilai awal

    do
    {
        // akan menampilkan hello world minimal sekali
        // dan menampilkan hello word berikutnya jika kondisi terpenuhi
        std::cout << "Hello World\n";
    } while (i <= 5); // jika i <= 5 maka akan melanjut kan perulangannya

    return 0;
}