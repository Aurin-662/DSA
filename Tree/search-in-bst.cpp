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
node* input(){
    int val;
    cin>>val;
    node* root;
    if(val==-1) root=nullptr;
    else root=new node(val);
    queue<node*> q;
    if(root) q.push(root);
    while(!q.empty()){
        node* p=q.front();
        q.pop();

        int l,r;        
        cin>>l>>r;
        node* myleft,*myright;
        if(l==-1) myleft=nullptr;
        else myleft=new node(l);
        if(r==-1) myright=nullptr;
        else myright=new node(r);

        p->left=myleft;
        p->right=myright;

        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
    return root;
}

void insert(node* root,int val){
    if(root==nullptr){
        node* root =new node(val);
    }
    if(val<root->val){
        if(root->left==nullptr){
            root->left=new node(val);
        }
        else{
            insert(root->left,val);
        }
    }
    else{
        if(root->right==nullptr){
            root->right=new node(val);
        }
        else{
            insert(root->right,val);
        }
    }
}
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
bool search(node* root,int val){
    if(root==nullptr) return false;
    if(root->val==val) return true;
    if(root->val>val){
        return search(root->left,val);
    }
    else{
        return search(root->right,val);
    }
}

int main(){
    node* root=input();

    // insert(root,99);

    // levelorder(root);
    int val;
    cin>>val;
    if(search(root,val)){
        cout<<"found\n";
    }
    else{
        cout<<"Not found\n";
    }
     
 return 0;
}
