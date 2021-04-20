#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
int n,arr[MAX],k;
bool isFeasible(int mid){
    int pos=arr[0],e=1;
    for(int i=1;i<n;i++){
        if(arr[i]-pos>=mid){
            pos=arr[i];
            e++;
            if(e==k)
                return true;
        }
    }
    return false;
}
void solution()
{
    sort(arr,arr+n);
    int res=-1;
    int start=arr[0],endd=arr[n-1];
    while(start<endd){
        int mid=(start+endd)/2;
        if(isFeasible(mid)){
            res=max(res,mid);
            start=mid+1;
        }
        else
            endd=mid;
    }
    cout<<res<<endl;
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    solution();
    return 0;
}
