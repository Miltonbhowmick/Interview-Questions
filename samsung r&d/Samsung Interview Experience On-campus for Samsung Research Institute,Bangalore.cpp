#include<iostream>
#define SMALL 1000000
#define LARGE 1000000000000000
using namespace std;
long long a,b,c,k;
/// log
long long Log2n(long long n){
    if(n>1){
        return 1+Log2n(n/2);
    }
    else
        return 0;
}
/// fun for equation
long long func(long long a,long long b,long long c, long long n){
    long long res=a*n;
    long long logVal=Log2n(n);
    res+=b*n*logVal;
    res+=c*(n*n*n);
    return res;
}
/// get pos by binary search
void getPos(){
    long long start=1,endd=SMALL;
    if(c==0)
        endd=LARGE;
    while(start<=endd){
        long long mid=(start+endd)/2;
        long long val=func(a,b,c,mid);
        if(val==k){
            cout<<mid<<endl;
            break;
        }
        else if(k>val){
            start=mid+1;
        }
        else
            endd=mid-1;
    }
}
int main()
{
    cin>>a>>b>>c>>k;
    getPos();
    return 0;
}
