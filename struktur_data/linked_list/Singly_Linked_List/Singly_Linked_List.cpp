#include <iostream>
struct Node{
    int data;
    Node* next = nullptr;

    Node(int new_data){
        this->data = new_data;
        this->next = nullptr;
    }
};

void traversal_linkedList(Node* head){
    while(head != nullptr){
        std::cout << head->data << " ";
        head = head->next;
    }
}

bool searching(Node *head,int cari){
    Node* curr = head;
    while(curr != nullptr){
        if(curr->data == cari){
            return true;
            break;
        }   
        curr = curr->next;
    }
    return false;
}
int main(){
    //manual insertion
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    std::cin.get();
    return 0;
}