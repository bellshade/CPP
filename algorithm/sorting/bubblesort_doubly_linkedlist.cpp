#include <iostream>

using namespace std;

struct Node {
    int number;

    Node* prev;
    Node* next;
};

Node* NodeHead = NULL;
Node* NodeTail = NULL;

void CreateNodeBegin(int number);
void BubbleSort();
void ReadData();

int main() {
    CreateNodeBegin(5);
    CreateNodeBegin(3);
    CreateNodeBegin(1);
    CreateNodeBegin(9);
    CreateNodeBegin(7);

    BubbleSort();

    ReadData();
}

/* Bubble sort */
void BubbleSort()
{
    int swapped;
    struct Node *temp;

    // Cek apakah data kosong. Jika kosong, bubble sort berhenti.
    if (NodeHead == NULL) return;

    do {
        swapped = 0;
        temp = NodeHead;

        // Looping list hingga mencapai node terakhir
        while (temp->next != NodeTail) {
            /*
                Sorting data secara ascending.
                Jika ingin sorting secara descending, ubah operator '>' dibawah ini menjadi '<'.
            */
            if (temp->number > temp->next->number) {
                // swap() : function penukaran nilai antar 2 variable
                swap(temp->number, temp->next->number);
                swapped = 1;
            }

            // Menggeser node temp ke node selanjutnya
            temp = temp->next;
        }

        // Assign nilai NodeTail berupa node temp
        NodeTail = temp;
    } while (swapped);
}

// Membuat node baru dibagian awal list
void CreateNodeBegin(int number) {
    Node* newNode = new Node;

    newNode->number = number;
    
    newNode->next = NodeHead;
    NodeHead = newNode;
    NodeHead->prev = NULL;
}

// Membaca data list
void ReadData() {
    Node* temp = NodeHead;

    while (temp != NULL) {
        cout << temp->number << endl;
        temp = temp->next;
    }
}