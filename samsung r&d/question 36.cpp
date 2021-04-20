#include<iostream>
#define MAX 1000
using namespace std;
int grid[MAX][MAX],l,n,m,r,c, dis[MAX][MAX];
bool vis[MAX][MAX];
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
    if(fnt==-1 || fnt>rear) return true;
    return false;
}
Cell Front(){
    return q[fnt];
}
/// Direction
int dx[4]={0,0,0,0};
int dy[4]={0,0,0,0};

bool isValid(int x,int y){
    if(x>=0&&x<=n&&y>=0&&y<=n)
        return true;
    return false;
}
void ChangeX(int a,int b,int c,int d){
    dx[0]=a,dx[1]=b,dx[2]=c,dx[3]=d;
}
void ChangeY(int a,int b,int c,int d){
    dy[0]=a,dy[1]=b,dy[2]=c,dy[3]=d;
}
void CheckPipe(int val){
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
        ChangeY(0,0,0,-1);
    }
    else{
        ChangeX(0,0,0,0);
        ChangeY(0,0,0,0);
    }
}
bool CheckAdj(int px,int py,int ax,int ay, int a){
    if(a==0) return false;
    CheckPipe(a);
    for(int i=0;i<4;i++){
        int bx = ax+dx[i];
        int by = ay+dy[i];
        if(px==bx&&py==by &&isValid(bx,by)&&vis[bx][by]==true&&grid[bx][by]){  /// vis[bx][by] True!!!! IMPORATANT

            return true;
        }
    }
    return false;
}
/// bfs
int bfs(int r, int c,int l){
    int cnt=0;
    Cell v;
    v.x=r;
    v.y=c;
    push(v);
    vis[r][c]=true;
    dis[r][c]=0;
    while(!isEmpty()){
        Cell v=Front();
        pop();
        int px=v.x;
        int py=v.y;
        vis[px][py]=true;
//        cout<<px<<"++"<<py<<endl;
        for(int i=0;i<4;i++){
            CheckPipe(grid[px][py]);
            int ax = px+dx[i];
            int ay = py+dy[i];
            if(CheckAdj(px,py,ax,ay,grid[ax][ay])&&vis[ax][ay]==false){ /// IMPORTANT
                Cell c;
                c.x=ax;
                c.y=ay;
                push(c);
                dis[ax][ay] = dis[px][py]+1;
                if(dis[ax][ay]<=l)
                    cnt++;
//                cout<<ax<<"--"<<ay<<endl;
            }
//                cout<<cnt<<endl;
        }
    }
    return cnt;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>r>>c>>l;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
                vis[i][j]=false;
            }
        }
        cout<<bfs(r,c,l)<<endl;
    }
    return 0;
}
