#include<iostream>
using namespace std;
int graph[15][15],input[15][2];
bool visited[15];
int V,E,save;

int abs(int a){
   if(a<0) return -1*a;
   else return a;
}
void tsp(int src, int V, int cnt, int cost, int &ans){

    if(cnt==V&&graph[src][0]){
        ans = min(ans, cost+graph[src][V]);
        return ;
    }
    for(int i=0;i<V;i++){
        if(!visited[i]&&graph[src][i]){
            visited[i]=true;
            tsp(i,V,cnt+1,cost+graph[src][i],ans);
            visited[i]=false;
        }
    }
}
void reset(){
    for(int i=0;i<=15;i++){
        for(int j=0;j<=15;j++){
            graph[i][j]=abs(input[i][0]-input[j][0])+abs(input[i][1]-input[j][1]);
        }
        visited[i]=false;
    }
}
int main()
{
    for(int t=0;t<10;t++){
        int ans=1e3;
        int c; //customers
        cin>>c;
        int x,y,p,q;
        cin>>x>>y;
        input[0][0]=x,input[0][1]=y;
        cin>>p>>q;
        for(int i=1;i<=c;i++){
            cin>>x>>y;
            input[i][0]=x;
            input[i][1]=y;
        }
        input[c+1][0]=p,input[c+1][1]=q;
        reset();

        visited[0]=true;
        tsp(0,c+1,1,0,ans);
        cout<<"#"<<t+1<<" "<<ans<<endl;
    }

    return 0;
}
