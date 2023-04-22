#include <iostream>

int main(int argc, char *argv[]){
  std::string input; 
  
  std::cout<<"Masukan angka: ";
  std::cin>>input;
  
  for (const auto& itr : input){
    if (!(itr >= '0' && itr <= '9')){
      std::cout<<"Input harus angka!";
      return 7;
    }
  }
  
  int parseInt = stoi(input);
  if (parseInt % 2 == 0){
    std::cout<<"Ini adalah bilangan genap.";
  } else { 
    std::cout<<"Ini adalah bilangan ganjil."; 
  }
}
