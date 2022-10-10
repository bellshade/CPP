#include <iostream>

int main(){

    // arr[baris][kolom]
    int arr[3][2] = {
        {0,1},
        {2,3},
        {4,5}
    };

    for(int baris = 0; baris < 3; baris++){
        for(int kolom = 0; kolom < 2; kolom++){
            std::cout << "arr[" << baris << "][" << kolom << "]: " << arr[baris][kolom] << std::endl;
        }
    }
    
    /*
    
    Expected Output:
    arr[0][0]: 0
    arr[0][1]: 1
    arr[1][0]: 2
    arr[1][1]: 3
    arr[2][0]: 4
    arr[2][1]: 5

    */
}