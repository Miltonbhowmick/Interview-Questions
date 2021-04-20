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
struct Node* FindNode(struct Node *root,int data){
    if(root==NULL)
        return NULL;
    if(root->data==data){
        return root;
    }
    Node *res1=FindNode(root->left,data);
    Node *res2=FindNode(root->right,data);
    if(res1) return res1;
    else if(res2) return res2;
    else return NULL;
}
/// x node to all leaf
void FindToLeaf(struct Node *node,int level,int &max_dis){
    if(node==NULL){
        return ;
    }
    if(node->left==NULL&&node->right==NULL){
        if(level<max_dis){
            max_dis=level;
        }
        return;
    }
    FindToLeaf(node->left,level+1,max_dis);
    FindToLeaf(node->right,level+1,max_dis);
}
/// x node to all parent
int FindToParent(struct Node *root,struct Node *node,int &max_dis){
    if(root==NULL) return -1;
    if(root==node) return 0;

    int l=FindToParent(root->left,node,max_dis);
    if(l!=-1){
        FindToLeaf(root->right,l+2,max_dis);
        return l+1;
    }
    int r=FindToParent(root->right,node,max_dis);
    if(r!=-1){
        FindToLeaf(root->left,r+2,max_dis);
        return r+1;
    }
    return -1;
}
int main()
{
    struct Node *root=NULL;
    int n,max_dis=12435;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(i==0) root=Insert(root,x);
        else Insert(root,x);
    }
    int f;
    cin>>f;
    struct Node *node=FindNode(root,f);
    if(node!=NULL){
        FindToLeaf(node,0,max_dis);
        FindToParent(root,node,max_dis);
        cout<<max_dis<<endl;
    }

    return 0;
}
