#include <iostream>

int main(int argc, char *argv[]){
  std::string input; 
  
  std::cout<<"Masukan angka: ";
  std::cin>>input;
  
  // Setiap karakter akan diperiksa untuk memastikan bahwa input harus berupa angka.
  for (const auto& itr : input){
    if (!(itr >= '0' && itr <= '9')){
      std::cout<<"Input harus angka!";
      return 7; // Nilai 7 biasanya menunjukkan adanya kesalahan dalam program.
    }
  }
  
  int parseInt = stoi(input); // Konversi string input menjadi integer dan menyimpannya ke variabel parseInt.
  if (parseInt % 2 == 0){
    std::cout<<"Ini adalah bilangan genap.";
  } else { 
    std::cout<<"Ini adalah bilangan ganjil."; 
  }
}
