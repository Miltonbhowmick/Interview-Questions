#include<iostream>
#include<climits>
#define MAX 10000
using namespace std;
int t,r,c,grid[MAX][MAX],dis[MAX][MAX];
bool vis[MAX][MAX];

/// direction
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
/// validity
bool isValid(int x,int y){
    if(x>=0&&x<=r-1&&y>=0&&y<=c-1)
        return true;
    else return false;
}
/// bfs
void bfs(int sx,int sy,int ddx,int ddy){
    dis[sx][sy]=grid[sx][sy];

    for(int p=1;p<=r*c;p++){
        ///minimum
        int mn=INT_MAX,px,py;
        for(int x=0;x<r;x++){
            for(int y=0;y<c;y++){
                if(dis[x][y]<mn&&vis[x][y]==false){
                    mn=dis[x][y];
                    px=x;
                    py=y;
                }
            }
        }
        vis[px][py]=true;
        /// all adjacent
        for(int j=0;j<8;j++){
            int ax = px + dx[j];
            int ay = py + dy[j];
            if(isValid(ax,ay)&&(dis[ax][ay]>(dis[px][py]+grid[ax][ay]))&&vis[ax][ay]==false){
                dis[ax][ay]=dis[px][py]+grid[ax][ay];
            }
        }
    }
    cout<<dis[ddx][ddy]<<endl;
}
/// reset
void reset(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            vis[i][j]=false;
            dis[i][j]=INT_MAX;
        }
    }
}
int main()
{
    cin>>t;
    while(t--){
        cin>>r>>c;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>grid[i][j];
            }
        }
        reset();
        bfs(0,0,r-1,c-1);
    }

    return 0;
}
