#include<iostream>
using namespace std;
int graph[10000][10000], point[1000][5];
bool visited[10000];

int abs(int a){
    if(a<0) return -1*a;
    return a;
}

int distance(int sx,int sy,int dx, int dy){
    return abs(sx-dx)+abs(sy-dy);
}
void short_dis_to(int n,int sx,int sy,int dx,int dy,int cost,int &ans){

    ans=min(ans,distance(sx,sy,dx,dy)+cost);
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            visited[i]=true;
            int temp=distance(sx,sy,point[i][0],point[i][1])+point[i][4]+cost;
            short_dis_to(n,point[i][2],point[i][3],dx,dy,temp,ans);
            visited[i]=false;
        }
    }
}

void short_dis_by(int n, int sx,int sy,int dx,int dy,int cost,int &ans){
    ans=min(ans, distance(sx,sy,dx,dy)+cost);
    for(int i=n-1;i>=0;i--){
        if(visited[i]==false){
            visited[i]=true;
            int temp=distance(sx,sy,point[i][2],point[i][3])+point[i][4]+cost;
            short_dis_by(n,point[i][0],point[i][1],dx,dy,temp,ans);
            visited[i]=false;
        }
    }
}
int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int sx,sy,dx,dy;
        cin>>sx>>sy>>dx>>dy;
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin>>point[i][j];
            }
        }
        int ans=1e4;
        short_dis_to(n,sx,sy,dx,dy,0,ans);
        short_dis_by(n,dx,dy,sx,sy,0,ans);
        cout<<ans<<endl;
    }
    return 0;
}
