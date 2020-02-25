#include<iostream>
#include<climits>
#define MAX 1000
using namespace std;
int t,n,grid[MAX][MAX],input[MAX][2];
bool vis[MAX];
int abs(int x){
    if(x<0) return -1*x;
    return x;
}
void tsp(int u,int cnt,int cost,int &ans){
    if(cnt==n&&grid[u][n+1]){
        ans=min(ans,cost+grid[u][n+1]);
        return;
    }
    for(int i=1;i<=n;i++){
        if(grid[u][i]&&vis[i]==false){
            vis[i]=true;
            tsp(i,cnt+1,cost+grid[u][i],ans);
            vis[i]=false;
        }
    }
}
void reset(){
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            grid[i][j]=abs(input[i][0]-input[j][0])+abs(input[i][1]-input[j][1]);
        }
    }
}
int main()
{
    int sx,sy,dx,dy;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>sx>>sy>>dx>>dy;
        input[0][0]=sx;
        input[0][1]=sy;
        for(int i=1;i<=n;i++){
            int x,y;
            cin>>x>>y;
            input[i][0]=x;
            input[i][1]=y;
        }
        input[n+1][0]=dx;
        input[n+1][1]=dy;
        reset();
        vis[0]=true;
        int ans=INT_MAX;
        tsp(0,0,0,ans);
        cout<<ans<<endl;
    }
    return 0;
}
