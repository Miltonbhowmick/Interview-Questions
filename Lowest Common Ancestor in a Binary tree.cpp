#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left,*right,*parent;
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
    else if(data>root->data){
        root->left=Insert(root->left,data);
        root->left->parent=root;
    }
    return root;
}
struct Node* lca(struct Node *root,int n1,int n2){
    if(root==NULL)
        return NULL;
    if(root->data==n1||root->data==n2)
        return root;
    Node *left=lca(root->left,n1,n2);
    Node *right=lca(root->right,n1,n2);
    if(left) return left;
    else return right;
}
int main()
{
    struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 10, n2 = 14;
    cout<<lca(root,n1,n2)->data<<endl;
    return 0;
}
