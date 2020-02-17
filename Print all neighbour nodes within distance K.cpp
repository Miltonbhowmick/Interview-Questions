#include<iostream>
#define MAX 10000
using namespace std;
int v,e,grid[MAX][MAX],k,dis[MAX];
bool vis[MAX];

class Queue{
public:
    int fnt,rear,num_ele;
    int arr[MAX];
    Queue(){
        fnt=rear=-1;
    }
    void push(int data){
        if(fnt==-1) fnt=0;
        arr[++rear]=data;
    }
    void pop(){
        if(fnt==-1||fnt>rear) return ;
        fnt++;
    }
    bool isEmpty(){
        if(fnt==-1||fnt>rear) return true;
        return false;
    }
    int Front(){
        return arr[fnt];
    }
};

void bfs(int src){
    Queue q;
    q.push(src);

    while(!q.isEmpty()){
        int u=q.Front();
        if(dis[u]<=k)
            cout<<u<<" ";
        q.pop();
        vis[u]=true;
        for(int i=1;i<=v;i++){
            if(grid[u][i]){
                if(vis[i]==false){
                    q.push(i);
                    vis[i]=true;
                    dis[i]=dis[u]+1;
                }
            }
        }
    }
}
int main()
{
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        grid[x][y]=1;
        grid[y][x]=1;
    }
    int src;
    cin>>src>>k;
    bfs(src);
    return 0;
}
