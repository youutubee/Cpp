#include <iostream>
using namespace std;

// Function to perform a single left rotation
void rotateLeftOnce(int arr[], int n) {
    int temp = arr[0]; // Save the first element
    for (int i = 0; i < n-1; i++) { // Shift elements to the left
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp; // Place the first element at the end
}

// Function to perform a single right rotation
void rotateRightOnce(int arr[], int n) {
    int temp = arr[n-1]; // Save the last element
    for (int i = n-1; i > 0; i--) { // Shift elements to the right
        arr[i] = arr[i-1];
    }
    arr[0] = temp; // Place the last element at the beginning
}

// Function to perform multiple left rotations
void rotateLeft(int arr[], int n, int k) {
    for (int i = 0; i < k; i++) {
        rotateLeftOnce(arr, n);
    }
}

// Function to perform multiple right rotations
void rotateRight(int arr[], int n, int k) {
    for (int i = 0; i < k; i++) {
        rotateRightOnce(arr, n);
    }
}

// Function to print the array
void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n ;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout << "Original array: ";
    print(arr, n);

    int k = 15;

    // Perform left rotation
    rotateLeft(arr, n, k);
    cout << "Array after " << k << " left rotations: ";
    print(arr, n);

    // Reset array to original state
    int arr2[] = {1, 2, 3, 4, 5, 6, 7};

    // Perform right rotation
    rotateRight(arr2, n, k);
    cout << "Array after " << k << " right rotations: ";
    print(arr2, n);

    return 0;
}
