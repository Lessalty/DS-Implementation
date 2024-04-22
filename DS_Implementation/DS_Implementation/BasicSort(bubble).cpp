//Bubble Sort repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
//This process repeats until no swaps are needed, which means the list is sorted.It is called "Bubble Sort" because smaller elements bubble 
//to the top of the list(beginning of the array) with each iteration.

#include <iostream>
#include <vector>

// Function to perform the bubble sort
void bubbleSort(std::vector<int>& arr) {
    bool swapped;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        // Last i elements are already sorted
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap if the element found is greater than the next element
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (!swapped)
            break;
    }
}

// Function to print elements of the array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main2() {
    std::vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };  // Example array

    std::cout << "Original array: ";
    printArray(arr);

    bubbleSort(arr);  // Sorting the array using bubble sort

    std::cout << "Sorted array:   ";
    printArray(arr);

    return 0;
}
