#include<iostream>
using namespace std;
string s;

void swp(char *a, char *b){

    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}

void Reverse(){
    int len=s.length(),f,l;
    f=0;
    for(int i=0;i<=len;i++){
        if(s[i]==' '||i==len){
            l=i-1;
            while(f<l){
                swp(&s[f],&s[l]);
                f++,l--;
            }
            f=i+1;
        }
    }
    cout<<s<<endl;
}

int main()
{
    getline(cin,s);
    Reverse();
    return 0;
}
