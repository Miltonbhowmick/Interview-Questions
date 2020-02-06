/*
4 4
0 0 0 0
0 -1 0 0
-1 0 0 0
0 0 0 0
*/

#include<iostream>
#define MAX 1000
using namespace std;
int grid[MAX][MAX],r,c;

int FindPath(){
    if(grid[0][0]==-1)
        return 0;
    for(int i=0;i<r;i++){
        if(grid[i][0]>=0)
            grid[i][0]=1;
        else
            break;
    }
    for(int i=0;i<c;i++){
        if(grid[0][i]>=0)
            grid[0][i]=1;
        else
            break;
    }
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(grid[i][j]!=-1){
                if(grid[i-1][j]>0)
                    grid[i][j]+=grid[i-1][j];
                if(grid[i][j-1]>0)
                    grid[i][j]+=grid[i][j-1];
            }
        }
    }
    return (grid[r-1][c-1]>0)?grid[r-1][c-1]:0;
}
int main()
{
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>grid[i][j];
        }
    }

    cout<<FindPath()<<endl;
    return 0;
}
