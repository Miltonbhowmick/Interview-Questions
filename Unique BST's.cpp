#include<iostream>
using namespace std;
long long t,n;

long long binomial(long long n, long long k){
    int res=1;
    /// C(n,k)=C(n,n-k);
    if(k>(n-k))
        k=n-k;
    /// n*(n-1)*(n-2)*.....*(n-k+1)/(k*(k-1)*(k-2)*....*1
    for(int i=0;i<k;i++){
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
long long catalan(long long n){
    long long c=binomial(2*n,n);
    return c/(n+1);
}
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        cout<<catalan(n)<<endl;
    }
    return 0;
}
