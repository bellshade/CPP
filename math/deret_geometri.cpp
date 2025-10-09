/**
 * @brief Program untuk mensimulasikan deret geometri.
 * 
 * Program ini menyediakan berbagai overload fungsi untuk menghitung 
 * suku ke-n, jumlah n suku pertama, serta memvisualisasikan deret 
 * geometri berdasarkan rasio dan suku awal yang diberikan.
 * 
 * @details
  * - Mengimplementasikan konsep *three-pair overload*, yaitu hanya satu fungsi utama
 *   yang bekerja dengan parameter berbasis iterator, sementara dua overload lainnya 
 *   (untuk parameter `initializer_list` dan tiga nilai langsung `a, r, n`) hanya 
 *   berperan sebagai pembungkus (*wrapper*) yang memanggil fungsi utama tersebut.  
 * - Dengan pendekatan ini, hanya ada satu sumber logika inti, sehingga memudahkan 
 *   pemeliharaan dan menghindari duplikasi kode.  
 * - Mendukung perhitungan berbasis bilangan bulat (integer-only) 
 *   sehingga tidak perlu mengkhawatirkan kesalahan presisi floating point.  
 * - Menggunakan indeks berbasis 0 (0-based indexing), artinya suku pertama 
 *   berada pada indeks 0.  
 * - Dapat digunakan untuk eksperimen atau pembelajaran konsep deret geometri 
 *   dengan parameter yang bervariasi.
 * 
 * @authors Muh Yusuf
 * @note Program ini bekerja dengan 0-based indexed.
 */
#include <concepts>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <cmath>
#include <vector>
#include <sstream>
#include <ranges>
#include <string>
/**
 * @brief Menghitung rasio (r) dari suatu deret geometri.
 *
 * @details
 * Fungsi ini bekerja dengan dua iterator (`first` dan `last`) yang merepresentasikan
 * rentang elemen dalam deret geometri. Nilai rasio ditentukan dengan membagi elemen
 * kedua dengan elemen pertama dari deret tersebut.
 * 
 */
template <std::input_iterator It>
auto rasio(It first,It last)
->std::common_type_t<std::iter_value_t<It>,std::size_t>
{   
    using common = std::common_type_t<std::iter_value_t<It>,std::size_t>;
    std::vector<common>deret(first,last);
    if(deret.size() < 2){
        return *deret.begin();
    }
    return deret[1] / deret[0];
}
template <std::input_iterator It>
requires(std::integral<std::iter_value_t<It>>)
auto rasio(It first,It last,std::size_t pos_1,std::size_t pos_2)
->std::common_type_t<std::iter_value_t<It>,std::size_t>
{
    std::vector<int>deret(first,last);
    if(deret.size() < 2){
        return *deret.begin(); //return suku pertama
    }
    using common = std::common_type_t<std::iter_value_t<It>,std::size_t>;
    auto val_pos1 = deret[pos_1];
    auto val_pos2 = deret[pos_2];
    common rhs = (pos_1 < pos_2) ? val_pos2 / val_pos1 : val_pos1 / val_pos2;
    double lhs = pos_1 < pos_2 ? pos_2 - 1: pos_1 - pos_2;
    common result = pow(rhs,1.0/lhs);
    return result;
}
/**
 * @brief Menghitung suku ke-n dari deret geometri.
 *
 * @details
 * Fungsi ini menerima dua iterator (`first`, `last`) yang menunjuk ke deret bilangan
 * geometri dan sebuah parameter `n` yang menunjukkan suku ke-n yang ingin dihitung.
 * 
 * Cara kerja:
 * 1. Menentukan rasio umum deret dengan memanggil fungsi `rasio()`.
 * 2. Mengambil nilai suku pertama (`a`).
 * 3. Menggunakan rumus dasar deret geometri:
 * 
 * U_n = a + r^(n - 1)
 * dimana:
 * Un = rumus suku ke-n
 * a = suku pertama
 * r = rasio
 * n = suku yang ingin diketahui
 * Nilai dikembalikan dalam tipe data yang merupakan hasil dari `std::common_type_t`
 * antara nilai iterator dan `std::size_t`.
 */
