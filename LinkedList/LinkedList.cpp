#include <iostream>

using namespace std;

// Defining Node Object with its data and reference field

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

// Defining LinkedList with basic operations
class LinkedList {

    public: 
        Node* head;

        LinkedList(){
            head = NULL;
        }

        // Function to insert a node at the beginning
        void insertNode(int val) {
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }

        // Traverse the linked list and print its elements
        void print() {
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

    linkedList.insertNode(40);
    linkedList.insertNode(30);
    linkedList.insertNode(20);
    linkedList.insertNode(10);

    linkedList.print();

    return 0;
}