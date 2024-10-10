#include<bits/stdc++.h>
using namespace std;

/*
Question: Reverse Stack Using Recursion

Imagine you have a stack of numbers, and you want to reverse the order of the elements in the stack. 
For example, if the stack has [1, 2, 3], after reversal, it should become [3, 2, 1].

Here's the plan:
1. Use recursion to reverse the stack.
2. To reverse, remove all elements from the stack and then insert them at the bottom one by one.
3. Use a helper function to insert elements at the bottom of the stack.

We'll first write the recursive function to reverse the stack, then use it in the main function.
*/

// Recursive function to insert an element at the bottom of the stack
void insertAtBottom(stack<int>& s, int element) {
    // Base case: If the stack is empty, push the element and return
    if(s.empty()) {
        s.push(element);
        return;
    }
    
    // Store the top element and remove it
    int num = s.top();
    s.pop();
    
    // Recursive call to insert the element at the bottom
    insertAtBottom(s, element);
    
    // Push the stored element back onto the stack
    s.push(num);
}

// Recursive function to reverse the stack
void reverseStack(stack<int>& s) {
    // Base case: If the stack is empty, return
    if(s.empty()) {
        return;
    }
    
    // Remove the top element
    int num = s.top();
    s.pop();
    
    // Recursive call to reverse the remaining stack
    reverseStack(s);
    
    // Insert the removed element at the bottom of the reversed stack
    insertAtBottom(s, num);
}

int main() {
    stack<int> s;
    int n;
    
    // Read the number of elements
    cout << "Enter the number of elements in the stack: ";
    cin >> n;
    
    // Read each element and push it onto the stack
    cout << "Enter the elements of the stack: ";
    for(int i = 0; i < n; i++) {
        int ele;
        cin >> ele;
        s.push(ele);
    }
    
    // Call the function to reverse the stack
    reverseStack(s);
    
    // Print the reversed stack
    // We need to pop elements to print them correctly
    stack<int> tempStack;
    while(!s.empty()) {
        tempStack.push(s.top());
        s.pop();
    }

    cout << "Reversed stack: ";
    while(!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;
}
