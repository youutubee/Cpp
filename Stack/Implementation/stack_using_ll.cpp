#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* next;
    int data;
    Node(int data1){
        next=nullptr;
        data=data1;
    }
};

class Stack{
    public:
    Node* top;
    int size;

    Stack(){
        top = NULL;
        size = 0;
    }

    void push(int x){
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;

    }
    int peek(){
        return top->data;
    }
    void pop(){
        Node* temp = top;
        top=temp->next;
        delete temp;
        size--;
    }
    int getsize(){
        return size;
    }
    bool isempty(){
        if(top == NULL) return true;
        else return false;
    }
};

int main(){

    Stack st;
    st.push(9);
    st.push(7);
    st.push(13);
    st.push(3);
    st.pop();
    st.pop();
    cout<<st.peek()<<endl;
    st.isempty();
    cout<<st.getsize();
}

