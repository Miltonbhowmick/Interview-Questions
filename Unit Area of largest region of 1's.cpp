#include<iostream>
#define MAX 10000
using namespace std;
int t,n,m,grid[MAX][MAX];
bool vis[MAX][MAX];

/*
* * * *
* * * *
* * * *
* * * *
*/
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={0,1,-1,1,-1,1,0,-1};

bool isValid(int x,int y){
    if(x>=0&&x<=n-1&&y>=0&&y<=m-1)
        return true;
    return false;
}
bool dfs(int sx,int sy,int &cnt){
    vis[sx][sy]=true;
    for(int i=0;i<8;i++){
        int ax=sx+dx[i];
        int ay=sy+dy[i];
        if(isValid(ax,ay)&&grid[ax][ay]==1){
            if(vis[ax][ay]==false){
                cnt++;
                dfs(ax,ay,cnt);
            }
        }
    }
}
void reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vis[i][j]=false;
        }
    }
}
int main()
{
    cin>>t;
    while(t--){
        reset();
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
    int cnt,mx=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==false&&grid[i][j]==1){
                cnt=1;
                dfs(i,j,cnt);
                mx=max(mx,cnt);
            }
        }
    }
    cout<<mx<<endl;
    }
    return 0;
}
/*
10 3
0 0 1
1 1 0
1 0 1
1 1 1
0 1 0
0 1 0
1 0 1
0 0 1
0 0 0
1 1 1
3 3
1 1 0 0 0 1 1 0 1
1 3
1 1 1
*/
