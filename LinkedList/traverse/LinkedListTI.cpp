#include <iostream>

using namespace std;


class Node { 
public:  
    int data; 
    Node* next; 
    
    Node(int data) 
    { 
        this->data = data; 
        this->next = NULL; 
    } 
}; 

class LinkedList {

    public: 
        Node* head;

        LinkedList(){
            head = NULL;
        }

        // Function to insert a node at the beginning
        void insertAtStart(int val) {
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }

        // Function to traverse the linked list and print its elements
        void traverse() {
            Node* current = head;
            while (current != NULL) {
                std::cout << current->data << " -> ";
                current = current->next;
            }
            std::cout << "NULL" << std::endl;
        }
     
};

int main(){
    
    LinkedList linkedList;

    linkedList.insertAtStart(30);
    linkedList.insertAtStart(20);
    linkedList.insertAtStart(10);

    linkedList.traverse();

    return 0;
}