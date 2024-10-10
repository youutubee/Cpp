#include<bits/stdc++.h>
using namespace std;
//Main Linked List Class
class Node {
public: // Access modifier should be lowercase
    Node* next;
    int data;

public:
    Node(int data1, Node* next1) {
        data = data1;  // Initialize the member variable `data`
        next = next1;  // Initialize the member variable `next`
    }
    
    Node(int data1) {
        data = data1;  // Initialize the member variable `data`
        next = nullptr;  // Initialize `next` as nullptr (end of the list)
    }
};

//Function to convert a array to a LL
Node* convert(vector<int>&arr){
    if(arr.empty()) return nullptr;
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
//Function to print the LL
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
/*

This is not the most optimized solution 
tc->O(2n)
sc->O(n)

Node* odd_even(Node* head){
    Node* temp=head;
    vector<int>arr;
    Node* prev=head->next;
    while(temp!=NULL && temp->next!=NULL){
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp!=NULL) arr.push_back(temp->data);  //for odd case maybe if temp->next is not NUll it may skip the last element
    while(prev!=NULL && prev->next!=NULL){
        arr.push_back(prev->data);
        prev=prev->next->next;
    }
    if(prev!=NULL) arr.push_back(prev->data);
    temp=head;
    for(int i=0;i<arr.size();i++){
        temp->data=arr[i];
        temp=temp->next;
    }
    return head;

}
*/
Node* odd_even(Node* head){
    Node* odd=head;
    Node* even=head->next;
    Node* evenH=head->next;
    while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=evenH;
    return head;
}
int main(){
    vector<int> arr;
    arr.push_back(9);
    arr.push_back(7);
    arr.push_back(12);
    arr.push_back(2);
    Node* head=convert(arr);
    print(head);
    head=odd_even(head);
    print(head);
}