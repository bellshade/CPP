
/**
 * @namespace artificial_intelligence
 * @brief algoritma knn
 */
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <numeric>
#include <unordered_map>
#include <utility>
#include <vector>
namespace artificial_intelligence {
/**
 * @brief fungsi k nearest neighbour
 */
namespace k_nearest_neighbour {
/**
 * @brief menghitung jarak euclidean antara dua vektor
 * @param T tipe data vektor
 * @param a vektor pertama
 * @param b vektor kedua
 * @return double nilai jarak euclidean antara kedua vektor
 */
template <typename T>
double jarak_euclidean(const std::vector<T> &a, const std::vector<T> &b) {
  std::vector<double> hasil_antara;
  std::transform(
      a.begin(), a.end(), b.begin(), std::back_inserter(hasil_antara),
      [](T elemen1, T elemen2) { return std::pow((elemen1 - elemen2), 2); });
  // kecilin ukuran dari vektor
  hasil_antara.shrink_to_fit();
  return std::sqrt(
      std::accumulate(hasil_antara.begin(), hasil_antara.end(), 0.0));
}

/**
 * @brief class dari knn menggunakan jarak euclidean sebagai metriks dari jarak
 */
class knn {
private:
  // vektor attribut
  std::vector<std::vector<double>> X_;
  std::vector<int> Y_;

public:
  /**
   * @brief buat jarak knn terdekat
   * @param X vektor attribut
   * @param Y vektor label
   */
  explicit knn(std::vector<std::vector<double>> &X, std::vector<int> &Y)
      : X_(X), Y_(Y){};
  // copy konstruktor
  knn(const knn &model) = default;
  // copy assignment
  knn &operator=(const knn &model) = default;
  // pindah konstruktor
  knn(knn &&) = default;
  // pindah juga assigmentnya
  knn &operator=(knn &&) = default;
  // lalu buat destruktor
  ~knn() = default;

  /**
   * @brief klasifikasikan sampel
   * @param sampel sample yang ingin diklasifikasikan
   * @param k jumlah neighbour yang mau dilihat
   * @return int label dari neighbour yang paling sering muncul
   */
  int prediksi(std::vector<double> &sampel, int k) {
    std::vector<int> neighbour;
    std::vector<std::pair<double, int>> jarak;

    // hitung jarak euclidean antara sampel dan setiap data dalam
    // sebuah dataset
    for (std::size_t i = 0; i < this->X_.size(); ++i) {
      auto data_sekarang = this->X_.at(i);
      auto label = this->Y_.at(i);
      auto jarak_data = jarak_euclidean(data_sekarang, sampel);
      jarak.emplace_back(jarak_data, label);
    }

    // urutkan jarak berdasarkan kedekatan
    std::sort(jarak.begin(), jarak.end());

    // ambil label dari knn
    for (int i = 0; i < k; i++) {
      auto label = jarak.at(i).second;
      neighbour.push_back(label);
    }

    // hitung frekuensi dari setiap label
    std::unordered_map<int, int> frekuensi;
    for (auto label : neighbour) {
      ++frekuensi[label];
    }

    // temukan label dengan frekuensi tertinggi
    std::pair<int, int> prediksi;
    // label hasil prediksi
    prediksi.first = -1;
    // frekuensi tertinggi
    prediksi.second = -1;

    for (auto &pasangan : frekuensi) {
      if (pasangan.second > prediksi.second) {
        prediksi.second = pasangan.second;
        prediksi.first = pasangan.first;
      }
    }
    // return hasil prediksi
    return prediksi.first;
  }
};
} // namespace k_nearest_neighbour
} // namespace artificial_intelligence

/**
 * @brief fungsi untuk testing knn
 */
static void uji() {
  std::cout << "testing knn" << std::endl;
  std::vector<std::vector<double>> X1 = {{0.0, 0.0}, {0.25, 0.25}, {0.0, 0.5},
                                         {0.5, 0.5}, {1.0, 0.5},   {1.0, 1.0}};
  std::vector<int> Y1 = {1, 1, 1, 1, 2, 2};
  auto model1 = artificial_intelligence::k_nearest_neighbour::knn(X1, Y1);
  std::vector<double> sampel_pertama = {1.2, 1.2};
  assert(model1.prediksi(sampel_pertama, 2) == 2);
  std::cout << "testing pass" << std::endl;
}

int main() {
  uji();
  return 0;
}
