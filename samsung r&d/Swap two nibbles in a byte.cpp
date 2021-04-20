#include<iostream>
using namespace std;
int t,x;

int sw(){
    int f=x&0x0F;
    int l=x&0xF0;
    f=f<<4;
    l=l>>4;
    return f|l;
}
int main()
{
    cin>>t;
    while(t--){
        cin>>x;
        cout<<sw()<<endl;
    }
    return 0;
}
