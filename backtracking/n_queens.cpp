/**
* teka-teki delapan ratu adalah masalah
* menepatkan delapan ratu catur dengan papan catur
* ukuran 8*8 sehigga tidak ada dua ratu yang saling
* menyerang, demikian solusi mengharuskan tidak ada dua
* ratu yang berbagi baris,kolom atau  diagonal yan sama
*/

#include <array>
#include <cstddef>
#include <iostream>

namespace backtracking {
    namespace n_queens {
        template <size_t n>
        void printSolusi(const std::array<std::array<int, n>, n> board) {
            std::cout<<"\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    std::cout<<""<<board[i][j]<<"";
                }
                std::cout<<"\n";
            }
        }
        /**
        * periksa apakah ratu dapat
        * ditempatkan pada matriks
        * @tparam n jumlah ukuran dari matriks
        * @param board matriks tempat angka disimpan
        * @param row indeks row
        * @param col indeks kolom
        * @return `true` jika ratu bisa ditaruh
        * @return `false` jika ratu tidak bisa ditaruh
        */
        template <size_t n>
        bool isSafe(const std::array<std::array<int, n>, n> &board, const int &row, const int &col) {
            int i = 0, j = 0;
            
            // periksa baris di sisi kiri
            for (i = 0; i < col; i++) {
                if (board[row][i]) {
                    return false;
                }
            }
            
            // periksa diagonal atas di sisi kiri
            for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
                if (board[i][j]) {
                    return false;
                }
            }

            // periksa diagonal bawah di sisi kiri
            for (i = row, j = col; j >= 0 && i < n; i++, j--) {
                if (board[i][j]) {
                    return false;
                }
            }
            return true;
        }

        template <size_t n>
        void solveNQueen(std::array<std::array<int, n>, n> board, const int &col) {
            if (col >= n) {
                printSolusi<n>(board);
                return;
            }

            // pertimbangan kolom dan mencoba tempatkan
            // ratu di baris satu persatu
            for (int i = 0; i < n; i++) {
                // cek jika ratu bisa di tempatkan
                if (isSafe<n>(board, i, col)) {
                    board[i][col] = 1;
                    solveNQueen(board, col + 1);
                    board[i][col] = 0;
                }
            }
        }
    }
}

int main() {
    const int n = 4;
    std::array<std::array<int, n>, n> board = {
        std::array<int, n>({0, 0, 0, 0}), std::array<int, n>({0, 0, 0, 0}),
        std::array<int, n>({0, 0, 0, 0}), std::array<int, n>({0, 0, 0, 0})
    };
    backtracking::n_queens::solveNQueen<n>(board, 0);
    return 0;
}