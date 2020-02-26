#include<iostream>
#define MAX 10000
using namespace std;
int n,grid[MAX][MAX],dis[MAX][MAX];
bool vis[MAX][MAX];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

struct Cell{
    int x;
    int y;
};
/// queue
class Queue{
public:
    int fnt,rear;
    Cell arr[MAX];
    Queue(){
        fnt=rear=-1;
    }
    void push(Cell data){
        if(fnt==-1) fnt=0;
        arr[++rear]=data;
    }
    void pop(){
        if(fnt==-1||fnt>rear) return ;
        fnt++;
    }
    bool isEmpty(){
        if(fnt==-1||fnt>rear) return true;
        else return  false;
    }
    Cell Front(){
        return arr[fnt];
    }
};
bool isValid(int x,int y){
    if(x>=0&&x<=n-1&&y>=0&&y<=n-1)
        return true;
    return false;
}
void bfs(Cell src){
    dis[src.x][src.y]=0;
    vis[src.x][src.y]=true;
    Queue q;
    q.push(src);
    while(!q.isEmpty()){
        Cell u=q.Front();
        q.pop();
        int px=u.x;
        int py=u.y;
        for(int i=0;i<4;i++){
            int ax=px+dx[i];
            int ay=py+dy[i];
            if(isValid(ax,ay)&&vis[ax][ay]==false&&grid[ax][ay]){
                Cell v;
                v.x=ax;
                v.y=ay;
                q.push(v);
                vis[ax][ay]=true;
                if(i==0||i==1)
                    dis[ax][ay]=dis[px][py]+1;
                else
                    dis[ax][ay]=dis[px][py];
            }
        }
    }
    cout<<dis[n-1][n-1]<<endl;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    Cell src;
    src.x=0;
    src.y=0;
    bfs(src);
    return 0;
}
/*
5
1 0 0 0 0
1 0 1 1 1
1 0 1 0 1
1 0 1 0 1
1 1 1 0 1
*/
