// knight tour dlah urutn gerakan ksatria papan catur
// sehingg ksatria mengunjungi setiap kotak hanya sekali.
// jika ksatria berakhir pada kota yang merupakan langkah
// satu ksatria dari awal persegi (gara bisa langsung
// tur papan lgi, berikut jalur yang sama, tur ditutup;
// jika tidak maka akan terbuka)

#include <array>     
#include <iostream>  

namespace backtracking {
    namespace knight_tour {
        template <size_t V>
        bool issafe(int x, int y, const std::array<std::array<int, V>, V> &sol) {
            return (x < V && x >= 0 && y < V && y >= 0 && sol[x][y] == -1);
        }
        
        template <size_t V>
        bool solve(int x, int y, int mov, std::array<std::array<int, V>, V> &sol, const std::array<int, V> &xmov, std::array<int, V> &ymov) {
            int k = 0, xnext = 0, ynext = 0;

            if (mov == V * V) {
                return true;
            }

            for (k = 0; k < V; k++) {
                xnext = x + xmov[k];
                ynext = y + ymov[k];

                if (issafe<V>(xnext, ynext, sol)) {
                    sol[xnext][ynext] = mov;

                    if (solve<V>(xnext, ynext, mov + 1, sol, xmov, ymov) == true) {
                        return true;
                    } else {
                        sol[xnext][ynext] = -1;
                    }
                }
            }
            return false;
        }
    }  
}  


int main() {
    const int n = 8;
    std::array<std::array<int, n>, n> sol = {0};

    int i = 0, j = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            sol[i][j] = -1;
        }
    }

    std::array<int, n> xmov = {2, 1, -1, -2, -2, -1, 1, 2};
    std::array<int, n> ymov = {1, 2, 2, 1, -1, -2, -2, -1};

    sol[0][0] = 0;

    bool flag = backtracking::knight_tour::solve<n>(0, 0, 1, sol, xmov, ymov);
    if (flag == false) {
        std::cout << "Error: solusi tidak ditemukan\n";
    } else {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                std::cout << sol[i][j] << "  ";
            }
            std::cout << "\n";
        }
    }
    return 0;
}
