/*
3
0 0 100 100
1 2 120 120
4 5 120 100
6 8 150 180
*/
#include<iostream>
#define MAX 10000
using namespace std;
int n,grid[MAX][5],sx,sy,dx,dy,ans;
bool vis[MAX];
int abs(int x){
    if(x<0) return -1*x;
    return x;
}
int distance(int sx,int sy,int dx,int dy){
    return abs(sx-dx)+abs(sy-dy);
}
void worm(int sx,int sy,int dx,int dy,int dis){
    ans=min(ans,distance(sx,sy,dx,dy)+dis);
    cout<<distance(sx,sy,dx,dy)+dis<<endl;
    for(int i=0;i<n;i++){
        if(vis[i]==false){
            vis[i]=true;
            int temp=distance(sx,sy,grid[i][0],grid[i][1])+distance(grid[i][0],grid[i][1],grid[i][2],grid[i][3])+dis;
            worm(grid[i][2],grid[i][3],dx,dy,temp);
            temp=distance(sx,sy,grid[i][2],grid[i][3])+distance(grid[i][0],grid[i][1],grid[i][2],grid[i][3])+dis;
            worm(grid[i][0],grid[i][1],dx,dy,temp);
            vis[i]=false;
        }
    }
}
int main()
{
    cin>>n;
    cin>>sx>>sy>>dx>>dy;
    for(int i=0;i<n;i++){
         for(int j=0;j<4;j++){
            cin>>grid[i][j];
         }
    }
    ans=123456789;
    worm(sx,sy,dx,dy,0);
    cout<<ans<<endl;
    return 0;
}
