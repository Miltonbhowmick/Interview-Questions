#include<iostream>
#include<cstdlib>
#include<cstdio>
#define MAX 10000
using namespace std;
int t,n;
struct Node{
    string data;
    Node *left;
    Node *right;
    Node *parent;
};
///
class Queue{
public:
    int fnt,rear,num_ele;
    Node *arr[MAX];
    Queue(){
        fnt=rear=-1;
    }
    void push(struct Node *data){
        if(fnt==-1) fnt=0;
        arr[++rear]=data;
    }
    void pop(){
        if(fnt==-1||fnt>rear) return ;
        fnt++;
    }
    bool isEmpty(){
        if(fnt==-1||fnt>rear) return true;
        return false;
    }
    Node* Front(){
        return arr[fnt];
    }
};

struct Node* newNode(string data){
    struct Node *temp = new Node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    temp->parent=NULL;
    return temp;
}
struct Node* Insert(struct Node *root, string data){
    if(root==NULL)
        return newNode(data);
    Queue q;
    q.push(root);
    while(!q.isEmpty()){
        Node *u=q.Front();
        q.pop();

        if(u->left==NULL){
            u->left=newNode(data);
            break;
        }
        else
            q.push(u->left);
        if(u->right==NULL){
            u->right=newNode(data);
            break;
        }
        else
            q.push(u->right);
    }

}

void printLevel(struct Node *root){
    Queue q;
    q.push(root);
    while(!q.isEmpty()){
        Node *u=q.Front();
        cout<<u->data<<" ";
        q.pop();

        if(u->left!=NULL) q.push(u->left);
        if(u->right!=NULL) q.push(u->right);
    }
    cout<<endl;
}
int main()
{
    cin>>t;
    while(t--){
        struct Node *root=NULL;
        string s="",r="";
        int ck=0,idx=0;

        for(int i=0;i<idx;i++){
            if(s[i]==' '){
                if(ck==0) root=Insert(root,r),ck++;
                else Insert(root,r);
                r="";
            }
            else{
                r+=s[i];
            }
        }
        cout<<root->data;
    }
    return 0;
}
