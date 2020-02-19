#include<iostream>
#define MAX 1000
using namespace std;
int t,n,grid[MAX][MAX],sx,sy;
bool vis[MAX][MAX];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

struct Cell{
    int x;
    int y;
};
/// Queue
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
        if(fnt==-1||fnt>rear) return;
        fnt++;
    }
    bool isEmpty(){
        if(fnt==-1||fnt>rear) return true;
        return false;
    }
    Cell Front(){
        return arr[fnt];
    }
};
/// Queue end
bool isValid(int x,int y){
    if(x>=0&&x<=n-1&&y>=0&&y<=n-1)
        return true;
    return false;
}
bool bfs(int sx,int sy){
    vis[sx][sy]=true;
    Cell src;
    src.x=sx;
    src.y=sy;
    Queue q;
    q.push(src);
    vis[sx][sy]=true;
    while(!q.isEmpty()){
        Cell u=q.Front();
        q.pop();
        int px=u.x;
        int py=u.y;
        for(int i=0;i<4;i++){
            int ax = px+dx[i];
            int ay = py+dy[i];
            if(isValid(ax,ay)&&grid[ax][ay]!=0&&vis[ax][ay]==false){
                vis[ax][ay]=true;
                Cell v;
                v.x=ax;
                v.y=ay;
                q.push(v);
                if(grid[ax][ay]==2) return true;
            }
        }
    }
    return false;
}
void reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vis[i][j]=false;
        }
    }
}
int main()
{
    cin>>t;
    while(t--){
        reset();
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>grid[i][j];
                if(grid[i][j]==1) sx=i,sy=j;
            }
        }
        cout<<bfs(sx,sy)<<endl;
    }
    return 0;
}
