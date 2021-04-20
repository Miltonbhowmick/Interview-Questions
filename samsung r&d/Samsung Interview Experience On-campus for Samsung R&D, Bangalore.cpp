#include<iostream>
#define MAX 10000
using namespace std;
int t,v,e,grid[MAX][MAX];
bool vis[MAX],sptStack[MAX];

/// stack
class Stack{
public:
    int top,arr[MAX];
    Stack(){
        top=-1;
    }
    void push(int data){
        arr[++top]=data;
    }
    int pop(){
        if(top<0) return -1;
        int x=arr[top--];
        return x;
    }
    bool isEmpty(){
        return (top<0);
    }
    int Top(){
        return arr[top];
    }
};
bool dfs(int u,Stack &s){
    vis[u]=true;
    sptStack[u]=true;
    for(int i=0;i<v;i++){
        if(grid[u][i]){
            if(vis[i]==false){
                dfs(i,s);
                    return true;
            }
            else if(sptStack[i]==true)
                return true;
        }
    }
    sptStack[u]=false;
    s.push(u);
    return false;
}
void reset()
{
    for(int i=0;i<v;i++){
        vis[i]=false;
        sptStack[i]=false;
    }
}
int main()
{
    cin>>t;
    while(t--){
        reset();
        cin>>v>>e;
        for(int i=0;i<e;i++){
            int x,y;
            cin>>x>>y;
            grid[x][y]=1;
        }
        reset();
        Stack s;
        /// dfs for all graphs
        for(int i=0;i<v;i++){
            if(vis[i]==false){
                dfs(i,s);
            }
        }
        while(!s.isEmpty()){
            cout<<s.Top()<<" ";
            s.pop();
        }
    }
    return 0;
}
