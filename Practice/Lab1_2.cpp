#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    Node* next;
    int data;

public:
    Node(int data1, Node* next1) {
        data = data1; 
        next = next1;  
    }
    
    Node(int data1) {
        data = data1;  
        next = nullptr;  
    }
};
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
Node *Sort(Node *head) {
    Node *currNode = head;
    bool swapped = false;

    while (currNode != NULL) {
        Node *traverseNode = head;
        Node *prevNode = head;
        swapped = false;

        while (traverseNode->next != NULL) {
            Node *ptr = traverseNode->next;
            if (traverseNode->data < ptr->data) {
                swapped = true;
                if (traverseNode == head) {
                    traverseNode->next = ptr->next;
                    ptr->next = traverseNode;
                    prevNode = ptr;
                    head = prevNode;
                }
                else {
                    traverseNode->next = ptr->next;
                    ptr->next = traverseNode;
                    prevNode->next = ptr;
                    prevNode = ptr;
                }
            }
            else{
                    prevNode = traverseNode;
                    traverseNode = traverseNode->next;
                }
        }
        if (!swapped) {
            break;
        }
        currNode = currNode->next;
    }
    return head;
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    vector<int>arr;
    arr.push_back(9);
    arr.push_back(7);
    arr.push_back(3);
    arr.push_back(12);
    Node* head=convert(arr);
    head = Sort(head);
    print(head);
}