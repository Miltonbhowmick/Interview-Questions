/*
3
1 2 2 2 2
2 2 2 2 2
2 2 2 2 2

output: 1
1st , 2nd, 3rd column can be the starting point to check all the cases
and get maximum coins. if we only check from centre of columns, it gives answer 0.
if we start from 1-column, it gives 1. That's why we are checking from 1,2,3 no column

6
0 1 0 2 0
0 2 2 2 1
0 2 1 1 1
1 0 1 0 0
0 0 1 2 2
1 1 0 0 1

output: 5
*/
#include<iostream>
#define MAX 1000
using namespace std;
int grid[MAX][MAX],r,max_coin;
bool bomb;
void go_to(int i,int j,int coins){

    if(j<0||j>=5)
        return;
    if(i==r){
        if(coins>max_coin){
            max_coin=coins;
        }
        return;
    }
    int flag=0,idx=0;
    int enemy_coord[50][2];
    if(grid[i][j]==2){
        if(bomb==true){
            if(coins>max_coin){
                max_coin=coins;
            }
            return;
        }
        else{
            bomb=true;
            flag=1;
            for(int x=i;x<min(i+5,r);x++){
                for(int y=0;y<5;y++){
                    if(grid[x][y]==2){
                        enemy_coord[idx][0]=x;
                        enemy_coord[idx++][1]=y;
                        grid[x][y]=0;
                    }
                }
            }
        }
    }
    else if(grid[i][j]==1)
        coins++;
    go_to(i+1,j,coins);
    go_to(i+1,j+1,coins);
    go_to(i+1,j-1,coins);

    if(flag==1){
        for(int c=0;c<idx;c++){  /// IMPORTANT!
            int x=enemy_coord[c][0];
            int y=enemy_coord[c][1];
            grid[x][y]=2;
        }
    }
    return;
}
int main()
{
    cin>>r;
    for(int i=0;i<r;i++){
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        grid[r-1-i][0]=a;
        grid[r-1-i][1]=b;
        grid[r-1-i][2]=c;
        grid[r-1-i][3]=d;
        grid[r-1-i][4]=e;
    }
    max_coin=0;
    go_to(0,1,0);
    go_to(0,2,0);
    go_to(0,3,0);

    cout<<max_coin<<endl;

    return 0;
}
