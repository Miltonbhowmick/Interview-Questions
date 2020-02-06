#include<iostream>
#define MAX 1000
using namespace std;
int v,e,grid[MAX][MAX],path[MAX],cycle_end,cycle_start;
bool rec_stack[MAX],vis[MAX];
bool dfs(int u){
        vis[u]=true;
        rec_stack[u]=true;
        for(int i=0;i<v;i++){
            if(grid[u][i]){
                if(vis[i]==false){
                    if(dfs(i)){
                        path[i]=u;
                        return true;
                    }
                }
                else if(rec_stack[i]==true){
                    cycle_end=u;
                    cycle_start=i;
                    return true;
                }
            }
        }
    rec_stack[u]=false;
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
    bool ck=false;
    for(int i=0;i<v;i++){
        if(vis[i]==false && dfs(i)){
            ck=true;
            break;
        }
    }
    if(ck){
        cout<<cycle_end<<" ";
        while(cycle_end!=cycle_start){
            cycle_end=path[cycle_end];
            cout<<cycle_end<<" ";
        }
        cout<<"Cycle"<<endl;
    }
    else cout<<"No cycle"<<endl;
    return 0;
}
