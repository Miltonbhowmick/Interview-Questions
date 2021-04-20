#include<iostream>
#include<cstdlib>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Node* newNode(int data){
    struct Node *temp=new Node();
    temp->data=data;
    temp->next=NULL;
}
void push(struct Node **root, int data){
    struct Node *temp = newNode(data);
    temp->next = *root;
    *root=temp;
}
/// another push method
void push1(struct Node **root,int data){
    struct Node *current = *root;
    if(current==NULL){
        *root = newNode(data);
    }
    else{
        while(current->next!=NULL)
            current=current->next;
        current->next = newNode(data);
    }
}
void pop(struct Node *root,int data){
    struct Node *current=root;
    while(current->next!=NULL){
        if(current->next->data==data){
            struct Node *temp=current->next;
            current->next=temp->next;
            free(temp);
        }
        else current=current->next;
    }
}
void print(struct Node *root){
    while(root!=NULL){
        cout<<root->data<<" ";
        root=root->next;
    }
    cout<<endl;
}
int main()
{
    int t,n;
    cin>>t;
    while(t--){
        struct Node *root=NULL;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            push1(&root,x);
        }
        int rm;
        cin>>rm;
        if(root->data==rm){
            struct Node *temp=root;
            root=root->next;
            free(temp);
        }
        else{
            pop(root,rm);
        }
        print(root);
    }
    return 0;
}
