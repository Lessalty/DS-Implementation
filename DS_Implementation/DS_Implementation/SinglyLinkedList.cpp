//A singly linked list is a fundamental data structure that consists of a sequence of elements called nodes, 
// where each node contains a piece of data and a reference(or link) to the next node in the sequence.This structure allows for 
// efficient insertion and deletion of elements at the expense of quick access to arbitrary positions within the list.
//
//Singly Linked List Key Concepts
//Node Structure : Each node typically holds data and a pointer to the next node.
//Head Pointer : The list maintains a head pointer, which points to the first node in the list.An empty list has a head pointer that is nullptr.
//Tail Node : The last node of the list, which points to nullptr because there is no next node.
//Operations : Common operations include insertion(at the front, back, or a specific position), deletion, searching for values, and traversing the list 
// to print all the elements.

#include <iostream>

// Define the Node structure
struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

// Define the SinglyLinkedList class
class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor
    SinglyLinkedList() : head(nullptr) {}

    // Destructor to free memory
    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // Function to add element to the front of the list
    void addFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to add element to the end of the list
    void addEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to remove the first occurrence of a given value
    void removeValue(int value) {
        if (head == nullptr) return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    // Function to print all elements in the list
    void printList() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    SinglyLinkedList list;
    list.addFront(10);
    list.addEnd(20);
    list.addFront(5);
    list.addEnd(30);

    std::cout << "List after additions: ";
    list.printList();

    list.removeValue(20);
    std::cout << "List after removing 20: ";
    list.printList();

    return 0;
}
