#include<iostream>
#define MAX 1000000
using namespace std;
int n,arr[MAX];

int checkPat(int n){
    int cnt=0;
    while(n){
        cnt+=n&1;
        n>>=1;
    }
    return cnt;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int sum=0;
    for(int i=0;i<n;i++){
        if((checkPat(arr[i])%2)==0)
            sum+=arr[i];
    }
    cout<<sum<<endl;
    return 0;
}
