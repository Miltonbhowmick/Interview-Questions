#include<iostream>
#define MAX 10000
using namespace std;
int n,t;
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
        if(fnt==-1||fnt>rear) return ;
        fnt++;
    }
    bool isEmpty(){
        if(fnt==-1||fnt>rear) return true;
        else return false;
    }
    Node* Front(){
        return arr[fnt];
    }
};
struct Node* Insert(struct Node *root,int data){
    if(root==NULL)
        return newNode(data);
    else{
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
}
struct Node* FindNode(struct Node *root, int data){
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
/// node to leaf
void NodeToLeaf(struct Node *root,int cnt,int &max_dis){
    if(root->left==NULL&&root->right==NULL){
        max_dis=min(cnt,max_dis);
        return;
    }
    if(root==NULL)
        return;

    NodeToLeaf(root->left,cnt+1,max_dis);
    NodeToLeaf(root->right,cnt+1,max_dis);
}
int FindFromParent(struct Node *root,struct Node *node,int &max_dis){
    if(root==NULL)
        return -1;
    if(root==node)
        return 0;

    int li=FindFromParent(root->left,node,max_dis);
    if(li!=-1){
        NodeToLeaf(root->right,li+2,max_dis);
        return li+1;
    }

    int ri=FindFromParent(root->right,node,max_dis);
    if(ri!=-1){
        NodeToLeaf(root->left,ri+2,max_dis);
        return ri+1;
    }
    return -1;
}
int main()
{
    struct Node *root=NULL;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(i==0){
                root=Insert(root,x);
            }
            else Insert(root,x);
        }
        int f;
        int max_dis=241789146;
        cin>>f;
        struct Node *node=FindNode(root,f);

        NodeToLeaf(node,0,max_dis);
        cout<<max_dis<<endl;
    }
    return 0;
}
