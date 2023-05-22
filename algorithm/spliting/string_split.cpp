#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>

/**
 * @brief Melakukan split pada string
 *
 * @param str string
 * @param delim delimeter
 * @return std::vector<std::string>
 */
std::vector<std::string> string_spit(const std::string& str, const char delim) {
  // membuat vector (container) untuk menampung string yang di split
  std::vector<std::string> result = {};

  for (auto first = str.begin(); first < str.end();) {
    // mencari lokasi `delim` di `str`
    auto last = std::find(first, str.end(), delim);  // iterator

    // men-construct string menggunakan iterator `first` and `last`
    std::string word = std::string(first, last);

    // menambahkan `word` di akhir vector
    result.push_back(word);

    // increment untuk `for-loop`
    // `last + 1` agar delimeter sebelumnya di lewati
    first = last + 1;
  }

  return result;
}

void test() {
  std::string str{};
  std::vector<std::string> splitted_words{};

  // test 1
  str = "Hello world";
  splitted_words = {"Hello", "world"};
  assert(string_spit(str, ' ') == splitted_words);
  std::cout << "Test #1: Berhasil\n";

  // test 2
  str = "carry-wilder-rubble-elated-duplicity";
  splitted_words = {"carry", "wilder", "rubble", "elated", "duplicity"};
  assert(string_spit(str, '-') == splitted_words);
  std::cout << "Test #2: Berhasil\n";
}

/**
 * @brief Mencetak `vector` ke console/terminal
 *
 * @param vec vector
 */
template <class T>
void print_vector(const std::vector<T>& vec) {
  auto concat = [&](auto dest, auto x) {
    auto src = x;
    if (dest.empty()) {
      return dest + src;
    }
    return dest + ", " + src;
  };

  std::cout << "{";
  std::cout << std::accumulate(vec.begin(), vec.end(), std::string{}, concat);
  std::cout << "}\n";
}

int main() {
  test();

  auto vec = string_spit("Selamat Pagi", ' ');
  print_vector(vec);
};
