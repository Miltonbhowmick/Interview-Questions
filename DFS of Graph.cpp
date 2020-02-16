#include<iostream>
#define MAX 10005
using namespace std;
int t,n,e,grid[MAX][MAX];
bool vis[MAX];
void dfs(int u){
    vis[u]=true;
    cout<<u<<" ";
    for(int i=0;i<n;i++){
        if(grid[u][i]){
            if(vis[i]==false){
                dfs(i);
            }
        }
    }
    return;
}
void reset(){
    for(int i=0;i<n;i++){
        vis[i]=false;
    }
    cout<<endl;
}
int main()
{
    cin>>t;
    while(t--){
        cin>>n>>e;
        for(int i=0;i<e;i++){
            int x,y;
            cin>>x>>y;
            grid[x][y]=1;
        }
        dfs(0);
        reset();
    }
    return 0;
}
