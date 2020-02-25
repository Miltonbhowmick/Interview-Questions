#include<iostream>
#include<cstdlib>
#define MAX 10000
using namespace std;
int n,m,grid[MAX][MAX],k;

int pow(int x,int y){
    int val=1;
    for(int i=0;i<y;i++)
        val*=2;
    return val;
}
void solution()
{
    int sz=1;
    for(int i=0;i<=n*m;i++){
        sz*=2;
    }
    int *has=(int *)calloc(sz,sizeof(int));

    for(int i=0;i<n;i++){
        int keyVal=0;
        int zeros=0;
        for(int j=0;j<m;j++){
            keyVal+=(grid[i][j]*pow(2,j));
            if(grid[i][j]==0)
                zeros++;
        }
        if(((k-zeros)%2)==0&&(k-zeros)>=0)
            has[keyVal]++;
    }
    int mx=0;
    for(int i=0;i<=sz;i++){
        if(has[i]>mx){
            mx=i;
        }
    }
    cout<<has[mx]<<endl;
}
int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    solution();
    return 0;
}
