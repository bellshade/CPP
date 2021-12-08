/**
 * @file sudoku_solve.cpp
 * @author your name (you@domain.com)
 * sudoku disebut dengan number placement game.
 * informasi lebih lanjut tentang sudoku
 * https://en.wikipedia.org/wiki/Sudoku
 */

#include <array>
#include <iostream>

namespace backtraking{
    /**
     * @brief fungsi dari sudoku
     */
    namespace sudoku_solver{
        template <size_t V>
        bool isPossible(const std::array<std::array<int, V>, V> &mat, int i, int j, int no, int n){
            for (int x = 0; x < n; x++){
                if (mat[x][j] == no || mat[i][x] == no){
                    return false;
                }
            }
            
            int sx = ( i / 3) * 3;
            int sy = (j / 3) * 3;

            for (int x = sx; x < sx + 3; x++){
                for(int y = sy; y < sy + 3; y++){
                    if (mat[x][y] == no){
                        return false;
                    }
                }
            }
            return true;
        }

        template <size_t V>
        void printMat(const std::array<std::array<int, V>, V> &mat, const std::array<std::array<int, V>, V> &starting_mat, int n){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if (starting_mat[i][j] != mat[i][j]){
                        std::cout<<"\033[93m"<<mat[i][j]<<"\033[0m"<<" ";
                    }else{
                        std::cout<<mat[i][j]<<" ";
                    }
                    if ((j + 1) % 3 == 0){
                        std::cout<<'\t';
                    }
                }
                if ((i + 1) % 3 == 0){
                    std::cout<<std::endl;
                }
                std::cout<<std::endl;
            }
        }

        template <size_t V>
        bool solveSudoku(std::array<std::array<int, V>, V> &mat, const std::array<std::array<int, V>, V> &starting_mat, int i, int j){
            if(i == 9){
                printMat<V>(mat, starting_mat, 9);
                return true;
            }
            if (j == 9)[
                return solveSudoku<V>(mat, starting_mat, i + 1, 0);
            ]
            if (mat[i][j] != 0){
                return solveSudoku<V>(mat, starting_mat, i, j + 1);
            }
            for (int no = 1; no <= 9; no++){
                if (isPossible<V>(mat, i, j, no, 9)){
                    mat[i][j] = no;
                    bool solution_found = solveSudoku<V>(mat, starting_mat, i, j + 1);
                    if (solution_found){
                        return true;
                    }
                }
            }
            
            mat[i][j] = 0;
            return false;
        }
    }
}

int main() {
    const int V = 9;
    std::array<std::array<int, V>, V> mat = {
        std::array<int, V>{5, 3, 0, 0, 7, 0, 0, 0, 0},
        std::array<int, V>{6, 0, 0, 1, 9, 5, 0, 0, 0},
        std::array<int, V>{0, 9, 8, 0, 0, 0, 0, 6, 0},
        std::array<int, V>{8, 0, 0, 0, 6, 0, 0, 0, 3},
        std::array<int, V>{4, 0, 0, 8, 0, 3, 0, 0, 1},
        std::array<int, V>{7, 0, 0, 0, 2, 0, 0, 0, 6},
        std::array<int, V>{0, 6, 0, 0, 0, 0, 2, 8, 0},
        std::array<int, V>{0, 0, 0, 4, 1, 9, 0, 0, 5},
        std::array<int, V>{0, 0, 0, 0, 8, 0, 0, 7, 9}};

    backtraking::sudoku_solver::printMat<V>(mat, mat, 9);
    std::cout<<"solusi "<<std::endl;
    std::array<std::array<int, V>, V> starting_mat = mat;
    backtraking::sudoku_solver::solveSudoku<V>(mat, starting_mat, 8, 9);

    return 0;
}