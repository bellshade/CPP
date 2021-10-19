/**
 * \file
 * \brief selesaikan persamaan \f$f(x) = 0\f$ menggunakan metode bisection
 * informasi tentang bisection
 * https://en.wikipedia.org/wiki/Bisection_method
 * diberikan dua point \f$a\f$ dan \f$b\f$ seperti yang \f$f(a)<0\f$ dan
 * \f$f(b) > 0\f$ maka \f$(i+1)^\text{th}\f$ pendekatan yang diberikan oleh:
 * \f[
 * x_{i+1} = \frac{a_i+b_i}{2}
 * \f]
 *
 * untuk iterasi berikutnya, interval dipilih sebagai
 * \f$[a,x]\f$ jika \f$x>0\f$ atau \f$[x, b]\f$ if \f$<0\f$.
 * prosesnya adalah dilanjutkan sampai pendekatan yang cukup dekat tercapai
 * */

#include <cmath>
#include <iostream>
#include <limits>

#define EPSILON \
  1e-6 // std::numeric_limits<double>::epsilon()
#define MAX_ITERATIONS 50000 ///<Jumlah maksimum iterasi untuk dieriksa

/**
 * definisikan \f$f(x)\f$ untuk mencari akar untuk
 * */

static double eq(double i){
  // persamaan asli
  return (std::pow(i, 3) - (4 * i) - 9);
}

// dapatkan tanda dari nomor yang diberikan

template <typename T>
int sgn(T val){
  return (T(0) < val) - (val < T(0));
}

// main()

int main(){
  double a = -1, b = 1, x, z;
  int i;

  for(int i = 0; i < MAX_ITERATIONS; i++){
    z = eq(a);
    x = eq(b);
    // tanda yang sama, kemudian tingkatkan interval
    if (sgn(z) == sgn(x)){
      b++;
      a--;
    }
    else{
      break;
    }
  }
  std::cout<<"\nInisial pertama: "<<a;
  std::cout<<"\nInisial kedua: "<<b;
  
  // mulai iterasi
  for(i =0; i < MAX_ITERATIONS; i++){
    x = (a + b) / 2;
    z = eq(x);
    std::cout<<"\n\nz: "<<z<<"\t["<<a<<" ,"<<b<<" | Bisect: "<<x<<"]";
    if (z < 0){
      a = x;
    }
    else{
      b = x;
    }
    
    if (std::abs(z) < EPSILON)
      break;
  }
  std::cout<<"\n\nAkar: "<<x<<"\t\tLangkah: "<<i<<std::endl;
  return 0;
}

