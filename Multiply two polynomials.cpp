#include<iostream>
#define MAX 10000
using namespace std;
int t,m,n,a[MAX],b[MAX];
int main()
{
    cin>>t;
    while(t--){
        cin>>m>>n;
        for(int i=0;i<m;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        int sz=m+n-1;
        int ans[sz];
        for(int i=0;i<sz;i++)
            ans[i]=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i+j]+=(a[i]*b[j]);
            }
        }
        for(int i=0;i<sz;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
