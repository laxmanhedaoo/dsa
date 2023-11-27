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
    
        // Function to traverse the linked list recursively and print its elements
        void traverseRecursive(Node* current) {
            if (current == NULL) {
                std::cout << "NULL" << std::endl;
                return;
            }

            std::cout << current->data << " -> ";
            traverseRecursive(current->next);
        }
};

int main(){
    
    LinkedList linkedList;

    linkedList.insertAtStart(30);
    linkedList.insertAtStart(20);
    linkedList.insertAtStart(10);

    linkedList.traverseRecursive(linkedList.head);

    return 0;
}