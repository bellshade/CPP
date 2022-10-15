#include <iostream> // I/O
#include <fstream>

/*
Header <fstream>
- ifstream // untuk membaca (In fstream)
- ofstream // untuk menulis (Out fstream)
- fstream // gabungan dari ifstream & ofstream

Parameter <fstream>
- out
- in 
- binary
- trunc
*/

struct baca_data{
    std::string input_file;
    std::ifstream in;
    std::ofstream out;

    baca_data(std::string file){
        this->input_file = file;
    }

    void inspect(){
        std::string data;;
		baca_data::in.open(baca_data::input_file);
		while(!baca_data::in.eof()){
			// 1. cara lama = baca_data::in >> data;
            getline(baca_data::in, data);
			std::cout << data << "\n";
		}
		baca_data::in.close();
    }
};

int main()
{
    /*
    Disini saya akan mendemonstrasikan cara penggunaan fstream untuk pemula
    Materi: 
        1. Cara menulis ke file.txt
        2. Membaca file.txt
    */

    // 2a. Mambaca file.txt dasar
    /*
        std::ifstream baca;
        baca.open("file.txt"); 
        std::string buffer; 
        baca >> buffer;
        std::cout << buffer;
        baca.close();
    */

    // 2b. Membaca file.txt dengan getline 
    /*
        std::ifstream baca;
        baca.open("file.txt"); 
        std::string buffer; 
        getline(baca,buffer);
        std::cout << buffer;
        baca.close();
    */

    // 2c. Membaca file.txt dengan looping
    /*
        std::ifstream baca;
        std::string buffer;
        baca.open("file.txt");
        while(!baca.eof()){ 
            getline(baca,buffer);
            std::cout << buffer << "\n";
        }
        baca.close();
    */
    
    // 2d. Membaca file.txt dengan struct
    baca_data baca = baca_data("file.txt");
    baca.inspect();

    return 0;
}
