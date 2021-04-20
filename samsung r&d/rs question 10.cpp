#include<iostream>
#include<climits>
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
struct Node* Insert(struct Node *root, int data){
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
struct Node* SearchNode(struct Node *root,int data){
    if(root==NULL)
        return NULL;
    if(root->data==data){
        return root;
    }
    struct Node *res1=SearchNode(root->left,data);
    struct Node *res2=SearchNode(root->right,data);
    if(res1!=NULL) return res1;
    else if(res2!=NULL) return res2;
}
/// find from leaf
void FindLeafDown(Node *node,int level,int &mn){
    if(node==NULL){
        return;
    }
    if(node->left==NULL&&node->right==NULL){
        if(level<mn){
            mn=level;
        }
        return;
    }
    FindLeafDown(node->left,level+1,mn);
    FindLeafDown(node->right,level+1,mn);
}
/// find through parent
int FindThroughParent(struct Node *root, struct Node *node,int &mn){
    if(root==NULL) return -1;
    if(root==node)return 0;

    int l=FindThroughParent(root->left,node,mn);

    if(l!=-1){
        FindLeafDown(root->right,l+2,mn);
        return l+1;
    }

    int r=FindThroughParent(root->right,node,mn);
    if(l!=-1){
        FindLeafDown(root->left,l+2,mn);
        return l+1;
    }
    return -1;
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
//    Preorder(root);
    int x;
    cin>>x;
    struct Node * node=SearchNode(root,x);
    int mn=INT_MAX;

    FindLeafDown(node,0,mn);
    FindThroughParent(root,node,mn);

    cout<<mn<<endl;
    return 0;
}
