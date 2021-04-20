#include<iostream>
#define MAX 10000
using namespace std;
int f,k,Acnt,Bcnt;
int a[MAX],b[MAX];
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
struct Node* lca(struct Node *root,int n1,int n2){
    if(root==NULL)
        return NULL;
    if(n1<root->data&&n2<root->data){
        lca(root->left,n1,n2);
    }
    else if(n1>root->data && n2>root->data){
        lca(root->right,n1,n2);
    }
    else return root;
}
void Search1(struct Node *root, int n1,int &Acnt){
    if(n1==root->data&&root!=NULL){
        a[Acnt++]=root->data;
        return;
    }
    if(root==NULL){
        return;
    }
    if(n1<root->data){
        Search1(root->left,n1,Acnt);
        a[Acnt++]=root->data;
    }
    else{
        Search1(root->right,n1,Acnt);
        a[Acnt++]=root->data;
    }
    return;
}
int main()
{
    struct Node *root=NULL;
    int n,n1,n2;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(i==0) root=Insert(root,x);
        else Insert(root,x);
    }
    cin>>n1>>n2;
    struct Node *ans=lca(root,n1,n2);
    Search1(ans,n1,Acnt);
    for(int i=0;i<Acnt;i++)
        cout<<a[i]<<" ";
    Search1(ans,n2,Bcnt);
    for(int i=Bcnt-2;i>=0;i--)
        cout<<a[i]<<" ";
    return 0;
}

