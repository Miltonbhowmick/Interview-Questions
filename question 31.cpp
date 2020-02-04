
/// You have to find the node which has highest possibility to reach after t time
/// from the source node!!!

#include<iostream>
#define MAX 1000
using namespace std;
int n,e,t;
float grid[MAX][MAX];
float finale[MAX-100];

void dfs(int curr_node,float p, int time){
    if(time<=0){
        finale[curr_node]+=p;
        return;  /// IMPORTANT!!!
    }

    for(int i=0;i<n;i++){
        if(grid[curr_node][i]>0)
            dfs(i,p*grid[curr_node][i],time-10);
    }
}
int main()
{
    for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++){
            grid[i][j]=0;
        }
        finale[i] = 0;
    }

    cin>>n>>e>>t;
    for(int i=0;i<e;i++){
            int x,y;
            float p;
            cin>>x>>y>>p;
            grid[x][y]=p;
    }
    int start;
    cin>>start;

    if(t<=10){
        cout<<start<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(grid[start][i]>0){
            dfs(i,grid[start][i],t-10);
        }
    }

    float mx=-1;
    int pos=start;
    for(int i=0;i<n;i++){
        if(finale[i]>mx){
            pos=i;
            mx=finale[i];
        }
    }
    cout<<pos<<" "<<mx<<endl;
    return 0;
}
