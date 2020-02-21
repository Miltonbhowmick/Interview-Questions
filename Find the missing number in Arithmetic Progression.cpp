#include<iostream>
#define MAX 1000000
using namespace std;
int n,arr[MAX];

void findMissing(int start,int endd,int diff){
    int ans=0,mid,val;
    while(start<endd){
        mid=(start+endd)/2;
        val=arr[0]+(mid*diff);
        if(val==arr[mid]){
            start=mid+1;
        }
        else
            endd=mid-1;
    }
    if((arr[start+1]-arr[start])==diff) ans=arr[0]+(start*diff);
    else ans=arr[0]+((start+1)*diff);
    cout<<ans<<endl;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int diff=min((arr[1]-arr[0]),(arr[n-1]-arr[n-2]));

    findMissing(0,n-1,diff);
    return 0;
}
