#include<iostream>
#define MAX 10000
using namespace std;
int n,m,grid[MAX][MAX];

/// direction
int dx[8]={1,1,-1,-1,2,2,-2,-2};
int dy[8]={-2,2,-2,2,-1,1,-1,1};

bool isValid(int x,int y){
    if(x>=0&&x<=n-1&&y>=0&&y<=m-1)
        return true;
    return false;
}
void FindPossibleMoves(int px,int py){
    int cnt=0;
    for(int i=0;i<8;i++){
        int ax=px+dx[i];
        int ay=py+dy[i];
        if(isValid(ax,ay)&&grid[ax][ay]==0){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int sx,sy;
    cin>>sx>>sy;
    FindPossibleMoves(sx,sy);
    return 0;
}
