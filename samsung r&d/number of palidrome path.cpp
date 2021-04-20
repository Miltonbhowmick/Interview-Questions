#include<iostream>
#define MAX 10000
using namespace std;
int t,r,c,grid[MAX][MAX];
bool vis[MAX][MAX];
void NumPalin(int x,int y,int &cnt){
    if(x==n-1&&y==n-1){
        cnt++;
    }

    if(vis[x][y]==true)
        return;

    NumPalin(x+1,y,cnt);
    NumPalin(x,y+1,cnt);
    NumPalin(x-1,y,cnt);
    NumPalin(x+1,y-1,cnt);
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
    }
    NumPalin(0,0);
    return 0;
}
