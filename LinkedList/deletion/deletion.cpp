#include <iostream>

using namespace std;
 

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Function to insert a node at the beginning
    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Function to delete the first node
    void deleteFirst() {
        if (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to delete a node at a specific position (mid)
    void deleteAtMid(int position) {
        if (head == NULL) {
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* prev = NULL;

        for (int i = 1; i < position && current != NULL; ++i) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            return;
        }

        prev->next = current->next;
        delete current;
    }

    // Function to delete the last node
    void deleteAtEnd() {
        if (head == NULL) {
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;
        Node* prev = NULL;

        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }

        prev->next = NULL;
        delete current;
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

int main() { 
    LinkedList linkedList;

    linkedList.insertAtStart(30);
    linkedList.insertAtStart(20);
    linkedList.insertAtStart(10);

    std::cout << "Original List: ";
    linkedList.traverse();

    linkedList.deleteFirst();
    std::cout << "List after deleting first node: ";
    linkedList.traverse();

    linkedList.deleteAtMid(2); // Deleting at position 2
    std::cout << "List after deleting 2nd node: ";
    linkedList.traverse();

    linkedList.deleteAtEnd();
    std::cout << "List after deleting last node: ";
    linkedList.traverse();

    return 0;
}
