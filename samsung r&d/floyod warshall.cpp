#include<iostream>
#include<climits>
#define MAX 10000
using namespace std;
int t,v,grid[MAX][MAX],dis[MAX][MAX];

void floydWar(){
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                dis[i][j]=min(dis[i][j],(dis[i][k]+dis[k][j]));

            }
        }
    }
}
void print(){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(dis[i][j]==10000000)
                cout<<"INF"<<" ";
            else
                cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>v;
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                cin>>s;
                if(s=="INF") grid[i][j]=10000000;
                else{
                    int l=s.length();
                    int e=s[0]-'0';
                    for(int p=1;p<l;p++){
                        e*=10;
                        e+=(s[p]-'0');
                    }
                    grid[i][j]=e;
                }
                dis[i][j]=grid[i][j];
            }
        }
        floydWar();
        cout<<
    }
    return 0;
}
