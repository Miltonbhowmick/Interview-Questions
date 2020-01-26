/// This is for undirected graph!!!!

#include<iostream>
#define MAX 1000
using namespace std;
int V,E,graph[MAX][MAX],last,parent[MAX];
bool visited[MAX];
bool flag=true;
int dfs(int u,int par){
    visited[u]=true;
    for(int i=0;i<V;i++){
        if(graph[u][i]){
            if(!visited[i]){
                if(dfs(i,u)) return true;
            }
            else if(i!=par){
                return true;
            }
        }
    }
    return false;
}
void reset(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            graph[i][j]=0;
        }
        visited[i]=false;
        parent[i]=0;
    }
}
int main()
{
    reset();
    cin>>V>>E;
    for(int i=0;i<E;i++){
        int x,y;
        cin>>x>>y;
        graph[x][y]=1;
        graph[y][x]=1;
    }
    if(dfs(0,-1))cout<<"Cycle"<<endl;
    else cout<<"No cycle"<<endl;
    return 0;
}
