#include<iostream>
#define MAX 1000
using namespace std;
int n;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node *parent;
};
/// Queue
class Queue{
public:
    int fnt,rear;
    Node *arr[MAX];
    Queue(){
        fnt=rear=-1;
    }
    void push(Node *data){
        if(fnt==-1) fnt=0;
        arr[++rear]=data;
    }
    void pop(){
        if(fnt==-1||fnt>rear) return;
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
/// Queue end
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
void CheckSumRoot(struct Node *root,int &cnt){
    int leftval=0,rightval=0;
    if(root==NULL||root->left==NULL&&root->right==NULL)
        return ;
    else{
        if(root->left)
            leftval=root->left->data;
        if(root->right)
            rightval=root->right->data;

        if(root->data==(leftval+rightval)){
            cout<<root->data<<" ";
            cnt++;
        }
        CheckSumRoot(root->left,cnt);
        CheckSumRoot(root->right,cnt);
    }
}
int main()
{
    struct Node *root=NULL;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(i==0) root=Insert(root,x);
        else Insert(root,x);
    }
    int cnt=0;
    CheckSumRoot(root,cnt);
    cout<<"\n"<<cnt<<endl;
    return 0;
}
