#include<iostream>
using namespace std;

int main()
{
    int t,a,b,m;
    cin>>t;
    while(t--){
        cin>>a>>b>>m;

        int d=(b/m)-(a/m);
        if(a%m==0) d++;
        cout<<d<<endl;
    }
    return 0;
}
