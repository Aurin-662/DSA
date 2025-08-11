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
node* insert(node* root,int val){
    if(root==nullptr){
        node* root =new node(val);
        return root;
    }
    if(val<root->val){
        root->left= insert(root->left,val);
    }
    else{
       root->right =  insert(root->right,val);
    }
    return root;
}
node* minval(node* root){
    node* tmp=root;
    while(tmp->left!=nullptr){
        tmp=tmp->left;
    }
return tmp;
}
node* maxval(node* root){
    node* tmp=root;
    while(tmp->right!=nullptr){
        tmp=tmp->right;
    }
return tmp;
}
node* del(node* root,int val){
    // base case
    if(root==nullptr)
        return root;
    
    if(root->val==val){
        // 0 child
        if(root->left==nullptr&&root->right==nullptr){
            delete root;
            return nullptr;
        }
        // 1 child

        // left child
        if(root->left!= nullptr&&root->right==nullptr){
            node* tmp=root->left;
            delete root;
            return tmp;
        }
        // right child
        if(root->left==nullptr&&root->right!=nullptr){
            node* tmp=root->right;
            delete root;
            return tmp;
        }

            // 2 child
        if(root->left!=nullptr&&root->right!=nullptr){
            int mini=minval(root->right)->val;
            root->val=mini;
            root->right=del(root->right,mini);
            return root;
            
        }

    }   
    else if(root->val>val){
        // left part e jao
      root->left=del(root->left,val);
      return root;
    } 
    else{
        // right part e jao
        root->right=del(root->right,val);
      return root;
    }

}


void input(node* &root){
    int val;
    cin>>val;
    while(val!=-1){
        root =  insert(root,val);
        cin>>val;
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
void inorder(node* root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);  //left
    cout<<root->val<<" ";   //root
    inorder(root->right);   //right

}
void preorder(node* root){
    if(root==nullptr){
        return;
    }

    cout<<root->val<<" ";   //root
    preorder(root->left);  //left    
    preorder(root->right);   //right

}

int main(){
    node* root=nullptr;
    cout<<"enter ur bst"<<endl;
    input(root);

    levelorder(root);
    cout<<"inorder:";
    inorder(root);
    cout<<"preorder:";
    preorder(root);
    cout<<"\nmin value: "<<minval(root)->val<<endl;
    cout<<"man value: "<<maxval(root)->val<<endl;
     
 return 0;
}
