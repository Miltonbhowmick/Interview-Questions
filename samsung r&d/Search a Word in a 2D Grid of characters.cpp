#include<iostream>
#define MAX 1000
using namespace std;
int r,c,l;
char grid[MAX][MAX];
string s;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,0,-1,1};
int cnt,pos[MAX][2];

bool isValid(int x,int y){
    if(x>=0&&x<=r-1&&y>=0&&y<=c-1)
        return true;
    return false;
}
bool dfs(int sx,int sy,int go){
    bool ck=false;
    int ax,ay;
    int len=s.length();
    for(int j=0;j<8;j++){
        int i;
        ax=sx,ay=sy;
        for(i=0;i<len;i++){
            if(isValid(ax,ay)==false)
                break;
            if(s[i]!=grid[ax][ay])
                break;

            ax=ax+dx[j];
            ay=ay+dy[j];
        }
        if(i==len) return true;
    }
    return false;
}
/*
3 13
GEEKSFORGEEKS
GEEKSQUIZGEEK
IDEQAPRACTICE
GEEKS
*/
bool CheckPatt(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==s[0]){
                int len=1,go=0;
                if(dfs(i,j,go)){
                    cout<<i<<" "<<j<<endl;
                }
            }
        }
    }
    return false;
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
    cout<<CheckPatt()<<endl;
    return 0;
}
