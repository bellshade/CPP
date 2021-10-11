/**
 * @file
 * @brief 
 * mengembalikan nilai terpanjang / dan terpendek
 * algoritma minimax bisa dilihat disini
 * https://en.wikipedia.org/wiki/Minimax
 * @details
 * minimax adalah sebuah aturan keputusan
 * yang digunakan dalam kecerdasan buatan, teori permainan
 * statistik, dan teori keputusan dan
 * untuk meminimalisir (kemungkinan) kerugian untuk beberapa
 * skenario (kerugian maksimum)
 * ketika berhadapan dengan keuntungan, ini disebut dengan maximin
 * untuk memaksimalkan nilai keuntungan minimum
 * awalnya diformulasikan untuk teori permainan zero-sum dua pemain,
 * yang mencakup kasus di mana pemain mengambil gerakan alternatif dan mereka
 * juga melakukan gerakan simultan, itu juga telah diperluas ke permain yang lebih
 * kompleks dan pengambilan keputusan umum di hadapan ketidakpastian
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <array>
namespace backtracking {
    /**
        * periksa nomor mana yang  maksimum / minimum dalam array
        * @param depth = kedalaman saat ini di dalam pohon permainan
        * lebih singkat tentang pohon permainan
        * https://en.wikipedia.org/wiki/Game_tree
        * @param nodex_index = indeks saat ini dalam array
        * @param is_max = jika index saat ini adalah angka terpanjang
        * @param score = menyimpan di dalam array
        * @param height = tinggi maksimum untuk pohon permainan
        * @return max atau min dari angka
        */
template <size_t T>
int minimax(int depth, int node_index, bool is_max,
            const std::array<int, T> &scores, double height) {
    if (depth == height) {
        return scores[node_index];
    }

    int v1 = minimax(depth + 1, node_index * 2, !is_max, scores, height);
    int v2 = minimax(depth + 1, node_index * 2 + 1, !is_max, scores, height);

    return is_max ? std::max(v1, v2) : std::min(v1, v2);
    }
}

int main() {
    std::array<int, 8> scores = {90, 23, 6, 33, 21, 65, 123, 34423};
    double height = log2(scores.size());

    std::cout << "Optimasi value: " << backtracking::minimax(0, 0, true, scores, height)
              << std::endl;
    return 0;
}
