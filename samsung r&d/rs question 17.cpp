#include<iostream>
using namespace std;
int n;

/// first 2nCn the 2nCn/(n+1)
/// binomial for 2nCn
unsigned long int binomial(unsigned int n, unsigned int k){
    unsigned long int res=1;
    /// C(n,k)=C(n,n-k)
    if(k>n-k)
        k=n-k;

    /// [n*(n-1)*(n-2)*....*(n-k+1)]/[k*(k-1)*....*1]
    for(int i=0;i<k;i++){
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
/// catalan
unsigned long int catalan(unsigned int n){
    unsigned long int c = binomial(2*n,n);
    return c/(n+1);
}
int main()
{
    cin>>n;
    cout<<catalan(n)<<endl;
    return 0;
}
