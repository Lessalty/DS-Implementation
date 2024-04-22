//Stack: A Last In First Out(LIFO) structure where the last element added to the stack is the first one to be removed.Common operations include push(add 
// an item), pop(remove the top item), and peek(view the top item without removing it).

#include <iostream>

// Node structure for Stack
struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

// Stack class
class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) {
            throw std::out_of_range("Stack is empty");
        }
        Node* temp = top;
        int data = temp->data;
        top = top->next;
        delete temp;
        return data;
    }

    int peek() {
        if (top == nullptr) {
            throw std::out_of_range("Stack is empty");
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};
