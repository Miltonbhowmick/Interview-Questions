#include<iostream>
#define MAX 10000
using namespace std;
int n,m,r,c,l,grid[MAX][MAX],dis[MAX][MAX];
bool vis[MAX][MAX];
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
        else return false;
    }
    Cell Front(){
        return arr[fnt];
    }
};
/// direction
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
/// change x y
void ChangeX(int a,int b,int c,int d){
//    cout<<121<<endl;
    dx[0]=a;dx[1]=b;dx[2]=c;dx[3]=d;
}
void ChangeY(int a,int b,int c,int d){
    dy[0]=a;dy[1]=b;dy[2]=c;dy[3]=d;
}
void CheckDir(int val){
    if(val==1){
        ChangeX(1,-1,0,0);
        ChangeY(0,0,1,-1);
    }
    else if(val==2){
        ChangeX(1,-1,0,0);
        ChangeY(0,0,0,0);
    }
    else if(val==3){
        ChangeX(0,0,0,0);
        ChangeY(0,0,1,-1);
    }
    else if(val==4){
        ChangeX(0,-1,0,0);
        ChangeY(0,0,1,0);
    }
    else if(val==5){
        ChangeX(1,0,0,0);
        ChangeY(0,0,1,0);
    }
    else if(val==6){
        ChangeX(1,0,0,0);
        ChangeY(0,0,0,-1);
    }
    else if(val==7){
        ChangeX(0,-1,0,0);
        ChangeY(0,0,-1,0);
    }
}
bool isValid(int x,int y){
    if(x>=0&&x<=n-1&&y>=0&&y<=m-1)
        return true;
    else return false;
}
bool CheckPipe(int ax,int ay,int px,int py){
    CheckDir(grid[ax][ay]);
    for(int i=0;i<4;i++){
        int bx=ax+dx[i];
        int by=ay+dy[i];
        if(px==bx&&py==by&&isValid(bx,by)&&grid[bx][by]>0&&vis[bx][by]==true)
            return true;
    }
    return false;
}
/// bfs
void bfs(int r,int c,int l){
    int cnt=0;
    Cell src;
    src.x=r;
    src.y=c;
    Queue q;
    q.push(src);
    dis[r][c]=0;
    while(!q.isEmpty()){
        Cell u=q.Front();
        q.pop();
        int px=u.x;
        int py=u.y;
        vis[px][py]=true;
        for(int i=0;i<4;i++){
            CheckDir(grid[px][py]);
            int ax=px+dx[i];
            int ay=py+dy[i];

//            cout<<grid[ax][ay]<<endl;
            if(isValid(ax,ay)&&grid[ax][ay]&&CheckPipe(ax,ay,px,py)==true&&vis[ax][ay]==false){
                Cell v;
                v.x=ax;
                v.y=ay;
                q.push(v);
                Cell abc=q.Front();
                cout<<abc.x<<"--"<<abc.y<<endl;
                dis[ax][ay]=dis[px][py]+1;
                if(dis[ax][ay]<=l)
                    cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}
int main()
{
    cin>>n>>m>>r>>c>>l;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    bfs(r,c,l);
    return 0;
}
