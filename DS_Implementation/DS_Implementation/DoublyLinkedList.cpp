//A doubly linked list is an enhanced version of a singly linked list where each node has two links : one pointing to the next node and another 
// pointing to the previous node.This structure allows for easier bidirectional traversal and more efficient insertion and deletion operations, 
// particularly when it comes to removing nodes or inserting at the end of the list.
//
//Doubly Linked List Key Concepts
//Node Structure : Each node in a doubly linked list contains :
//Data: The actual value stored in the node.
//Next Pointer : A pointer to the next node in the list.
//Previous Pointer : A pointer to the previous node in the list.
//Head and Tail Pointers : The list maintains both head and tail pointers, which point to the first and last nodes of the list, respectively.An empty list
//  has both head and tail pointers set to nullptr.
//Operations : Common operations include :
//Insertion: At the front, back, or a specific position.
//Deletion : Of specific nodes or values.
//Traversal : Both forwards and backwards, thanks to the previous and next pointers.


#include <iostream>

// Node structure for a doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

// DoublyLinkedList class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }

    // Add element at the front of the list
    void addFront(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Add element at the end of the list
    void addEnd(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Remove the first occurrence of the value in the list
    void removeValue(int value) {
        Node* current = head;
        while (current != nullptr && current->data != value) {
            current = current->next;
        }

        if (current == nullptr) return; // Value not found

        if (current == head) {
            head = current->next;
        }
        if (current == tail) {
            tail = current->prev;
        }
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }

        delete current;
    }

    // Print list from head to tail
    void printForward() const {
        Node* current = head;
        std::cout << "Head -> ";
        while (current != nullptr) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Print list from tail to head
    void printBackward() const {
        Node* current = tail;
        std::cout << "Tail -> ";
        while (current != nullptr) {
            std::cout << current->data << " <-> ";
            current = current->prev;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.addFront(10);
    list.addEnd(20);
    list.addFront(5);
    list.addEnd(30);

    std::cout << "List in forward order: ";
    list.printForward();

    std::cout << "List in backward order: ";
    list.printBackward();

    list.removeValue(20);
    std::cout << "List after removing 20: ";
    list.printForward();

    return 0;
}
