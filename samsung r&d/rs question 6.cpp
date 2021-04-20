#include<iostream>
using namespace std;

/// binary tree
struct Node{
    int data;
    Node *left;
    Node *right;
    Node *parent;
};
struct Node* newNode(int data){
    struct Node *temp=new Node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    temp->parent=NULL;
    return temp;
}
struct Node* Insert(struct Node *root,int data){
    if(root==NULL)
        return newNode(data);
    if(data<root->data){
        root->left=Insert(root->left,data);
        root->left->parent=root;
    }
    else{
        root->right=Insert(root->right,data);
        root->right->parent=root;
    }
    return root;
}
int EachNode(struct Node *root){
    if(root==NULL)
        return 0;

    int val=root->data;
    root->data=EachNode(root->left);
    root->data+=EachNode(root->right);

    return root->data+val;
}
void Inorder(struct Node *root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    Inorder(root->left);
    Inorder(root->right);
}
int main()
{
    struct Node *root=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(i==0) root=Insert(root,x);
        else Insert(root,x);
    }
    Inorder(root);
    EachNode(root);
    Inorder(root);
    return 0;
}
