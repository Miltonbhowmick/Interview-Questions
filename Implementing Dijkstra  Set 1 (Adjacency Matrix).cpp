#include<iostream>
#include<climits>
#define MAX 10000
using namespace std;
int t,n,grid[MAX][MAX],dis[MAX],s;
bool vis[MAX];

/// minimum dis .... priority queue
int MinDis(){
    int mn=INT_MAX,idx;
    for(int i=0;i<n;i++){
        if(dis[i]<mn&&vis[i]==false){
            mn=dis[i];
            idx=i;
        }
    }
    return idx;
}
/// bfs as dijkstra

void dijkstra(int src){
    dis[src]=0;

    for(int c=0;c<n;c++){
        int u=MinDis();
        vis[u]=true;
        for(int i=0;i<n;i++){
            if(grid[u][i]){
                if(vis[i]==false){
                    if((dis[u]+grid[u][i])<dis[i])
                        dis[i]=dis[u]+grid[u][i];
                }
            }
        }

    }
    for(int i=0;i<n;i++)
        cout<<dis[i]<<endl;
    cout<<endl;
}
void reset(){
    for(int i=0;i<n;i++){
        vis[i]=false;
        dis[i]=INT_MAX;
    }
}
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        reset();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>grid[i][j];
            }
        }
        cin>>s;
        dijkstra(s);
    }
    return 0;
}
