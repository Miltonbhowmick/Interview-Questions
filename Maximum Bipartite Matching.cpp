/*
6 6
0 1 1 0 0 0
1 0 0 1 0 0
0 0 1 0 0 0
0 0 1 1 0 0
0 0 0 0 0 0
0 0 0 0 0 1

5
*/
#include<iostream>
#define MAX 10000
using namespace std;
int m,n,grid[MAX][MAX],matchR[MAX];
bool vis[MAX];
/// dfs for each jobs
bool dfs(int u){
    for(int v=0;v<m;v++){
        if(vis[v]==false&&grid[u][v]){
            vis[v]=true;
            if(matchR[v]>0){
                if(dfs(v))
                    return true;
            }
            else{
                matchR[v]=u;
                return true;
            }
        }
    }
    return false;
}
/// for all applicants
void maxBPM(){
    for(int i=0;i<m;i++)
        matchR[i]=-1;
    int result=0;
    for(int u=0;u<n;u++){

        /// unvisited all jobs for u
        for(int i=0;i<m;i++)
            vis[i]=false;

        if(dfs(u))
            result++;
    }
    cout<<result<<endl;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    maxBPM();
    return 0;
}
