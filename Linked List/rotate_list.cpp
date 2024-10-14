#include<bits/stdc++.h>
using namespace std;
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
int length(Node* head){
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
Node* rotate(Node* head,int k){
    int n=length(head);
    k=k%n;
    while(k>0){
        cout<<"Loop ran "<<k<<endl;
        Node* temp=head;
        while(temp->next->next!=NULL){
        temp=temp->next;
        }
        Node* new_node=new Node(temp->next->data);
        new_node->next=head;
        head=new_node;
        delete temp->next;
        temp->next=NULL;
        k--;

    }
    return head;
}
int main(){
    vector<int>arr;
    arr.push_back(9);
    arr.push_back(7);
    arr.push_back(3);
    arr.push_back(12);
    int k=2;
    Node* head=convert(arr);
    print(head);
    head=rotate(head,k);
    print(head);
}