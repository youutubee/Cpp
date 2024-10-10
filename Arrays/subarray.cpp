#include <bits/stdc++.h>
using namespace std;

//Using Two pointer approach ==>> It is most optimal when the array just conatins positive integers

// Function to find the length of the maximum subarray with a given sum k
int max_subarray_length_with_positives(int arr[], int n, int k) {
    int right = 0; // Right pointer
    int left = 0;  // Left pointer
    int maxi = 0;  // Maximum length of subarray
    int sum = arr[0]; // Current sum of subarray
    
    while (right < n) {
        // Adjust left pointer if sum exceeds k
        while (left <= right && sum > k) {
            sum -= arr[left];
            left++;
        }
        
        // Update maximum length if sum equals k
        if (sum == k) {
            maxi = max(maxi, right - left + 1);
        }
        
        right++; // Move right pointer
        if (right < n) {
            sum += arr[right];
        }
    }
    
    return maxi; // Return maximum length
}

int main() {
    int n;
    cin >> n; // Input array size
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input array elements
    }
    int k;
    cin >> k; // Input desired sum
    
    // Find and print the length of the maximum subarray with sum k
    int length = max_subarray_length_with_positives(arr, n, k);
    cout << length;
    
    return 0;
}
