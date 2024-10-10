#include<bits/stdc++.h>
using namespace std;

/*
Question: Delete Middle Element from Stack

Imagine you have a stack of numbers, and you want to remove the middle number from it. 
For example, if you have 5 numbers, you want to remove the 3rd one. If you have 6 numbers, 
remove the 3rd one (counting from 1).

Here's the plan:
1. Read the number of elements in the stack.
2. Push all elements into the stack.
3. Remove the middle element from the stack.
4. Print the remaining elements in the stack.

We'll first do this using recursion, then we'll rewrite it without recursion.
*/

// Recursive function to delete the middle element of the stack
void deleteMiddleRecursive(stack<int>& s, int n, int count) {
    // If we've reached the middle, pop the element and return
    if(count == n / 2) {
        s.pop();
        return;
    }
    
    // Pop the top element and store it
    int num = s.top();
    s.pop();
    
    // Recursive call to process the next element
    deleteMiddleRecursive(s, n, count + 1);
    
    // Push the stored element back onto the stack
    s.push(num);
}

int main() {
    stack<int> s;
    int n;
    
    // Read the number of elements
    cin >> n;
    
    // Read each element and push it onto the stack
    for(int i = 0; i < n; i++) {
        int ele;
        cin >> ele;
        s.push(ele);
    }
    
    int count = 0;
    
    // Call the recursive function to delete the middle element
    deleteMiddleRecursive(s, n, count);
    
    // Print the remaining elements in the stack
    // We need to pop elements to print them correctly
    stack<int> tempStack;
    while(!s.empty()) {
        tempStack.push(s.top());
        s.pop();
    }
    
    while(!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;
}


