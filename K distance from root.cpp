#include<iostream>
#define MAX 100000
using namespace std;
int t,v,e,k,level[MAX];
bool vis[MAX];
int main()
{
    cin>>t;
    while(t--){
        cin>>e>>k;
        for(int i=0;i<e;i++){
            int x,y;
            char ch;
            cin>>x>>y>>ch;
            if(x!=-1) v++,vis[x]=true;
            if(y!=-1) v++,vis[y]=true;
            if(i==0) level[x]=0;
            if(y!=-1)
                level[y]=level[x]+1;
        }
        for(int i=1;i<=v;i++)
            if(level[i]==k&&vis[i]==true)
                cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
