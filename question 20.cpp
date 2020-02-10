/*
6 6
5 2
5 0
4 0
4 1
2 3
3 1
*/
#include<iostream>
#define MAX 1000
using namespace std;
int v,e,grid[MAX][MAX];
bool vis[MAX];
/// stack
class Stack{

public:
    int top;
    int a[MAX];
    Stack(){
        top=-1;
    }
    bool push(int x){
        if(top>=(MAX-1)){
            return false; ///Stack Overflow
        }
        else{
            a[++top]=x;
            return true;
        }
    }
    int pop(){
        if(top<0){
            return 0; /// Stack Underflow
        }
        else{
            int x=a[top--];
            return x;
        }
    }
    int peek(){
        if(top<0){
            return 0;
        }
        else{
            int x=a[top];
            return x;
        }
    }
    bool isEmpty(){
        return (top<0);
    }
};
/// Topological DFS

void dfs(int u,Stack &s){
    vis[u]=true;
    for(int i=0;i<v;i++){
        if(grid[u][i]){
            if(vis[i]==false){
                dfs(i,s);
            }
        }
    }
    s.push(u);
    return;
}
int main()
{
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        grid[x][y]=1;
    }
    Stack s;
    /// dfs for all vertex ... move to stack
    for(int i=0;i<v;i++){
        if(vis[i]==false){
            dfs(i,s);
        }
    }
    while(!s.isEmpty()){
        cout<<s.peek()<<" ";
        s.top--;
    }
    return 0;
}
