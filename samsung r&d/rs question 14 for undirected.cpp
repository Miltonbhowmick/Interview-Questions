#include<iostream>
#define MAX 10000
using namespace std;
int v,e,grid[MAX][MAX];
int path[MAX],cycle_start,cycle_end;
bool vis[MAX];

bool dfs(int u,int parent){
    vis[u]=true;
    for(int i=0;i<v;i++){
        if(grid[u][i]){
            if(vis[i]==false){
                path[u]=i;
                if(dfs(i,u)){
                    return true;
                }
            }
            else if(i!=parent){
                cycle_start=i;
                cycle_end=u;
                return true;
            }
        }
    }
    return false;
}
bool CheckCycle(){
    for(int i=0;i<v;i++){
        if(vis[i]==false){
            if(dfs(i,i)==true)
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
        grid[y][x]=1;
    }
    if(CheckCycle()){
        while(cycle_start!=cycle_end){
            cout<<cycle_start<<" ";
            cycle_start=path[cycle_start];
        }
        cout<<cycle_end<<endl;
    }
    else
        cout<<"No cycle"<<endl;
    return 0;
}
