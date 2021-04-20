#include<iostream>
#include<cstdlib>
using namespace std;

/// Creating BST
int flag=1;
struct node{
    int flag;
    int data;
    node *left, *right, *parent;
};
struct node *root=NULL;
struct node* newNode(int data){
    node *temp = new node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    return temp;
}
struct node* NodeInsert(struct node *nd, int data){
    if(nd == NULL){
        struct node *New = newNode(data);
        New->flag = flag;
        flag++;
        return New;
    }
    if(data< nd->data){
        nd->left = NodeInsert(nd->left,data);
        nd->left->parent=nd;
    }
    else if(data> nd->data){
        nd->right = NodeInsert(nd->right,data);
        nd->right->parent=nd;
    }
    return nd;
}
struct node* StackBST(struct node *nd){
    if(nd==NULL)
        return NULL;
    if(nd->flag==(flag-1)){
        return nd;
    }
    struct node *res1 = StackBST(nd->left);
    struct node *res2 = StackBST(nd->right);
    if(res1!=NULL) return res1;
    else if(res2!=NULL) return res2;
    else return NULL;
}
int Top(){
    node *top=StackBST(root);
    return top->data;
}
void Pop(){
    node *pop=StackBST(root);
    node *popParent=pop->parent;
    if(popParent==NULL) return;
    if(popParent->left!=NULL&& popParent->left->data == pop->data){
        popParent->left=NULL;
    }
    else{
        popParent->right=NULL;
    }
    free(pop);   ///IMPORTANT!!!!
    flag--;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        if(i==0)
            root = NodeInsert(root,data);
        else
            NodeInsert(root,data);
    }
    cout<<Top();
    Pop();
    cout<<Top();
    NodeInsert(root,90);
    cout<<Top();
    Pop();
    cout<<Top();
    return 0;
}
