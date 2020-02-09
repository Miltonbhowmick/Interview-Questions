/*
4
0 1 1 1
1 1 2 1
0 1 0 1
1 2 1 2
3
1 2
3 1
3 3
*/

#include<iostream>
#include<cstdio>
#include<climits>
#define MAX 20
using namespace std;

int n,r,grid[MAX][MAX], rear_dis[5],road_dis[MAX],dis[MAX][MAX];
bool vis[MAX][MAX];
/// direction
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool isValid(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<n)
        return true;
    return false;
}
/// Queue
struct Cell{
    int x;
    int y;
};
int fnt=-1,rear=-1;
Cell q[1000];
void push(Cell data){
    if(fnt==-1) fnt=0;
    q[++rear]=data;
}
void pop(){
    if(fnt>rear) return;
    fnt++;
}
bool isEmpty(){
    if(fnt==-1 || fnt>rear)
        return true;
    return false;
}
Cell Front(){
    return q[fnt];
}
/// Queue End

int bfs(Cell src, int mn){
    int mx=-1;
    push(src);
    vis[src.x][src.y]=true;
    dis[src.x][src.y]=0;
    while(!isEmpty()){
        Cell v;
        v=Front();
        int px=v.x;
        int py=v.y;
        pop();
        vis[px][py]=true;
        for(int i=0;i<4;i++){
            int ax = px+dx[i];
            int ay = py+dy[i];
            if(isValid(ax,ay)&&vis[ax][ay]==false&&grid[ax][ay]){
                Cell c;
                c.x=ax;
                c.y=ay;
                push(c);
                dis[ax][ay] =  dis[px][py]+1;
                if(grid[ax][ay]==2){
                    mx=max(dis[ax][ay],mx);
                }
            }
        }
    }
    mn=min(mx,mn);
    return mn;
}
void reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vis[i][j]=false;
            dis[i][j]=0;
        }
    }
}
int MinPath(){
    int mn=1e3;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                reset(); /// IMPORTANT!!
                Cell src;
                src.x=i;
                src.y=j;
                mn = bfs(src,mn);
            }
        }
    }
    return mn;
}
int main()
{
    cin>>n>>r;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<r;i++){
        int x,y;
        cin>>x>>y;
        grid[x][y]=2;
    }
    cout<<MinPath()<<endl;
    return 0;
}
