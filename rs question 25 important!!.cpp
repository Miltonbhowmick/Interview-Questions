#include<iostream>
#define MAX 10000
using namespace std;
int t,n,grid[MAX][MAX],sol[MAX][MAX],ans,path[MAX][MAX];
bool vis[MAX][MAX];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool isValid(int x, int y){
    if(x>=0&&x<=n-1&&y>=0&&y<=n-1)
        return true;
    return false;
}
void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
}
void dfs(int sx,int sy,int mx){

    if(sx==n-1&&sy==n-1){
        if(grid[sx][sy]==2)mx++;
        if(ans<mx){
            ans=mx;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    path[i][j]=sol[i][j];
                }
            }
        }
        return;
    }

    for(int i=0;i<4;i++){
        int ax=sx+dx[i];
        int ay=sy+dy[i];

        if(isValid(ax,ay)&&vis[ax][ay]==false&&grid[ax][ay]!=1){
            vis[ax][ay]=true;
            sol[ax][ay]=3;
            if(grid[ax][ay]==2){
                dfs(ax,ay,mx+1);
                sol[ax][ay]=2;
            }
            else{
                dfs(ax,ay,mx);
                sol[ax][ay]=0;
            }
            vis[ax][ay]=false;
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
            path[i][j]=grid[i][j];
        }
    }
    ans=-1231445;
    vis[0][0]=true;
    sol[0][0]=3;
    dfs(0,0,0);
    cout<<ans<<endl;
    print();
    return 0;
}
