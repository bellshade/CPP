#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <iostream>

template <typename T>
double perpangkatan_rekursif(T a, T b){
  if (b < 0)
    return 1.0 / perpangkatan_rekursif(a, -b);

  if (b == 0)
    return 1;

  T bwh = perpangkatan_rekursif(a, b >> 1);

  double hasil;
  if ((b & 1) == 0)
    hasil = bwh * bwh;
  else
    hasil = bwh * bwh * a;

  return hasil;
}

template <typename T>
double perpangkatan_linear(T a, T b){
  if (b < 0)
    return 1.0 / perpangkatan_linear(a, -b);

  double hasil = 1;
  while(b){
    if (b & 1)
      hasil = hasil * a;
    a = a * a;
    b = b >> 1;
  }
  
  return hasil;
}

int main(){
  std::srand(std::time(nullptr));
  std::ios_base::sync_with_stdio(false);

  std::cout<<"test perpangkatan .."<<std::endl;
  for (int i = 0; i < 20; i++){
    int a = std::rand() % 20 - 10;
    int b = std::rand() % 20 - 10;

    std::cout<<std::endl<<"kalkulasi "<<a<<"^"<<b<<std::endl;
    assert(perpangkatan_rekursif(a, b) == std::pow(a, b));
    assert(perpangkatan_linear(a, b) == std::pow(a, b));
    std::cout<<"-----"<<a<<"^"<<b<<"="<<perpangkatan_rekursif(a, b)<<std::endl;
  }
  
  int64_t a, b;
  std::cin >> a >> b;
  std::cout<<a<<"^"<<b<<"="<<perpangkatan_rekursif(a,b)<<std::endl;

  std::cout<<a<<"^"<<b<<"="<<perpangkatan_linear(a,b)<<std::endl;

  return 0;
}

