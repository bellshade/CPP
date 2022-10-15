#include <iostream>
#include <vector>

    // - at
    // - front
    // - back
    // - data
    // - operator[]

int main()
{
    std::vector <std::string> nama
    {
        "Aldi","Andre","Chairul"
    //   [0]     [1]     [3]
    };

    /*
        1. front & 2. back 
        adalah Element Access yang seharusnya kalian
        bisa paham dengan hanya sekali baca untuk memahaminya
        Yap, fungsi untuk mengakses nilai spesifik hanya depan / belakang
    */

    std::cout << nama.front() << std::endl;
    std::cout << nama.back() << std::endl;
    
    /*
        3. at
        Kita dapat menggunakan ini ketika ingin mengakses nilai tertentu
        bukan hanya mengakses nilai depan / belakang, ini dapat di gunakan dengan bebas

    */

    std::cout << nama.at(1) << std::endl;

    /*
        4. Operator[]
        Operator[] yang kita maksud disini hanyalah [] saja tanpa kata operatornya
        penjelasan yang ini hampir sama dengan at
    */

   std::cout << nama[0] << std::endl;

   /*
        5. data
        
   */

    return 0;
}
