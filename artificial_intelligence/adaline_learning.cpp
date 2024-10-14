#include <array>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <numeric>
#include <vector>
constexpr int MAKS_ITERASI = 500;

/**
 * @namespace artificial_intelligence
 * @brief algoritma machine learning
 */
namespace artificial_intelligence {
class adaline {
public:
  /**
   * @brief konstruktor default
   * @param jumlah_fitur jumlah fitur yang ada
   * @param laju_pembelajaran nilai laju training
   * @param akurasi nilai akurasi konvergensi
   */
  explicit adaline(int jumlah_fitur, const double laju_pembelajaran = 0.01f,
                   const double akurasi = 1e-5)
      : laju_pembelajaran(laju_pembelajaran), akurasi(akurasi) {
    if (laju_pembelajaran <= 0) {
      std::cerr << "laju pembelajaran harus positif dan tidak nol" << std::endl;
      std::exit(EXIT_FAILURE);
    }

    // inisialisasi bobot dengan nilai acak di range [-50, 49]
    bobot = std::vector<double>(jumlah_fitur + 1);
    // inisialisasi bobot awal dengan nilai 1
    for (double &bobot_satuan : bobot)
      bobot_satuan = 1.f;
  }

  // buat operator untuk mencetak bobot model
  friend std::ostream &operator<<(std::ostream &keluar, const adaline &ada) {
    keluar << "<";
    for (int i = 0; i < ada.bobot.size(); i++) {
      keluar << ada.bobot[i];
      if (i < ada.bobot.size() - 1) {
        keluar << ", ";
      }
    }
    keluar << ">";
    return keluar;
  }

  /**
   * @brief prediksi keluaran model untuk set fitur tertentu
   * @param x vektor input
   * @param out keluaran opsional, mengembalikan output neuron sebelum aktivasi
   * @return keluaran prediksi model
   */
  int prediksi(const std::vector<double> &x, double *keluaran = nullptr) {
    if (!cek_kecocokan_ukuran(x)) {
      return 0;
    }
    // nilai bias
    double y = bobot.back();
    // hitung nilai y dari input dan bobot
    y = std::inner_product(x.begin(), x.end(), bobot.begin(), y);

    if (keluaran != nullptr) {
      *keluaran = y;
    }
    return aktivasi(y);
  }

  /**
   * @brief memperbarui bobot model denga menggunakan training untuk satu vektor
   * @param x vektor fitur
   * @param y nilai keluaran yang diketahui
   * @return faktor koreksi
   */
  double pelatihan(const std::vector<double> &x, const int &y) {
    if (cek_kecocokan_ukuran(x)) {
      return 0;
    }

    // output model dengan bobot saat ini
    int p = prediksi(x);
    int kesalahan_prediksi = y - p;
    double faktor_koreksi = laju_pembelajaran * kesalahan_prediksi;

    for (int i = 0; i < x.size(); i++) {
      bobot[i] += faktor_koreksi * x[i];
    }
    bobot[x.size()] += faktor_koreksi;
    return faktor_koreksi;
  }

  /**
   * @brief memperbarui bobot mdel menggunakan training untuk array vektor
   * @param x array vektor fitur
   * @param y nilai keluaran yang diketahui untuk setiap vektor fitur
   */
  template <size_t N>
  void pelatihan(std::array<std::vector<double>, N> const &X,
                 std::array<int, N> const &Y) {
    double rata_kesalahan_prediksi = 1.f;
    int iterasi = 0;

    for (iterasi = 0;
         (iterasi < MAKS_ITERASI) && (rata_kesalahan_prediksi > akurasi);
         iterasi++) {
      rata_kesalahan_prediksi = 0.f;
      for (int i = 0; i < N; i++) {
        double err = pelatihan(X[i], Y[i]);
        rata_kesalahan_prediksi += std::abs(err);
      }
      rata_kesalahan_prediksi /= N;
      std::cout << "\tIterasi " << iterasi << ": Bobot training: " << *this
                << "\tRata-rata error: " << rata_kesalahan_prediksi
                << std::endl;
    }

    if (iterasi < MAKS_ITERASI) {
      std::cout << "konvergen setelah " << iterasi << " iterasi" << std::endl;
    } else {
      std::cout << "tidak konvergen setelah " << iterasi << " iterasi"
                << std::endl;
    }
  }

  /**
   * @brief fungsi aktivasi sebagai fungsi heaviside
   * @param x nilai untuk diaktivasi
   * @return hasil aktivasi
   */
  int aktivasi(double x) { return x > 0 ? 1 : -1; }

private:
  bool cek_kecocokan_ukuran(const std::vector<double> &x) {
    if (x.size() != (bobot.size() - 1)) {
      std::cerr
          << __func__ << ": "
          << "jumlah fitur dalam x tidak cocok dengan dimensi fitur model!";
      return false;
    }
    return true;
  }
  const double laju_pembelajaran;
  const double akurasi;
  std::vector<double> bobot;
};
} // namespace artificial_intelligence

using artificial_intelligence::adaline;

/**
 * @brief fungsi pengujian untuk memprediksi titik dalam sistem koordinat 2D
 *        memisahkan di atas garis x=y sebagai +1 dan lainnya sebagai -1
 * @param laju_pembelajaran laju pembelajaran (default = 0.01)
 */
void pengujian1(double laju_pembelajaran = 0.01) {
  adaline ada(2, laju_pembelajaran);

  // jumlah sample
  const int N = 10;

  // data fitur dan label keluaran
  std::array<std::vector<double>, N> X = {
      std::vector<double>({0, 1}),   std::vector<double>({1, -2}),
      std::vector<double>({2, 3}),   std::vector<double>({3, -1}),
      std::vector<double>({4, 1}),   std::vector<double>({6, -5}),
      std::vector<double>({-7, -3}), std::vector<double>({-8, 5}),
      std::vector<double>({-9, 2}),  std::vector<double>({-10, -15})};

  // label keluaran
  std::array<int, N> y = {1, -1, 1, -1, -1, -1, 1, 1, 1, -1};

  std::cout << "pengujian pertama" << std::endl;
  std::cout << "model sebelum pelatihan: " << ada << std::endl;

  ada.pelatihan<N>(X, y);
  std::cout << "model setelah pelatihan: " << ada << std::endl;

  int prediksi = ada.prediksi({5, -3});
  std::cout << "prediksi untuk x=(5, 3): " << prediksi;
  assert(prediksi == -1);
  std::cout << "... berhasil !" << std::endl;

  prediksi = ada.prediksi({5, 8});
  std::cout << "prediksi untuk x=(5, 8): " << prediksi;
  assert(prediksi == 1);
  std::cout << "... berhasil !" << std::endl;
}

int main() {
  std::srand(std::time(nullptr));
  pengujian1();
  return 0;
  return 0;
}
