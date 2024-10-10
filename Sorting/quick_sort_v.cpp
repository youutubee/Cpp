#include <bits/stdc++.h>
using namespace std;

/*
 * Quicksort is a popular and efficient sorting algorithm that uses the divide-and-conquer strategy.
 * Here's how it works:
 * 1. Divide: The array is divided into two sub-arrays by a pivot element. 
 *    Elements less than the pivot are moved to the left of the pivot, and elements greater than the pivot are moved to the right.
 * 2. Conquer: The sub-arrays are then sorted recursively using the same process.
 * 3. Combine: The sub-arrays are combined to produce the sorted array.
 *
 * Time Complexity:
 * - Best and average case: O(n log n)
 * - Worst case: O(n^2) (occurs when the smallest or largest element is always picked as the pivot)
 *
 * Example to visualize the process:
 *
 * Initial array: [9, 3, 7, 5, 6, 4, 8, 2]
 * Pivot chosen: 9 (first element)
 *
 * Step-by-step:
 * 1. Partition the array:
 *    [2, 3, 7, 5, 6, 4, 8, 9]
 *    9 is in its correct position
 * 2. Recursively sort the left sub-array: [2, 3, 7, 5, 6, 4, 8]
 *    Pivot chosen: 2 (first element)
 *    After partition: [2, 3, 7, 5, 6, 4, 8]
 *    2 is in its correct position
 * 3. Continue recursively sorting sub-arrays...
 */

// Function to print the array
void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Choose the first element as the pivot
    int i = low;
    int j = high;

    while (i < j) {
        // Increment i until an element greater than the pivot is found
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
            cout << "i has been incremented to " << i << endl;
        }
        // Decrement j until an element less than or equal to the pivot is found
        while (arr[j] > pivot && j >= low + 1) {
            j--;
            cout << "j has been decremented to " << j << endl;
        }
        // Swap the elements at i and j
        cout << "The values being swapped are " << arr[i] << " and " << arr[j] << endl;
        if (i < j) swap(arr[i], arr[j]);
        cout << "Array after swap: ";
        print(arr, 8);
    }
    // Swap the pivot element with the element at j
    swap(arr[low], arr[j]);
    cout << "Array after swapping pivot element: ";
    print(arr, 8);

    return j; // Return the partition index
}

// Function to perform quicksort on the array
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int partition_index = partition(arr, low, high); // Get the partition index
        quick_sort(arr, low, partition_index - 1);       // Recursively sort the left sub-array
        quick_sort(arr, partition_index + 1, high);      // Recursively sort the right sub-array
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n; // Input the number of elements
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input the elements of the array
    }
    int low = 0;
    int high = n - 1;
    quick_sort(arr, low, high); // Perform quicksort on the array
    cout << "Final resultant array: ";
    print(arr, n); // Print the sorted array
}
