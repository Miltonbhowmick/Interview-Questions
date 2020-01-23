#include<iostream>
#define MAX 10000
using namespace std;
int t,n,arr[MAX],a,pos[MAX],check[100000];

int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        int cnt=0,mn=1e5;
        for(int i=0;i<100000;i++) check[i]=0;
        for(int i=0;i<n;i++){
            cin>>a;
            if(a>-1) pos[cnt++]=arr[i],mn=min(mn,a),check[a]++;
        }
        while(check[mn]>0) mn++;
        cout<<mn<<endl;
    }
    return 0;
}
