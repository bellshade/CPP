#include <iostream>
#include <string>
/*
@brief

*/
class Node{
    public:
        int data;
        Node* next;
        //Constructor
        Node(int data){
            this->data = data;
            this->next = nullptr;
        }

        //destructor
        ~Node(){
            std::cout << "data dihapus: " << data << std::endl;
        }

};
int main(){
    Node* head = new Node(3);
    
    std::cin.get();
    return 0;
}   