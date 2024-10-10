#include <bits/stdc++.h>
using namespace std;

// Node class representing each element in the doubly linked list
class Node {
    public:
    int data;      // Data of the node
    Node* next;    // Pointer to the next node
    Node* back;    // Pointer to the previous node

    // Constructor to initialize data, next, and back pointers
    Node(int data1 , Node* next1 , Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

// Function to convert a vector into a doubly linked list
Node* convert(vector<int> arr) {
    if (arr.empty()) return nullptr;  // Edge case for empty array
    
    // Create the head of the list
    Node* head = new Node(arr[0]);
    Node* mover = head;
    
    // Create the rest of the list
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;      // Set next pointer of current node
        temp->back = mover;      // Set back pointer of new node
        mover = temp;            // Move to the next node
    }
    
    return head;  // Return the head of the list
}

// Function to print the doubly linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";  // Print data
        temp = temp->next;          // Move to next node
    }
    cout << endl;
}

// Function to reverse the doubly linked list
Node* reverse(Node* head) {
    Node* last = nullptr;   // Pointer to keep track of the last node (new head)
    Node* current = head;   // Pointer to traverse the list
    
    // Reverse the pointers in the list
    while (current != nullptr) {
        last = current->back;    // Store current's back pointer
        current->back = current->next;  // Swap next and back pointers
        current->next = last;
        current = current->back;        // Move to the next node (which was back)
    }
    
    // After reversing, 'last' will point to the old head's back, so return last's back
    return last->back;
}

int main() {
    vector<int> arr;
    arr.push_back(9);
    arr.push_back(7);
    arr.push_back(3);
    arr.push_back(12);
    
    Node* head = convert(arr);  // Convert the vector to doubly linked list
    
    cout << "Original list: ";
    print(head);                // Print the original list
    
    head = reverse(head);       // Reverse the list
    
    cout << "Reversed list: ";
    print(head);                // Print the reversed list
    
    return 0;
}
