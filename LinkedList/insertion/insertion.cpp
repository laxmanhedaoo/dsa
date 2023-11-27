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


        // Function to insert a node at the end
        void insertAtEnd(int val) {
            Node* newNode = new Node(val);

            if (head == NULL) {
                head = newNode;
                return;
            }

            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }

            current->next = newNode;
        }

        // Function to insert a node at the specified position (mid)
        void insertAtPos(int val, int position) {
            Node* newNode = new Node(val);
            Node* current = head;

            for (int i = 1; i < position - 1 && current != NULL; ++i) {
                current = current->next;
            }

            if (current == NULL) {
                std::cerr << "Invalid position for mid insertion." << std::endl;
                return;
            }

            newNode->next = current->next;
            current->next = newNode;
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

    linkedList.insertAtStart(40);
    linkedList.insertAtStart(30);
    linkedList.insertAtStart(20);
    linkedList.insertAtStart(10);

    std::cout << "List after inserting at the beginning: ";
    linkedList.traverse();

    linkedList.insertAtEnd(5);
    std::cout << "List after inserting 5 at the end: ";
    linkedList.traverse();

    linkedList.insertAtPos(25, 3); // Inserting at position 3
    std::cout << "List after inserting 25 at the middle: ";
    linkedList.traverse();

    return 0;
}