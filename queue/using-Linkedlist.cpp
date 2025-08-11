#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node* prev;
    node(int val){
        this->val=val;
        this->next=nullptr;
        this->prev=nullptr;
    }
};

class myQueue{
    public:
    node* head=nullptr;
    node* tail=nullptr;
    int sz=0;
    void push(int val){
        sz++;
        node* newnode=new node( val);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    void pop(){
        sz--;
        node* del=head;
        head=head->next;
        delete del;
        if(head==nullptr){
            tail==nullptr;
            return;
        }
        head->prev=nullptr;
    }
    int front(){
        return head->val;
    }
    int back(){
        return tail->val;
    }
    int size(){
        return sz;
    }
    bool empty(){
        return head==nullptr;
        }
    
};

int main(){
    myQueue q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        q.push(val);
    }
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
// cout<<q.back();
 return 0;
}