#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;

};
Node* create(int value){
    Node* new_node=new Node;
    new_node->data=value;
    new_node->next=nullptr;
    return new_node; 
}
Node* insert(Node* &head,int value){
    Node* new_node=create(value);
    if(head == NULL){
        head = new_node;
        return head;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    return head;
}
int traversal(Node* head){
    Node* temp = head;
    int maxi = temp->data;
    while(temp!=NULL){
        if(temp->data > maxi){
            maxi = temp->data;
        }
        temp=temp->next;
    }
    return maxi;
}
int main(){
    Node* head=nullptr;
    insert(head,9);
    insert(head,7);
    insert(head,12);
    insert(head,18);
    insert(head,22);
    insert(head,8);
    int ans = traversal(head);
    cout<<ans;
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}