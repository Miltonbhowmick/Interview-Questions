#include<iostream>
#include<cstdio>
#define MAX 10000
using namespace std;
int n,r,c,grid[MAX][MAX],sol[MAX][MAX];
/// node
bool isValid(int x,int y){
    if(x>=0&&x<=n-1&&y>=0&&y<=n-1&&grid[x][y])
        return true;
    return false;
}
bool SolveMaze(int x,int y,int &cost,int ck){
    if(x==r&&y==c){
        cout<<x<<" "<<y<<endl;
        if(ck==2) cost++,cout<<131<<endl;
        sol[x][y]=1;
        return true;
    }
    if(isValid(x,y)){
        /// to x
        sol[x][y]=1;

        if(SolveMaze(x+1,y,cost,1)==true)
            return true;
        if(SolveMaze(x,y+1,cost,2)==true){
            cost++;
            cout<<12312<<endl;
            return true;
        }

        sol[x][y]=0;
        return false;
    }
    return false;
}
void printSolution()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}
int main()
{
    cin>>n>>r>>c;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    int cost=0;
    SolveMaze(0,0,cost,0);
    cout<<cost<<endl;
    printSolution();
    return 0;
}
