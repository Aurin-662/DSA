#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int val;
    node *left;
    node *right;
    node(int val){
        this->val=val;
        this->right=nullptr;
        this->left=nullptr;
    }
};
void levelorder(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* f=q.front();
        q.pop();

        cout<<f->val<<" ";
        if(f->left){
            q.push(f->left);
        }   
        if(f->right){
            q.push(f->right);
        }
    }
}

int main(){
    node* root=new node(10);
    node* a=new node(20);
    node* b=new node(30);
    node* c=new node(40);
    node* d=new node(50);
    node* e=new node(60);
    root->left=a;
    root->right=b;
    a->left=c;
    b->left=d;
    b->right=e;

    levelorder(root);

 return 0;
}
