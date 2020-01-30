#include<iostream>
using namespace std;

void swp(char *a, char *b){
    char temp = *a;
    *a=*b;
    *b=temp;
}
void GreaterNum(string s){
    string r=s;
    int l = s.length(),idx=l-1;
    int i;
    for(i=l-1;i>0;i--){
        if((s[i]-'0')<=(s[i-1]-'0'))
            swp(&s[i],&s[i-1]);
        else{
            swp(&s[i],&s[i-1]);
            idx=i;
            break;
        }
    }
    if(i==0){
        cout<<r<<endl;
        return;
    }
    for(int j=i;j<l;j++){
        int pos=j,mn=1e4;
        for(int k=j;k<l;k++){
            int c=s[k]-'0';
            if(c<mn)
                pos=k,mn=c;
        }
        swp(&s[j],&s[pos]);
    }
    cout<<s<<endl;
}
int main()
{
    string s;
    cin>>s;
    GreaterNum(s);
    return 0;
}
