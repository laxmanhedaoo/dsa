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
        void insertAtBeginning(int val) {
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }

        // Function to traverse the linked list and print its elements
        void traverse() {
            Node* current = head;
            while (current != NULL) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    
        // Function to traverse the linked list recursively and print its elements
        void traverseRecursive(Node* current) {
            if (current == NULL) {
                std::cout << std::endl;
                return;
            }

            std::cout << current->data << " ";
            traverseRecursive(current->next);
        }
};

int main(){
    
    LinkedList linkedList;

    linkedList.insertAtBeginning(3);
    linkedList.insertAtBeginning(2);
    linkedList.insertAtBeginning(1);

    linkedList.traverse();

    return 0;
}