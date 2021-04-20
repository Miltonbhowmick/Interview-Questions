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
void LeftNode(struct Node *root,int &max_level,int level){
    if(root==NULL) return;

    if(max_level<level){
        cout<<root->data<<" ";
        max_level=level;
    }
    LeftNode(root->right,max_level,level+1);
    LeftNode(root->left,max_level,level+1);
}
int main()
{
    struct Node *root        = newNode(12);
    root->left               = newNode(10);
    root->right              = newNode(30);
    root->left->left         = newNode(25);
    root->left->right        = newNode(40);
    int max_level=0;
    LeftNode(root,max_level,1);

    return 0;
}

