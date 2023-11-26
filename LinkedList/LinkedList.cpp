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
        void insertAtMid(int val, int position) {
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
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
};

int main(){
    
    LinkedList linkedList;

    linkedList.insertAtBeginning(40);
    linkedList.insertAtBeginning(30);
    linkedList.insertAtBeginning(20);
    linkedList.insertAtBeginning(10);

    linkedList.traverse();

    return 0;
}