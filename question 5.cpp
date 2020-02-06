#include<iostream>
#define MAX 1000
using namespace std;
int graph[MAX][MAX], path[MAX][MAX];

void PrintPath(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(path[i][j])
                cout<<1<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
}
bool isSafe(int x,int y,int n){
    if(x>=0&&x<=n-1&&y>=0&&y<=n-1&&graph[x][y]==1)
        return true;
    return false;
}
bool MazeFind(int x,int y, int n){
    if(x==n-1&&y==n-1&&graph[x][y]){
        path[x][y]=1;
        return true;
    }

    if(isSafe(x,y,n)){
        path[x][y]=1;
        if(MazeFind(x+1,y,n))
            return true;
        if(MazeFind(x,y+1,n))
            return true;
        path[x][y]=0;
        return false;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    int sx=0,sy=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    int ck = MazeFind(sx,sy,n);
    if(ck)
        PrintPath(n);
    else
        cout<<"No Solution"<<endl;
    return 0;
}
