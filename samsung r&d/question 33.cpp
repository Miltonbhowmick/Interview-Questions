#include<iostream>
using namespace std;
string s;
bool check101(int pos,int l){
    int zero=0, other=0;
    for(int i=pos;i<l;i++){
        if(s[i]=='0') zero++;
        else if(s[i]!='1') other++;
        else break;
    }
    if(other>0) return false;
    else if(zero==0) return false;
    else return true;
}
void NumPattern(int l){
    int cnt=0;
    for(int i=0;i<l;i++){
        if(s[i]=='1')
            cnt+=check101(i+1,l);
    }
    cout<<cnt<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        int l=s.length();
        NumPattern(l);
    }
    return 0;
}
