#include<iostream>
#define SMALL 1000000
#define LARGE 1000000000000000
using namespace std;
long long a,b,c,k;

/// log value
long long Log2n(long long n){
    if(n>1){
        return 1+Log2n(n/2);
    }
    else
        return 0;
}
/// func
long long func(long long a,long long b,long long c,long long n){
    long long res=a*n;
    long long logVal=Log2n(n);
    res+=b*logVal*n;
    res+=c*(n*n*n);
    return res;
}
/// binary search
long long getPosition(){
    long long start=1,endd=SMALL;
    if(c==0){
        endd=LARGE;
    }
    long long ans=0;
    while(start<=endd){
        long long mid=(start+endd)/2;
        long long val=func(a,b,c,mid);
        if(val==k){
            ans=mid;
            break;
        }
        else if(val>k){
            endd=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}
int main()
{
    cin>>a>>b>>c>>k;
    cout<<getPosition()<<endl;
    return 0;
}
