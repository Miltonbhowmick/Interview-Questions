#include<iostream>
#define MAX 10000
using namespace std;

void FindProduct(int arr[MAX],int n, int s, int e, int k){
    int cnt=0;
    for(int i=s;i<=e;i++){
        if(arr[i]>=k)
            cnt++;
    }
    cout<<1+(e-s)-cnt<<endl;
}
int main()
{
    int arr[MAX],n,s,e,k;
    cin>>n>>s>>e>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    FindProduct(arr,n,s-1,e-1,k);

    return 0;
}
