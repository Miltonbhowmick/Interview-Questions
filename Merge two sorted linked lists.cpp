#include<iostream>
using namespace std;
int t,n,m;

struct Node{
    int data;
    Node *next;
};
struct Node *a=NULL,*b=NULL;

struct Node* newNode(int data){
    struct Node *temp=new Node();
    temp->data=data;
    temp->next=NULL;
    return temp;
}
struct Node* push(struct Node *root, int data){
    if(root==NULL)
        return newNode(data);
    else{
        struct Node *curr=root;
        while(curr->next!=NULL)
            curr=curr->next;
        curr->next=newNode(data);
        return curr;
    }
}
/// merge
struct Node* MergeNow(struct Node *ra,struct Node *rb){
    struct Node *temp=NULL;
    int ck=0;
    while(ra!=NULL&&rb!=NULL){
        if(ra->data<=rb->data){
            if(ck==0) temp=push(temp,ra->data),ck++;
            else push(temp,ra->data);
            ra=ra->next;
        }
        else{
            if(ck==0) temp=push(temp,rb->data),ck++;
            else push(temp,rb->data);
            rb=rb->next;
        }
    }
    while(ra!=NULL){
        if(ck==0) temp=push(temp,ra->data),ck++;
            else push(temp,ra->data);
        ra=ra->next;
    }
    while(rb!=NULL){
        if(ck==0) temp=push(temp,rb->data),ck++;
            else push(temp,rb->data);
        rb=rb->next;
    }
    return temp;
}
int main()
{
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(i==0) a=push(a,x);
            else push(a,x);
        }
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            if(i==0) b=push(b,x);
            else push(b,x);
        }
        struct Node *ans=MergeNow(a,b);
        while(ans!=NULL){
            cout<<ans->data;
            ans=ans->next;
        }

    }
    return 0;
}
