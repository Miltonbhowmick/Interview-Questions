#include<iostream>
using namespace std;
string s;
int level,k,sum;
int main()
{
    cin>>k;
    cin>>s;
    int l=s.length();
    for(int i=0;i<l;i++){
        if(s[i]=='(')
            level++;
        else if(s[i]==')')
            level--;
        else{
            if((level-1)==k){
                ///num
                int j=i,ss=0;
                while(j<l&&s[j]!='('&&s[j]!=')'){
                    ss+=(s[j]-'0');
                    j++;
                    if(s[j]!='('&&s[j]!=')')ss*=10;
                }
                cout<<ss<<endl;
                sum+=ss;
                i=j-1;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
