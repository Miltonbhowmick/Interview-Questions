#include<iostream>
using namespace std;
int t,n;

bool Check(){
    if(n==1) return true;
    else{
        int d=1;
        while(d<n) d<<=1;
        if(d==n) return true;
        else return false;
    }
}
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        if(Check())
            cout<<"True"<<endl;
        else
            cout<<"False"<<endl;
    }
    return 0;
}
