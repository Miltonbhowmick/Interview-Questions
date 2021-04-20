#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a= n&0x0F;
    a = a<<4;
    int b= n&0xF0;
    b = b>>4;
    int ans=a|b;
    cout<<ans<<endl;

    return 0;
}
