#include<iostream>
using namespace std;
int t,n;
string s;

bool Check(int l,int r){
    while(l<=r){
        if(s[l]!=s[r])
            return false;
        l++,r--;
    }
    return true;
}
int main()
{
    cin>>t;
    while(t--){
        cin>>s;
        int l=s.length();
        cout<<(Check(0,l-1)?"Yes":"No")<<endl;
    }
    return 0;
}
