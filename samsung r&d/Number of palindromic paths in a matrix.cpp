/*
aaab
baaa
abba
*/
#include<iostream>
#define MAX 10000
using namespace std;
int n,m,cnt,idx;
char grid[MAX][MAX];
char r[MAX];
bool CheckPal(char *r,int idx){
    int s=0,e=idx;
    while(s<=e){
        if(r[s]!=r[e]) return false;
        s++,e--;
    }
    return true;
}
bool isValid(int x,int y){
    if(x>=0&&x<=n-1&&y>=0&&y<=m-1)
        return true;
    return false;
}
void dfs(int x,int y,int idx){
    if(x==n-1&&y==m-1){
        r[idx]=grid[x][y];
        if(CheckPal(r,idx)){
            cnt++;
        }
        return;
    }
    if(isValid(x,y)){
        r[idx]=grid[x][y];
        dfs(x,y+1,idx+1);
        dfs(x+1,y,idx+1);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    dfs(0,0,0);
    cout<<cnt<<endl;
    return 0;
}
