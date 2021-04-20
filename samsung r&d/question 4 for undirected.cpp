#include<iostream>
#define MAX 1000
using namespace std;
int grid[MAX][MAX],v,e, cycle_end, cycle_start, path[MAX];
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
                cycle_end=u;
                cycle_start=i;
                return true;
            }
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
    int ck=false;
    for(int i=0;i<v;i++){
        if(vis[i]==false&&dfs(i,-1)){
            ck=true;
            break;
        }
    }
    if(ck){
        cout<<cycle_start<<" ";
        while(cycle_end!=cycle_start){
            cycle_start=path[cycle_start];
            cout<<cycle_start<<" ";
        }
        cout<<"Cycle"<<endl;
    }
    else cout<<"No Cycle"<<endl;
    return 0;
}
