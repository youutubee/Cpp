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
class Queue{
    public:
    Node* start;
    Node* end;
    int size;
    Queue(){
        start=nullptr;
        end=nullptr;
        size=0;
    }
    void push(int x){
        Node* temp = new Node(x);
        if(start == nullptr && end == nullptr){
            start=temp;
            end=temp;
        }
        else {
            end->next=temp;
            end=temp;
        }
        size++;
    }
    void pop(){
        Node* temp=start;
        start=start->next;
        delete temp;
        size--;
    }
    int top(){
        return start->data;
    }
    int getsize(){
        return size;
    }
};
int main(){
    Queue q;
    q.push(9);
    q.push(7);
    q.push(13);
    q.push(8);
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.getsize()<<endl;
}