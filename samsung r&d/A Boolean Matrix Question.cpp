#include<iostream>
#define MAX 10000
using namespace std;
int n,grid[MAX][MAX],m;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool isValid(int x,int y){
    if(x>=0&&x<=n-1&&y>=0&&y<=m-1)
        return true;
    return false;
}
void Moves(int x,int y){
    for(int i=0;i<4;i++){
        int ax=x+dx[i];
        int ay=y+dy[i];
        while(isValid(ax,ay)){
            if(grid[ax][ay]==0)grid[ax][ay]=2;
            ax=ax+dx[i];
            ay=ay+dy[i];
        }
    }

}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>grid[i][j];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                Moves(i,j);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(grid[i][j]==2||grid[i][j]==1)
            cout<<1<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
    return 0;
}
