#include<iostream>
using namespace std;

/// Linked list
struct Node{
    int data;
    Node *next;
};
struct Node* newNode(int data){
    struct Node *temp=new Node();
    temp->data=data;
    temp->next=NULL;
}
void push(struct Node **root,int data){
    struct Node *current=*root;
    if(*root==NULL){
        *root=newNode(data);
    }
    else{
        while(current->next!=NULL)
            current=current->next;
        current->next=newNode(data);
    }
}
/// Merge
struct Node* finaleMerge(struct Node **a, struct Node **b){
    struct Node *currA = *a;
    struct Node *currB = *b;
    struct Node *temp=NULL;
    int cnt=0;
    while(currA!=NULL&&currB!=NULL){
        if(currA->data<=currB->data){
            push(&temp,currA->data);
//            cout<<currA->data<<endl;
            currA=currA->next;
        }
        else{
            push(&temp,currB->data);
            currB=currB->next;
//            cout<<2<<endl;
        }
    }
    while(currA!=NULL){
        push(&temp,currA->data);
        cout<<1<<endl;
        currA=currA->next;
    }
    while(currB!=NULL){
        push(&temp,currB->data);
        currB=currB->next;
    }
    return temp;
}
int main()
{
    struct Node *a=NULL;
    struct Node *b=NULL;
    struct Node *finale=NULL;

    int l1,l2;
    cin>>l1;
    for(int i=0;i<l1;i++){
        int x;
        cin>>x;
        push(&a,x);
    }
    cin>>l2;
    for(int i=0;i<l2;i++){
        int x;
        cin>>x;
        push(&b,x);
    }

    finale=finaleMerge(&a,&b);

    while(finale!=NULL){
        cout<<finale->data<<" ";
        finale=finale->next;
    }
    return 0;
}
