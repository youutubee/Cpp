#include<bits/stdc++.h>
using namespace std;


// Using binart search on rotated sorted arrays
// Four simple steps
// 1>> Return the mid index if it matches the target value
// 2>> Find out which part of the array is sorted
// 3>> Check if the key is that sorted part
// 4>> Adjust start and end according to it

int bs_rotated_sorted(int arr[], int n, int target) {
    // Initialization of variables
    int s = 0;
    int e = n - 1;
    // Calculate the mid index
    int mid = s + (e - s) / 2;

    while (s <= e) {
        // Check if the middle element is the target
        if (arr[mid] == target) return mid;

        // Check if the left part of the array is sorted
        if (arr[s] <= arr[mid]) {
            // Determine if the target is in the sorted left part
            if (target >= arr[s] && target < arr[mid]) {
                // If true, adjust the end to search in the left part
                e = mid - 1;
            } else {
                // Otherwise, adjust the start to search in the right part
                s = mid + 1;
            }
        }
        // If the left part is not sorted, the right part must be sorted
        else {
            // Determine if the target is in the sorted right part
            if (target > arr[mid] && target <= arr[e]) {
                // If true, adjust the start to search in the right part
                s = mid + 1;
            } else {
                // Otherwise, adjust the end to search in the left part
                e = mid - 1;
            }
        }
        // Recalculate the mid index
        mid = s + (e - s) / 2;
    }
    // Return -1 if the target value is not found
    return -1;
}

int main() {
    int n;
    cin >> n;
    int target;
    cin >> target;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int index = bs_rotated_sorted(arr, n, target);
    cout << index;
}


