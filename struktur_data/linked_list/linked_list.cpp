#include <iostream>


// membuat node
class Node {
  public:
    int value;
    Node *next;
};

int main() {
  Node *head;
  Node *pertama = NULL;
  Node *kedua = NULL;
  Node *ketiga = NULL;

  // alokasi 3 memori
  pertama = new Node();
  kedua = new Node();
  ketiga = new Node();

  // menetapkan memori
  pertama -> value = 1;
  kedua -> value = 2;
  ketiga -> value = 3;

  // koneksi ketiga node
  pertama -> next = kedua;
  kedua -> next = ketiga;
  ketiga -> next = NULL;

  // print dari linked list
  head = pertama;
  while (head != NULL) {
    std::cout<<"node ke: "<<head -> value<<std::endl;
    head = head -> next;
  }

  return 0;
}

