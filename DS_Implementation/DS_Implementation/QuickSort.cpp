//Pivot Selection : The choice of pivot can affect the performance of QuickSort.Common methods include choosing the first element, 
// the last element, the middle element, or a random element as the pivot.
// 
//Partitioning : Rearrange the array so that elements less than the pivot come before it and elements greater come after it.After partitioning, 
// the pivot is in its final position.
// 
//Recursive Sort : Apply the same logic to the left and right sub - arrays(elements on the left side of the pivot and elements on the right side).

#include <iostream>
#include <vector>

// Function to swap elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to perform the partitioning of the array
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Selecting the last element as the pivot
    int i = (low - 1);      // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;            // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Main function to implement QuickSort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print elements of the array
void prtArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main3() {
    std::vector<int> arr = { 10, 7, 8, 9, 1, 5 };
    int n = arr.size();

    std::cout << "Original array: ";
    prtArray(arr);

    quickSort(arr, 0, n - 1);  // Sorting the array using QuickSort

    std::cout << "Sorted array:   ";
    prtArray(arr);

    return 0;
}
