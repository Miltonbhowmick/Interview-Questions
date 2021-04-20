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
        else{
            q.push(u->left);
        }
        if(u->right==NULL){
            u->right=newNode(data);
            break;
        }
        else{
            q.push(u->right);
        }
    }
}

bool CheckSum(struct Node *root){

    int left_data=0,right_data=0;

    if(root==NULL || root->left==NULL&&root->right==NULL)
        return true;

    else{
        if(root->left){
            left_data=root->left->data;
        }
        if(root->right)
            right_data=root->right->data;
//        cout<<root->data<<"--"<<left_data<<" "<<right_data<<endl;
        if(root->data==(left_data+right_data)&&CheckSum(root->left)&&CheckSum(root->right))
            return true;
        else return false;
    }
}
int main()
{
    struct Node *root=NULL;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(i==0){
            root=Insert(root,x);
        }
        else Insert(root,x);
    }
    cout<<CheckSum(root)<<endl;
    return 0;
}
