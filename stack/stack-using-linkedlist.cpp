#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node *next;
    node* prev;
    node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};
class myStack{
    public:
    node* head=NULL;
    node* tail=NULL;
    int sz=0;
    void push(int val){
        sz++;
        node* newnode= new node(val);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    void pop(){
        sz--;
        node* del=tail;
        tail=tail->prev;
        delete del;
        if(tail==NULL){
            head=NULL;
            return;
        }
        tail->next=NULL;
    }
    int top(){
        return tail->val;
    }
    int size(){
        return sz;
    }
    bool empty(){
        return head==NULL;
    }
};

int main()
{
    myStack st;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}