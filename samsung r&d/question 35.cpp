#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left, *right, *parent;
};

struct Node* NewNode(int data){
    struct Node *temp = new Node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
}
struct Node* Insert(struct Node *root,int data){
    if(root==NULL){
        return NewNode(data);
    }
    if(data<=root->data){
        root->left=Insert(root->left,data);
    }
    else if(data>root->data){
        root->right=Insert(root->right,data);
    }
    return root;
}
/// reverse inorder!!! to maxmum to minimum node!!
void MaxNode(struct Node *root,int &c, int k){
    if(root==NULL || c>=k)
        return;
    MaxNode(root->right,c,k); /// Right to get maximum node
    c++;
    if(c==k){
        cout<<root->data<<endl;
        return;
    }
    MaxNode(root->left,c,k);
}
int main()
{
    struct Node *root=NULL;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(i==0){
            root=Insert(root,x);
        }
        else
            Insert(root,x);
    }
    int c=0;
    MaxNode(root,c,k);
    return 0;
}
