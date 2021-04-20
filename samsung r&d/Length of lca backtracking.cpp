#include<iostream>
using namespace std;
string s,r;

int lcs(int m,int n){
    if(m==0||n==0)
        return 0;
    else if(s[m-1]==r[n-1]){
        int a=1+lcs(m-1,n-1);
        return a;
    }
    else{
        int mx=max(lcs(m,n-1),lcs(m-1,n));
        return mx;
    }


}
int main()
{
    cin>>s;
    cin>>r;
    int m=s.length();
    int n=r.length();
    cout<<lcs(m,n)<<endl;
    return 0;
}
