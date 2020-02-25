#include<iostream>
using namespace std;
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

int Ceill(struct Node *root,int data,int &mn){
    if(root==NULL)
        return -1;
    if(root->data>=data&&root->data<=mn){
        mn=root->data;
    }
    if(data<root->data) Ceill(root->left,data,mn);
    else
        Ceill(root->right,data,mn);
    return mn;
}
int main()
{
    struct Node *root=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(i==0)root=Insert(root,x);
        else Insert(root,x);
    }
    for(int i=0;i<16;i++){
        int mn=241378593;
        cout<<i<<" "<<Ceill(root,i,mn)<<endl;
    }
    return 0;
}
