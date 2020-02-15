#include<iostream>
using namespace std;
int t,a,b;

int Check(int d){
    int cnt=0;
    while(d){
        cnt+=d&1;
        d>>=1;
    }
    return cnt;
}
int main()
{
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<Check(a^b)<<endl;
    }
    return 0;
}
