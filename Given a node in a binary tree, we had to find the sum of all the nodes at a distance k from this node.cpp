#include<iostream>
using namespace std;
int f,k;
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
    struct Node *res1=FindNode(root->left,data);
    struct Node *res2=FindNode(root->right,data);
    if(res1) return res1;
    else if(res2) return res2;
    else return NULL;
}
void FindToLeaf(struct Node *root, int cnt, int &max_dis){
    if(root==NULL)
        return;
    if(root->left==NULL&&root->right==NULL){
        max_dis=min(cnt,max_dis);
        return;
    }
    if(cnt==k){
        cout<<root->data<<endl;
        return;
    }
    FindToLeaf(root->left,cnt+1,max_dis);
    FindToLeaf(root->right,cnt+1,max_dis);
}
int FindToParent(struct Node *root,struct Node *node, int &max_dis){
    if(root==NULL)
        return -1;
    if(root==node)
        return 0;

    int li=FindToParent(root->left,node,max_dis);
    if(li!=-1){
        if((li+1)==k) cout<<root->data<<endl;
        FindToLeaf(root->right,li+2,max_dis);
        return li+1;
    }
    int ri=FindToParent(root->right,node,max_dis);
    if(ri!=-1){
        if((li+1)==k) cout<<root->data<<endl;
        FindToLeaf(root->left,ri+2,max_dis);
        return ri+1;
    }
}
int main()
{
    struct Node *root=NULL;
    int n;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(i==0) root=Insert(root,x);
        else Insert(root,x);
    }
    cin>>f;
    struct Node *node=FindNode(root,f);
    int max_dis=12435;
    if(node!=NULL){
        FindToLeaf(node,0,max_dis);
        FindToParent(root,node,max_dis);
    }

    return 0;
}