template <std::input_iterator It>
requires(std::integral<std::iter_value_t<It>>)
auto suku_keN(It first,It last,std::size_t n)
->std::common_type_t<std::iter_value_t<It>,std::size_t>
{
    using common = std::common_type_t<std::iter_value_t<It>,std::size_t>;
    common _rasio = rasio(first,last);
    std::vector<common>deret(first,last);
    common res = deret.front() * pow(_rasio,n - 1);
    return res;
}
/**
 * @brief Menghasilkan representasi string dari rumus umum suku ke-n deret geometri.
 *
 * @details
 * Fungsi ini menyusun rumus dalam bentuk teks menggunakan nilai suku pertama (`a`)
 * dan rasio (`r`) yang diperoleh dari deret.
 * 
 * Rumus yang dihasilkan berbentuk:
 * 
 * ```
 * Un = a * r^(n - 1)
 * ```
 */
template <std::input_iterator It>
requires(std::integral<std::iter_value_t<It>>)
std::string rumus_suku_KeN(It first,It last){
   // using common = std::common_type<std::iter_value_t<It>,std::size_t>;
    using type_iter = std::iter_value_t<It>;
    type_iter a = *first;
    type_iter r = rasio(first,last);
    std::ostringstream oss;
    oss << "Un = " << a << " + " << r << "^n - 1";
    return oss.str();
}
template <typename T>
requires(std::integral<T>)
//jika 2 diketahui 2 suku berurutan
T rasio(T suku_1,T suku_2){
    return suku_2 > suku_1 ? suku_2 / suku_1: suku_1 / suku_2;
}   
//jika tidak ketahui suku berurutan tetapi diberikan deret
template <typename T>
requires(std::integral<T>)
T rasio(std::initializer_list<T>arr){
    return rasio(arr.begin(),arr.end());
}
//jika diketahui 2 suku ke n yang tidak beurutan
template <typename T> 
requires(std::integral<T>)
auto rasio(std::initializer_list<T>arr,std::size_t pos_1,std::size_t pos_2)
->std::common_type_t<T,std::size_t>
{
    return rasio(arr.begin(),arr.end(),pos_1,pos_2);
}
//jika diketahui deret
template <std::ranges::input_range arr>
requires (std::integral<std::ranges::range_value_t<arr>>)
auto rasio(arr&& R){
    return rasio(R.begin(),R.end());
}
template <std::ranges::input_range arr>
requires (std::integral<std::ranges::range_value_t<arr>>)
auto rasio(arr&& R,std::size_t pos_1,std::size_t pos_2){
    return rasio(R.begin(),R.end(),pos_1,pos_2);
}
template <typename T> 
requires(std::integral<T>)
auto suku_keN(std::initializer_list<T>arr,std::size_t n){
    return suku_keN(arr.begin(),arr.end(),n);
}
template <std::ranges::input_range arr>
requires (std::integral<std::ranges::range_value_t<arr>>)
auto suku_keN(arr&& R,std::size_t n){
    return suku_keN(R.begin(),R.end(),n);
}
template <typename T> 
requires(std::integral<T>)
std::string rumus_suku_KeN(std::initializer_list<T>arr){
    return rumus_suku_KeN(arr.begin(),arr.end());
}
template <std::ranges::input_range arr>
requires (std::integral<std::ranges::range_value_t<arr>>)
std::string rumus_suku_KeN(arr&& R){
    return rumus_suku_KeN(R.begin(),R.end());
}
int main(){
    using namespace std;
    cout << "jika hanya diketahui 2 suku berurutan" << endl;
    cout << "hasil: " << rasio(2,4) << endl;
    cout << "jika diketahui 2 suku tidak berurutan(base on index)" << endl;
    cout << "hasil: "<< rasio({2,4,8,16},0,2) << endl;
    std::vector<int>a = {3,6,12,24};
    cout << "menggunakan ranges" << endl;
    cout << rasio(a) << endl;
    cout << "rumus suku keN" << endl;
    cout << "rumus: " << rumus_suku_KeN(a) << std::endl;
    //Menggunakan iterator langsung (begin, end)
    cout << "[4] Menggunakan iterator langsung\n";
    vector<int> deret1 = {2, 6, 18, 54};
    cout << "rasio(deret1.begin(), deret1.end()) = "
         << rasio(deret1.begin(), deret1.end()) << endl;
    // Menghitung nilai suku ke-n (iterator)
    cout << "[8] Nilai suku ke-n (iterator)\n";
    vector<int> deret3 = {3, 6, 12, 24};
    cout << "suku_keN(deret3.begin(), deret3.end(), 5) = "
         << suku_keN(deret3.begin(), deret3.end(), 5) << "\n\n";
    std::cin.get();
    return 0;
}