/**
 * @file quadratic_formula.cpp
*/

#include<iostream>
#include<cmath>

/**
  * @brief program ini merupakan untuk check apakah
  * parameter a,b,c untuk mengatur equation tersebut
  * @param a equation a
  * @param b equation b
  * @param c equation c
*/
void quadratic_formula(int a,int b,int c){
    if (a != 0){
        float descriminant=(pow(b,b)-(4 * a *c));
        if (descriminant>0){
            float x1=(-b + sqrt(descriminant))/(2 * a);
            float x2=(-b - sqrt(descriminant))/(2 * a);
            std::cout<<"X1="<<x1<<"\n"<<"X2="<<x2<<'\n';
        }else if (descriminant ==0){
            return ;
        }
        else{
            std::cout<<"hasilnya berupa imajiner\n";
        }
    }
}

int main(){
    // mari kita coba a=1,b=2,c=6
    quadratic_formula(1,2,6);
    // mari kita coba a=1,b=3,c=6
    quadratic_formula(1,3,6);

    return 0;
}