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
int length(Node* head){
    Node* fast=head;
    Node* slow=head;
    Node* temp=NULL;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        //this means there exists a loop
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            //now we know the start point so keep fast there and traverse
            fast=fast->next;
            int count=1;
            while(fast!=slow){
                fast=fast->next;
                count++;
            }
            return count;
        }
    }
    return 0;
}
int main(){
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(10);
    arr.push_back(15);
    arr.push_back(25);
    arr.push_back(30);
    Node* head=convert(arr);
    print(head);
    int ans=length(head);
    cout<<ans;
}