#include<iostream>
#define MAX 10000
using namespace std;
int v,e,grid[MAX][MAX];
bool vis[MAX],spt[MAX];

bool dfs(int u){
    vis[u]=true;
    spt[u]=true;
    for(int i=0;i<v;i++){
        if(grid[u][i]){
            if(vis[i]==false){
                if(dfs(i)){
                    cout<<"++"<<endl;
                    return true;
                }
            }
            else if(spt[i]==true){
                return true;
            }
        }
    }
    spt[u]=false;
    return false;
}
/*
4 6
0 1
1 3
3 2
2 0
2 1
1 2
*/
int CheckCycle(){
/// dfs for the graph
    int cnt=0;
    for(int i=0;i<v;i++){
        if(vis[i]==false){
            if(dfs(i)){
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        grid[x][y]=1;
    }
    cout<<CheckCycle()<<endl;
    return 0;
}
