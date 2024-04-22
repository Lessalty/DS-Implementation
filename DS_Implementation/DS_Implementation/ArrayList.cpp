//To implement an ArrayList from scratch, you typically need to manage a dynamically resizing array.Here's a basic overview of what this entails in most programming languages:
//
//Initialization: Start with an initial capacity.
//Add Element : When adding an element, check if the array needs to resize(i.e., if it's full). If so, increase the size of the array typically by doubling it to maintain an amortized time complexity of O(1) for each addition.
//    Get Element : Access an element at a specific index.This is a direct operation with O(1) complexity.
//    Remove Element : Remove an element from a specific index.This requires shifting elements to fill the space, which has O(n) complexity.
//    Set Element : Replace the element at a specific index with a new element, which is an O(1) operation.


#include <iostream>

class ArrayList {
private:
    int* data;        // This will store the elements of the list.
    int capacity;     // This tells us how many elements we can store before we need to make more room.
    int size;         // This tells us how many elements are currently in the list.

    // This function makes the list bigger when there's no room left.
    void expandCapacity() {
        int* newData = new int[capacity * 2];  // Create a new, bigger array.
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];  // Copy each element from the old array to the new one.
        }
        delete[] data;            // Get rid of the old, smaller array.
        data = newData;           // Point our data pointer to the new array.
        capacity *= 2;            // Double the capacity.
    }

public:
    // Constructor: set up the list with an initial capacity.
    ArrayList() : capacity(10), size(0) {
        data = new int[capacity];
    }

    // Destructor: clean up the list when it's no longer needed.
    ~ArrayList() {
        delete[] data;
    }

    // Add an element to the end of the list.
    void add(int value) {
        if (size == capacity) {
            expandCapacity();  // Make more room if there's no space left.
        }
        data[size] = value;  // Store the new value in the array.
        size++;              // Increase the size counter.
    }

    // Get the element at a specific index.
    int get(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Index out of bounds." << std::endl;
            return -1;  // This is an error value, since index is invalid.
        }
        return data[index];  // Return the element at the given index.
    }

    // Remove an element from a specific index.
    void remove(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Index out of bounds." << std::endl;
            return;  // Just exit if the index is invalid.
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];  // Shift each element one place to the left.
        }
        size--;  // Decrease the size since we've removed an element.
    }

    // Get the number of elements in the list.
    int getSize() {
        return size;
    }
};

int main1() {
    ArrayList myList;

    // Adding elements to the list
    myList.add(5);
    myList.add(10);
    myList.add(15);

    // Displaying an element
    std::cout << "Element at index 1: " << myList.get(1) << std::endl;

    // Removing an element
    myList.remove(1);
    std::cout << "Element at index 1 after removal: " << myList.get(1) << std::endl;

    // Checking the size of the list
    std::cout << "Current size of the list: " << myList.getSize() << std::endl;

    return 0;
}
