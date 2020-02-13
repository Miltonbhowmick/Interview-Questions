#include<iostream>
#include<cstdio>
#define MAX 10000
using namespace std;
int n,dx,dy,grid[MAX][MAX],sol[MAX][MAX];

bool isValid(int x,int y){
    if(x>=0&&x<=dx&&y>=0&&y<=dy&&grid[x][y]==1)
        return true;
    return false;
}
void printSolution()
{
    for (int i = 0; i <=n-1; i++) {
        for (int j = 0; j <=n-1; j++)
            printf("%d ", sol[i][j]);
        printf("\n");
    }
}

bool SolveMaze(int x,int y,int &cost){
    if(x==dx&&y==dy){
        cost++;
        sol[x][y]=1;
        return true;
    }
    if(isValid(x,y)==true){
        sol[x][y]=1;
        cost++;
        if(SolveMaze(x+1,y,cost)==true){
            return true;
        }
        if(SolveMaze(x,y+1,cost)==true){
            return true;
        }
        cost--;
        sol[x][y]=0;
        return false;
    }
    return false;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    int cost=0;
    cin>>dx>>dy;
    cout<<SolveMaze(0,0,cost)<<endl;
    cout<<cost<<endl;
    printSolution();
    return 0;
}
