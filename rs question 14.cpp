#include<iostream>
#define MAX 10000
using namespace std;
int v,e,grid[MAX][MAX];
int path[MAX],cycle_start,cycle_end;
bool vis[MAX],spt[MAX];
bool dfs(int u){
    vis[u]=true;
    spt[u]=true; /// IMPORTANT!
    for(int i=0;i<v;i++){

        if(grid[u][i]){
            if(vis[i]==false){
                path[u]=i;
                if(dfs(i)==true){
                    return true;
                }
            }
            else if(spt[i]==true){
                cycle_start=i;
                cycle_end=u;
                return true;
            }
        }
    }
    spt[u]=false;
    return false;
}
bool CheckCycle(){
    for(int i=0;i<v;i++){
        if(vis[i]==false){
            if(dfs(i)==true)
                return true;
        }
    }
    return false;
}
int main()
{
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        grid[x][y]=1;
    }
    if(CheckCycle()){
        while(cycle_start!=cycle_end){
            cout<<cycle_start<<" ";
            cycle_start=path[cycle_start];
        }
        cout<<cycle_end<<endl;
    }
    return 0;
}
