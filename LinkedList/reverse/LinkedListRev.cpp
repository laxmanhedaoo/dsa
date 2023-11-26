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

        void reverseIterative() {
            Node* current = head;
            Node* prev = NULL;
            Node* nextNode = NULL;

            while (current != NULL) {
                nextNode = current->next;
                current->next = prev;
                prev = current;
                current = nextNode;
            }

            head = prev;
        }

        void traverse() {
            Node* current = head;
            while (current != NULL) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
};

int main(){
    
    LinkedList linkedList;

    linkedList.insertAtBeginning(3);
    linkedList.insertAtBeginning(2);
    linkedList.insertAtBeginning(1);
    
    std::cout << "Original List: ";
    linkedList.traverse();

    linkedList.reverseIterative();

    std::cout << "Reversed List: ";
    linkedList.traverse();

    return 0;
}