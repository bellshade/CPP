/**
 * knapsack adalah masalah yang mana seorang
 * berhadapan dengan persoalan optimasi  pemilihan
 * benda mana yang bisa ditampung dalam wadah berkapasitas
 * terbatas. optimasi dimasukkan ke dalam suatu wadah yang
 * dimaksud diahasilkan keuntungan semaksimal mungkin.
 */
#include <iostream>

struct Item {
    int ukuran;
    int profit;
};

float profitPerUnit(Item x) { return (float)x.profit / (float)x.ukuran; }

/**
 * algoritma greedy yang merupakan teknik pemogramn yang kerap kali digunakan
 * dalam mengatasi permasalahan optimasi. cara kerja algoritma ini yaitu dengn
 * menggunakan heuristic dalam mencari solusi suboptium dengan harapan solusi
 * optimum.
 */

int partisi(Item arr[], int low, int high) {
    Item pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        // jika element lebih kecil maka bisa
        // di dalam
        if (profitPerUnit(arr[j]) <= profitPerUnit(pivot)) {
            i++;
            Item temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Item temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(Item arr[], int low, int high) {
    if (low < high) {
        int p = partisi(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    int n;
    float kapasitas;
    std::cout << "\nmasukkan kapasitas dari wadah: ";
    std::cin >> kapasitas;
    std::cout << "\nmasukkan angka dari item: ";
    std::cin >> n;
    Item itemArray[n];

    for (int i = 0; i < n; i++) {
        std::cout << "\nmasukkan ukuran dan profit dari item " << i + i
                  << " : ";
        std::cin >> itemArray[i].ukuran;
        std::cin >> itemArray[i].profit;
    }

    quickSort(itemArray, 0, n - 1);

    float maxProfit = 0;
    int i = n;
    while (kapasitas > 0 && --i >= 0) {
        if (kapasitas >= itemArray[i].ukuran) {
            maxProfit += itemArray[i].profit;
            kapasitas -= itemArray[i].ukuran;
            std::cout << "\n\t" << itemArray[i].ukuran << "\t"
                      << itemArray[i].profit;
        } else {
            maxProfit = profitPerUnit(itemArray[i]) * kapasitas;
            std::cout << "\n\t" << kapasitas << "\t"
                      << profitPerUnit(itemArray[i]) * kapasitas;
            kapasitas = 0;
            break;
        }
    }
    std::cout << "\nmaks profit : " << maxProfit;
    return 0;
}
