#include<iostream>
#include<vector>
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
Node* convert_to_ll(vector<int>&arr){
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

/*                                             DELETION                                                 */

//Function to Delete the head of a LL
Node* deletehead(Node* head){
    if (head == NULL) return head; 
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

//Function to Delete the tail of a LL
Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next; 
    temp->next=nullptr; 
    return head;
}

//Function to Delete a node in a LL by position
Node* deleteNodebypos(Node* head,int k){
    if(head==NULL){
        return head;
    }
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int count=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        count++;
        if(count==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next; 
    }
    return head;
}

//Function to Delete a node in a LL by value
Node* deleteNodebyval(Node* head,int element){
    if(head==NULL){
        return head;
    }
    if(head->data==element){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        if(temp->data==element){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next; 
    }
    return head;
}

/*                                          INSERTION                                                          */

//Insert a node/element at the head of LL
Node* inserthead(Node* head, int element){
    if(head==NULL){
        return new Node(element);
    }
    Node* temp=new Node(element,head);
    return temp;
}

//Insert a node/element at the tail of LL
Node* inserttail(Node* head,int element){
    if(head==NULL){
        return new Node(element);
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* nex=new Node(element);
    temp->next=nex;
    return head;
}
//Insert a node/element at any position in a LL
Node* insertpos(Node* head,int element,int position){
    if(head==NULL){
        if(position==1) return new Node(element,head);
        else return NULL;
    }
    if(position==1){
        Node* temp=new Node(element,head);
        return temp;
    }
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++; 
        if(count+1==position){
            Node* neww=new Node(element,temp);
            neww->next=temp->next;
            temp->next=neww; 
            break;
        }
        temp=temp->next;
    }
    return head;
}

//Insert a node/element in a LL before any value in the LL
Node* insertval(Node* head,int element,int value){
    if(head==NULL){
        return  NULL; 
    }
    if(head->data==value){
        Node* temp=head;
        temp=new Node(element,temp);
        return temp;
    }
    Node* temp=head;
    while(temp->next !=NULL){
        if(temp->next->data==value){
            Node* neww=new Node(element,temp->next);
            temp->next=neww;
            break;
        }
        temp=temp->next;
    }
    return head;
}

//Main function
int main() {
    vector<int>arr;
    arr.push_back(2);
    arr.push_back(8);
    arr.push_back(15);
    arr.push_back(7);

    Node* head = convert_to_ll(arr);
    head=insertval(head,12,15);
    print(head);

}
