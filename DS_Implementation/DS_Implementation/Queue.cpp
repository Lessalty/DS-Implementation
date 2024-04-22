//Queue: A First In First Out(FIFO) structure where the first element added is the first one to be removed.Common operations include enqueue(add an item 
// to the back), dequeue(remove the item from the front), and front(view the front item without removing it).

#include <iostream>

// Node structure for Queue
struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (front != nullptr) {
            dequeue();
        }
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    int dequeue() {
        if (front == nullptr) {
            throw std::out_of_range("Queue is empty");
        }
        Node* temp = front;
        int data = temp->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return data;
    }

    int getFront() {
        if (front == nullptr) {
            throw std::out_of_range("Queue is empty");
        }
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};
