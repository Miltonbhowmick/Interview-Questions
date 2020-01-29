#include<iostream>
#define MAX 10000
using namespace std;
int V,E,graph[MAX][MAX];
bool visited[MAX];

int dfs(int u){
    visited[u]=true;
    for(int i=0;i<V;i++){
        if(graph[u][i]){
            if(visited[i]){
                return true;
            }
            else{
                int x=dfs(i);
                if(x==1) return true;
            }
        }
    }
    return false;
}

void reset(){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            graph[i][j]=0;
        }
        visited[i]=false;
    }
}
int main()
{
    cin>>V>>E;
    for(int i=0;i<E;i++){
        int x,y;
        cin>>x>>y;
        graph[x][y]=1;
    }
    cout<<dfs(0)<<endl;;
    return 0;
}
