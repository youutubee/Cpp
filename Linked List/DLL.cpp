#include<bits/stdc++.h>
using namespace std;

//Main DLL Class
class Node {
public: // Access modifier should be lowercase
    Node* next;
    Node* back;
    int data;

public:
    Node(int data1, Node* next1,Node* back1) {
        data = data1;  // Initialize the member variable `data`
        next = next1;  // Initialize the member variable `next`
        back = back1;
    }
    
    Node(int data1) {
        data = data1;  // Initialize the member variable `data`
        next = nullptr;  // Initialize `next` as nullptr (end of the list)
        back = nullptr;
    }
};

//Convert a array to DLL
Node* convert_to_dll(vector<int>&arr){
    Node* head =new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=prev->next;
    }
    return head;
}
//Function to print the DLL
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

/*                                                  DELETION                                                             */

//Function to delete the head of a DLL
Node* deleteHead(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp=head;
    head=head->next;
    head->back=nullptr;
    temp->next=nullptr;
    delete temp;
    return head;
} 
//Function to delete the tail of a DLL
Node* deleteTail(Node* head){
    if(head==NULL || head->next!=NULL) return NULL;
    Node* temp=head;
    while(temp->next!=NULL){ 
        temp=temp->next;
    }
    Node* prev=temp;
    prev=temp->back;
    temp->back=nullptr;
    prev->next=nullptr;
    delete temp;  
    return head;
}

//Function to delete a node of a DLL by position
Node* deleteNodepos(Node* head, int position){
    Node* temp=head;
    if(head==NULL){
        return NULL;
    }
    //means we have to remove the head of the LL
    if(position==1){
        head=head->next;
        temp->next=nullptr;
        head->back=nullptr;
        delete temp;
        return head;
    }
    int count=0; 
    while(temp!=NULL){
        count++;
        if(count==position) break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* front=temp->next;
    //this means deleting the tail
    if(front==NULL){
        temp->back=nullptr;
        prev->next=nullptr;
        delete temp;
    }
    //it means if the DLL has only one element
    else if(front==NULL && prev==NULL){
        return NULL;
    }
    //this means if the postion is neither head nor tail nor the list is empty and neither it has only 1 node
    else{
        prev->next=temp->next;
        front->back=temp->back;
        temp->next=nullptr;
        temp->back=nullptr;
        delete temp;
    }
    return head;
}

//Function to delete a node of a DLL by value
Node* deleteNodeval(Node* head, int value){
    Node* temp=head;
    if(head==NULL){
        return NULL;
    }
    //means we have to remove the head of the LL
    if(head->data==value){
        head=head->next;
        temp->next=nullptr;
        head->back=nullptr;
        delete temp;
        return head;
    }
    while(temp!=NULL){
        if(temp->data==value) break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* front=temp->next;
    //this means deleting the tail
    if(front==NULL){
        temp->back=nullptr;
        prev->next=nullptr;
        delete temp;
    }
    //it means if the DLL has only one element
    else if(front==NULL && prev==NULL){
        return NULL;
    }
    //this means if the postion is neither head nor tail nor the list is empty and neither it has only 1 node
    else{
        prev->next=temp->next;
        front->back=temp->back;
        temp->next=nullptr;
        temp->back=nullptr;
        delete temp;
    }
    return head;
}

/*                                                  INSERTION                                                            */

//Inserting a node before head of a DLL
Node* insertbeforehead(Node* head,int value){
    Node* new_head=new Node(value,head,nullptr);
    head->back=new_head;
    return new_head;
}

//Inserting a node before head
Node* insertafterhead(Node* head,int value){
    Node* new_head=new Node(value,head->next,head->next);
    new_head->back=head;
    return head;
}

//Inserting a node before the tail of a DLL
Node* insertbeforetail(Node* head,int value){
    Node* temp=head;
    Node* prev=NULL;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    Node* new_node=new Node(value,temp,prev);
    temp->back=new_node;
    prev->next=new_node;
    return head;

}

//Inserting a node before a node in a DLL //if pos==3 so insert before the 3rd node
Node* insertbeforenode(Node* head,int position,int value){
    if(head==NULL){
        Node* new_node=new Node(value,nullptr,nullptr);
        return new_node;
    }
    if(head->next==NULL){
        Node* new_node=new Node(value,head,nullptr);
        head->back=new_node;
    }
    if(position==1){
        Node* new_node=new Node(value,head,nullptr);
        head->back=new_node;
        return new_node;
    }
    int count=1;
    Node* temp=head;
    Node* prev=NULL;
    while(temp->next!=NULL){
        if(count==position){
            break;
        }
        count++;
        prev=temp;
        temp=temp->next;

    }
    Node* new_node=new Node(value,temp,prev);
    temp->back=new_node;
    prev->next=new_node;
    return head;
}

int main(){
    vector<int>arr;
    arr.push_back(9);
    arr.push_back(3);
    arr.push_back(7);
    arr.push_back(13);

    Node* head = convert_to_dll(arr);
    head=insertbeforenode(head,4,5);
    print(head);
    return 0;
}