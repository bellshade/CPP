#include <iostream>
#include <cstring>

#define BEAD(i,j) beads[ i * max + j]

// fungsi untuk perform algoritma

void beadSort(int *a, int len){
    // menemukan nilai maksimum dari elemen
    int max = a[0];
    for(int i = 1; i < len; i++){
        if(a[i] > max)
            max = a[i];
    }

    // mengalokasikan memori
    unsigned char *beads = new unsigned char[max * len];
    memset(beads, 0, static_cast<size_t>(max) * len);

    // marking beadsnya
    for(int i = 0; i < len; i++)
        for(int j = 0; j < a[i]; j++) BEAD(i,j) = 1;

    for (int j = 0; j < max; j++){
        // menghitung berapa banyak bead tiap elemen
        int sum = 0;
        for (int i = 0; i < len; i ++){
            sum += BEAD(i,j);
            BEAD(i,j) = 0;
        }

        // menggeser bead kebawah
        for(int i = len - sum; i < len; i++) BEAD(i,j) = 1;
    }

    // maukkan value yang diorting ke array menggunakan bead
    for(int i = 0; i < len; i++){
        int j;
        for(j = 0; j < max && BEAD(i,j); j++){
        }
        a[i] = j;
    }
    delete[] beads;
}

// fungsi utama
int main(){
    int a[] = {5, 4, 2, 1,5, 7, 8};
    int len = sizeof(a) / sizeof(a[0]);
    beadSort(a, len);
    
    for(int i = 0; i < len; i++) printf("%d", a[i]);

    return 0;
}