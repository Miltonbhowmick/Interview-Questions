#include<iostream>
#define MAX 10000
using namespace std;
int v,e,grid[MAX][MAX];
int color[MAX];
/// Queue
class Queue{
public:
    int fnt,rear,num_ele;
    int arr[MAX];
    Queue(){
        fnt=rear=-1;
        num_ele=0;
    }
    void push(int data){
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
    int Front(){
        return arr[fnt];
    }
};
/// bfs

bool bfs(int src){
    color[src]=1;
    Queue q;
    q.push(src);

    while(!q.isEmpty()){
        int u=q.Front();
        q.pop();
        color[src]=1;

        for(int i=0;i<v;i++){
            if(grid[u][i]){
                if(color[i]==-1){
                    color[i]=1-color[u];
                }
                else if(color[i]==color[u]){
                    return false;
                }
            }
        }
    }
    return true;
}
bool isBi(){
    for(int i=0;i<v;i++){
        if(color[i]==-1){
            if(bfs(i)==false)
                return false;
        }
    }
    return true;
}
void reset(){
    for(int i=0;i<v;i++){
        color[i]=-1;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
    cin>>v;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>grid[i][j];
        }
    }
    reset();
    /// for disconnected graph
    cout<<isBi()<<endl;
    }
    return 0;
}
