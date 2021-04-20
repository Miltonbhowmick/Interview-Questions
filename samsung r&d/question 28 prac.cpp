#include<iostream>
using namespace std;
int k,level,sum;
string s;

void Add(string r){
    int l=r.length(),i=0;
    int s=0;
    while(i<l){
        s+=r[i]-'0';
        if((i+1)!=l) s*=10;
        i++;
    }
    cout<<s<<endl;
    sum+=s;
}
void SumK(){
    level=0;
    int l=s.length();
    for(int i=0;i<l;i++){
        if(s[i]=='(')
            level++;
        else if(s[i]!='('&&s[i]!=')'){
            int j=i;
            string r="";
            while(s[j]!='('&&s[j]!=')')
                r+=s[j],j++;
            if((level-1)==k) Add(r);
            i=j-1;
        }
        else
            level--;
    }
    cout<<sum<<endl;
}
int main()
{
    cin>>k>>s;
    SumK();

    return 0;
}
