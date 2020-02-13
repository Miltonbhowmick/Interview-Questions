#include<iostream>
#include<climits>
#define MAX 10000
using namespace std;
int n,grid[MAX][MAX];
bool vis[MAX];

void tsp(int u,int cnt,int cost,int &ans){

    if(cnt==n&&grid[u][0]>0){
        ans=min(ans,cost+grid[u][0]);
        return;
    }
    for(int i=0;i<n;i++){
        if(grid[u][i]>0){
            if(vis[i]==false){
                vis[i]=true;
                tsp(i,cnt+1,cost+grid[u][i],ans);
                vis[i]=false;
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vis[0]=true;
    int ans=INT_MAX;
    tsp(0,1,0,ans);
    cout<<ans<<endl;
    return 0;
}
