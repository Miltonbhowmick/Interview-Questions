#include<iostream>
#define MAX 10000
using namespace std;
int t,v,grid[MAX][MAX],color[MAX];
///Queue
class Queue{
public:
    int fnt,rear,num_ele,arr[MAX];
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

/// dfs for bipartite
bool bfs(int u){
    Queue q;
    q.push(u);
    color[u]=1;

    while(!q.isEmpty()){
        int u=q.Front();
        q.pop();

        for(int i=0;i<v;i++){
            if(grid[u][i]){
                if(color[i]==-1){
                    color[i]=1-color[u];
                    q.push(i);
                }
                else if(color[i]==color[u])
                    return false;
            }
        }
    }
    return true;
}
/// bipartite check
bool isBipartite(){
    for(int i=0;i<v;i++){
        if(color[i]==-1){
            if(bfs(i)==false)
                return false;
        }
    }
    return true;
}
///reset
void reset(){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            grid[i][j]=0;
        }
        color[i]=-1;
    }
}
int main()
{
    cin>>t;
    while(t--){
        reset();
        cin>>v;
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                cin>>grid[i][j];
            }
        }
        cout<<isBipartite()<<endl;
    }
    return 0;
}
