/**
 * @brief program untuk memsimulasikan algoritma powerSet yang digunakan
 * untuk mendapatkan semua sub himpunan dari semua himpunan.
 * 
 * @author yusuf
 * @date 9 september 2025
 */
#include <bits/stdc++.h>
/**
 * @brief powerSet adalah salah satu algoritma untuk mendapatkan semua subset
 * sebuah himpunan(set),ini dibutuhkan ketika menghadapi masalah/problem seperti
 * perfect sum.algoritma ini memiliki 2 metode untuk mengaplikasinnya yaitu
 * backtracking dan bitmasking,Contoh dibawah memakai bitmasking
 * 
 * jika kita punya n element,maka banyak subset adalah 2^n.
 * bilangan biner dengan n bit dapat membentuk tepat 2^n kombinasi
 * misal n = 3,maka total subset adalah 2^3 = 8
 * semua bilangan biner 3 bit mulai 000(0) sampai 111(7) bisa dipakai untuk
 * mewakili subset
 * 
 * aturannya:
 *  bit ke-j = 1 ->element ke -j masuk subset
 *  bit ke-j = 0 ->element ke j tidak masuk subset
 * @details Time complexity O(n^2),Space Complexity O(n)
 */
void PowerSet(){
    std::vector<int>nums = {1,2,3};
    int n = nums.size();
    for(int mask = 0;mask < (1 << n);mask++){ //iterasi sampai 2^n(banyak subset)
        std::vector<int>subset;
        for(int i = 0;i < n;i++){ 
            if(mask & (1 << i)){ // cek apakah bit ke i menyala
                subset.push_back(nums[i]);
            }
        }
        std::cout << "{ ";
        for(auto x: subset){
            std::cout << x << " ";
        }
        std::cout << "}";
    }
    
}
int main(){
    PowerSet();
    std::cin.get();
    return 0;
}