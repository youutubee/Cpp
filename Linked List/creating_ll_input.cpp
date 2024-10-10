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
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* insertafter(Node* head,int toinsert,int value){
    if(head==NULL || head->next==NULL) return head;
    Node* temp=head;
    int count=1;
    while(temp->next!=NULL){
        if(count==toinsert) break;
        count++;
        temp=temp->next;
    }
    Node* new_node=create(value);
    if(temp->next!=NULL) new_node->next=temp->next;
    temp->next=new_node;
    return head;
}
Node* insertbefore(Node* head,int toinsert,int value){
    if(head==NULL || head->next == NULL) return head;
    Node* prev=NULL;
    Node* temp=head;
    int count=1;
    while(temp!=NULL){
        if(count==toinsert) break;
        count++;
        prev=temp;
        temp=temp->next;
    }
    Node* new_node=create(value);
    if(prev->next!=NULL) new_node->next=temp;
    prev->next=new_node;
    return head;
}
Node* deleteNode(Node* head,int todelete){
    if(head == NULL || head->next==NULL) return head;
    Node* prev=NULL;
    Node* temp=head;
    int count=1;
    while(temp!=NULL){
        if(count==todelete) break;
        count++;
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    temp->next=nullptr;
    delete temp;
    return head;
}
int main(){
    Node* head=nullptr;
    insert(head,9);
    insert(head,7);
    insert(head,12);
    insert(head,8);
    print(head);
    deleteNode(head,2);
    print(head);
}