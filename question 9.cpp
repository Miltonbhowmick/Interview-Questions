/*
4 12
0 1 10
0 2 15
0 3 20
1 0 10
1 2 35
1 3 25
2 0 15
2 1 35
2 3 30
3 0 20
3 1 25
3 2 30

output: 80
*/
#include<iostream>
#define MAX 1000
using namespace std;
int grid[MAX][MAX],v,e;
bool vis[MAX];
void tsp(int u,int cnt,int cost,int &ans){

    if(cnt==v&&grid[u][0]){
        ans = min(ans,cost+grid[u][0]);
        return;
    }

    for(int i=0;i<v;i++){
        if(grid[u][i]){
            if(vis[i]==false){
                vis[u]=true;
                tsp(i,cnt+1,cost+grid[u][i],ans);
                vis[u]=false;
            }
        }
    }
}
int main()
{
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y>>w;
        grid[x][y]=w;
    }
    int ans=1e5;
    int src;
    cin>>src;
    vis[src]=true; /// IMPORTANT!!!!
    tsp(src,1,0,ans);
    cout<<ans<<endl;
    return 0;
}
