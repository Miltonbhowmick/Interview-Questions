/*
5
5
31 100 65 12 18
10 13 47 157 6
100 113 174 11 33
88 124 41 20 140
99 32 111 41 20
*/
#include<iostream>
#include<climits>
#define MAX 1000
using namespace std;
int t,n,grid[MAX][MAX],dis[MAX][MAX];
bool vis[MAX][MAX];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool isValid(int x,int y){
    if(x>=0&&x<=n-1&&y>=0&&y<=n-1)
        return true;
    return false;
}
/// dijkstra
void dijkstra(int sx,int sy){
    dis[sx][sy]=grid[0][0];

    for(int c=1;c<=n*n;c++){
        /// min from priority queue
        int mn=INT_MAX,px,py;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dis[i][j]<mn&&vis[i][j]==false){
                    mn=dis[i][j];
                    px=i;
                    py=j;
                }
            }
        }
        /// end
        vis[px][py]=true;
        for(int i=0;i<4;i++){
            int ax=px+dx[i];
            int ay=py+dy[i];
            if(isValid(ax,ay)&&vis[ax][ay]==false){
                if((dis[ax][ay]>(dis[px][py]+grid[ax][ay]))){
                    dis[ax][ay]=dis[px][py]+grid[ax][ay];
                }
            }
        }
    }
    cout<<dis[n-1][n-1]<<endl;
}
void reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dis[i][j]=INT_MAX;
            vis[i][j]=false;
        }
    }
}
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>grid[i][j];
            }
        }
        reset();
        dijkstra(0,0);
    }
    return 0;
}
