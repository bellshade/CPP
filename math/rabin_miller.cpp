#include <cassert>
#include <iostream>
#include <random>
#include <vector>

/**
 * algoritma yang menentukan apakah suatu
 * bilangan yang diberikan cenderung prima
 * mirip dengan model uji primalitas fermat
 * dan rumus solovay strassen
 */
template <typename T> std::vector<T> reverse_biner(T angka) {
  std::vector<T> hasil;
  T temp = angka;
  while (temp > 0) {
    hasil.push_back(temp % 2);
    temp = temp / 2;
  }
  return hasil;
}

/**
 * fungsi eksponen modul
 * untuk memberikan  hasil masalah
 * eksponensial modular dengan relatif cepat
 */
template <typename T>
T modular_eksponen(T base, const std::vector<T> &eksponen_biner, T modulus) {
  if (modulus == 1) {
    return 0;
  }
  T b = 1;
  if (eksponen_biner.size() == 0) {
    return b;
  }
  T A = base;
  if (eksponen_biner[0] == 1) {
    b = base;
  }

  for (typename std::vector<T>::const_iterator iterator =
           eksponen_biner.cbegin() + 1;
       iterator != eksponen_biner.cend(); ++iterator) {
    A = A * A % modulus;
    if (*iterator == 1) {
      b = A * b % modulus;
    }
  }
  return b;
}

/**
 * fungsi untuk mengetes fungsi diatas
 */
template <typename T> bool testing(T d, T angka) {
  std::random_device rd_seed;
  std::mt19937 gen(rd_seed());
  std::uniform_int_distribution<> distribution(2, angka - 2);
  T random = distribution(gen);
  std::vector<T> pangkat = reverse_biner(d);
  T x = modular_eksponen(random, pangkat, angka);
  if (x == 1 || x == angka - 1) {
    return true;
  }

  while (d != angka - 1) {
    x = (x * x) % angka;
    d *= 2;
    if (x == 1) {
      return false;
    }
    if (x == angka - 1) {
      return true;
    }
  }
  return false;
}

template <typename T> bool testing_rabin_miller(T angka, T perulangan) {
  if (angka <= 4) {
    if (angka == 2 || angka == 3) {
      return true;
    } else {
      return false;
    }
  }
  if (angka % 2 == 0) {
    return false;
  }

  T d = angka - 1, r = 0;
  while (d % 2 == 0) {
    d = d / 2;
    r++;
  }

  for (T i = 0; i < perulangan; ++i) {
    if (!testing(d, angka)) {
      return false;
    }
  }
  return true;
}

int main() { testing_rabin_miller(2, 1); }
