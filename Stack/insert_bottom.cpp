#include<bits/stdc++.h>
using namespace std;

/*
Question: Push Element to Bottom of Stack

Imagine you have a stack of numbers and you want to add a new number to the bottom of this stack. 
For example, if the stack has [1, 2, 3] and you want to add 0 to the bottom, the stack should become [0, 1, 2, 3].

Here's the plan:
1. If the stack is empty, simply push the new number.
2. Otherwise, pop the top element and call the function recursively to push the new number to the bottom.
3. After the recursive call, push the popped element back to the stack.

We'll first write the recursive function to do this, then use it in the main function.
*/

// Recursive function to push an element to the bottom of the stack
void pushToBottomRecursive(stack<int>& s, int x) {
    // Base case: If the stack is empty, push the element and return
    if(s.empty()) {
        s.push(x);
        return;
    }
    
    // Pop the top element and store it
    int num = s.top();
    s.pop();
    
    // Recursive call to push the element to the bottom
    pushToBottomRecursive(s, x);
    
    // Push the stored element back to the stack
    s.push(num);
}

// Function to push an element to the bottom of the stack
stack<int> pushAtBottom(stack<int>& myStack, int x) {
    pushToBottomRecursive(myStack, x);
    return myStack;
}

int main() {
    stack<int> s;
    int n, x;
    
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
    
    // Read the element to be pushed to the bottom
    cout << "Enter the element to push at the bottom: ";
    cin >> x;
    
    // Call the function to push the element at the bottom
    s = pushAtBottom(s, x);
    
    // Print the resulting stack
    // We need to pop elements to print them correctly
    stack<int> tempStack;
    while(!s.empty()) {
        tempStack.push(s.top());
        s.pop();
    }

    cout << "Stack after pushing the element to the bottom: ";
    while(!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;
}

