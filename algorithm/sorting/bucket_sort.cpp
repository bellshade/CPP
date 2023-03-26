/**
 * bucket sort atau bin sort adalah algoritma sorting yang bekerja dengan
 * mendistribusikan elemen dari array ke dalam ember. setiap ember diurutkan
 * secara satu per satu, baik menggunakan algoritma yang beda atu ecara rekursif
 */
#include <algorithm>
#include <iostream>
#include <vector>

void sortingBucket(float arr[], int n) {
  // membuat ember kosong
  std::vector<float> *b = new std::vector<float>[n];

  // masukkan elemen array di dalam ember yang 
  // berbeda beda
  for (int i  = 0; i < n; i++) {
    // variable bi adalah indeks untuk di dalam
    // ember
    int bi  = n * arr[i];
    b[bi].push_back(arr[i]);
  }

  // sorting ember satu persatu
  for (int i = 0; i < n; i++)
    std::sort(b[i].begin(), b[i].end());

  // masukkan semua ember ke dalam  variabel arr[]
  int indeks = 0;
  for (int i = 0; i < n; i++)
    for (int j= 0; j < b[i].size(); j++)
      arr[indeks++] = b[i][j];
  delete[] b;
}

int main() {
  float arr[] = {0.871, 0.761, 0.651, 0.7192, 0.8888, 0.712};
  int n = sizeof(arr) / sizeof(arr[0]);
  sortingBucket(arr, n);

  std::cout<<"array yang sudah di sorting adalah\n";
  for (int i = 0; i < n; i++)
    std::cout<<arr[i]<<" ";
  return 0;
}
