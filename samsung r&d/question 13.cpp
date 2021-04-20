/*
3
0 0 50 50
1 2 4 5 10
3 4 6 7 20
10 20 15 18 30


*/
#include<iostream>
#define MAX 1000
using namespace std;
int grid_worm[MAX][5],n,sx,sy,dx,dy,ans,dis;
bool vis[MAX];
/// bidirectional wormholes!!

int abs(int x){
    if(x<0) return-1*x;
    return x;
}
int distance(int sx,int sy,int dx,int dy){
    return abs(sx-dx)+abs(sy-dy);
}
void fn(int sx,int sy,int dx,int dy,int dis){
    ans=min(ans, distance(sx,sy,dx,dy)+dis);

    for(int i=0;i<n;i++){
        if(vis[i]==false){
            vis[i]=true;
            /// Bidirectional IMPORTANT!!
            int temp=distance(sx,sy,grid_worm[i][0],grid_worm[i][1])+grid_worm[i][4]+dis;
            fn(grid_worm[i][2],grid_worm[i][3],dx,dy,temp);
            temp=distance(sx,sy,grid_worm[i][2],grid_worm[i][3])+grid_worm[i][4]+dis;
            fn(grid_worm[i][0],grid_worm[i][1],dx,dy,temp);
            vis[i]=false;
        }
    }
}
int main()
{
    cin>>n;
    cin>>sx>>sy>>dx>>dy;

    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin>>grid_worm[i][j];
        }
    }
    ans=1e6;
    fn(sx,sy,dx,dy,0);
    cout<<ans<<endl;
    return 0;
}
