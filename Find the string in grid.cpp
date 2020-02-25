#include<iostream>
#define MAX 1000
using namespace std;
int t,n,m;
char grid[MAX][MAX];
string s;

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

bool isValid(int x,int y){
    if(x>=0&&x<=n-1&&y>=0&&y<=m-1)
        return true;
    else
        return false;
}
bool CheckWord(int x,int y){
    int l=s.length();
    for(int i=0;i<8;i++){
        int ax=x+dx[i];
        int ay=y+dy[i];
        int j=0;
        for(j=1;j<l;j++){
            if(isValid(ax,ay)) break;
            if(grid[ax][ay]!=s[j])
                break;
            ax=ax+dx[i];
            ay=ay+dy[i];
        }
        if(j==l)
            return true;
    }
    return false;
}
int main()
{
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        cin>>s;
        int ck=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==s[0]){
                    if(CheckWord(i,j))
                        cout<<i<<" "<<j<<", ",ck=1;
                }
            }
        }
        if(ck)
            cout<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;

}
