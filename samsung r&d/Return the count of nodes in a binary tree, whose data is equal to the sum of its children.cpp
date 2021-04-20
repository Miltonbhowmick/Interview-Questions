#include<iostream>
#define MAX 10000
using namespace std;
int n;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node *parent;
};
/// queue
class Queue{
public:
    int fnt,rear,num_ele;
    Node *arr[MAX];
    Queue(){
        fnt=rear=-1;
    }
    void push(Node *data){
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
struct Node* newNode(int data){
    struct Node *temp = new Node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    temp->parent=NULL;
    return temp;
}
struct Node* Insert(struct Node *root, int data){
    if(root==NULL)
        return newNode(data);
    else{
        Queue q;
        q.push(root);
        while(!q.isEmpty()){
            Node* u=q.Front();
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
}
void CountNode(struct Node *root, int &cnt){
    if(root==NULL)
        return ;
    if(root->left==NULL&&root->right==NULL)
        return;
    else{
        int leftval,rightval;
        if(root->left==NULL) leftval=0;
        else leftval=root->left->data;
        if(root->right==NULL) rightval=0;
        else rightval=root->right->data;

        if(root->data==(leftval+rightval))
            cnt++;
    }
    CountNode(root->left,cnt);
    CountNode(root->right,cnt);
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
    CountNode(root,cnt);
    cout<<cnt<<endl;
    return 0;
}
