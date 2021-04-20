#include<iostream>
#include<cstdlib>
#define MAX 10000
using namespace std;
int n;
/// Node
struct Node{
    int data;
    Node *next;
};
struct Node* newNode(int data){
    struct Node *temp= new Node();
    temp->data=data;
    temp->next=NULL;
    return temp;
}
struct Node* push(struct Node *root,int data){
    if(root==NULL)
        return newNode(data);
    else{
        while(root->next!=NULL)
            root=root->next;
        root->next=newNode(data);
        return root->next;
    }
}
void pop(struct Node **root,int data){
    struct Node *curr=*root;
    if(curr->data==data){
        *root=curr->next;
        free(curr);
    }
    else{
        while(curr->next->data!=data){
            curr=curr->next;
        }
        struct Node *del=curr->next;
        curr->next=del->next;
        free(del);
    }
}
void swp(struct Node **root,int x,int y){
    struct Node *n=*root;
    struct Node *m=*root;
    if(x==y) return;
    if(n->data==x){

        while(m->next!=NULL&&m->next->data!=y)
            m=m->next;
        struct Node *temp;
        *root=m;
        m->next=n;
    }
    else if(m->data==y){
        while(n->next!=NULL&&n->next->data!=x)
        n=n->next;
        struct Node *temp;
        *root=n;
        n->next=m;
    }
    else{
        while(n->next!=NULL&&n->next->data!=x)
            n=n->next;
        while(m->next!=NULL&&m->next->data!=y)
            m=m->next;
        struct Node *pren=n;
        struct Node *currn=n->next;
        struct Node *prem=m;
        struct Node *currm=m->next;
        pren->next=currm;
        prem->next=currn;

        struct Node *temp=currm->next;
        currm->next=currn->next;
        currn->next=temp;
    }

}
int main()
{
    struct Node *root=NULL;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(i==0) root=push(root,x);
        else push(root,x);
    }
//    pop(&root,12);
    swp(&root,12,20);

    while(root!=NULL){
        cout<<root->data<<" ";
        root=root->next;
    }
    cout<<endl;
    return 0;
}
