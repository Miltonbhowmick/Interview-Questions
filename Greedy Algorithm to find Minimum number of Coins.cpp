#include<iostream>
using namespace std;
int n;
int deno[20]={1,2,5,10,20,50,100,500,1000};

void FindMin(int taka){
    int ans[10000],cnt=0;
    for(int i=8;i>=0;i--){
        while(taka>=deno[i]){
            taka-=deno[i];
            ans[cnt++]=deno[i];
        }
    }
    for(int i=0;i<cnt;i++)
        cout<<ans[i]<<" ";
}
int main()
{
    cin>>n;
    FindMin(n);
    return 0;
}
