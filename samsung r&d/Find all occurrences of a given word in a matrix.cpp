#include<iostream>
#define MAX 10000
using namespace std;
int r,c,l;
char grid[MAX][MAX];
bool vis[MAX][MAX];
string s;

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

bool isValid(int x,int y){
    if(x>=0&&x<=r-1&&y>=0&&y<=c-1)
        return true;
    return false;
}
void dfs(int sx,int sy,int cnt){

    if(cnt==l){
        cout<<sx<<" "<<sy<<endl;
        return;
    }
    for(int i=0;i<8;i++){
        int ax=sx+dx[i];
        int ay=sy+dy[i];
        if(isValid(ax,ay)&&s[cnt]==grid[ax][ay]&&vis[ax][ay]==false){
            vis[ax][ay]=true;
            dfs(ax,ay,cnt+1);
            vis[ax][ay]=false;
        }
    }
    return;
}
int main()
{
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>grid[i][j];
        }
    }
    cin>>s;
    l=s.length();
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==s[0]){
                vis[i][j]=true;
                dfs(i,j,1);
                vis[i][j]=false;
            }
        }
    }
    return 0;
}
