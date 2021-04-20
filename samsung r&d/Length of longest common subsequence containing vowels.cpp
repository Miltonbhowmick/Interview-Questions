#include<iostream>
using namespace std;
string s,r;
bool isVowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i'
        || ch == 'o' || ch == 'u')
        return true;
    return false;
}
int lcs(int m,int n){
    int L[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0)
                L[i][j]=0;
            else if((s[i-1]==r[j-1]&&isVowel(s[i-1])))
                L[i][j]=L[i-1][j-1]+1;
            else
                L[i][j]=max(L[i-1][j],L[i][j-1]);
        }
    }
    int index=L[m][n];
    char lcs[index+1];
    lcs[index]='\0';

    int i=m,j=n;
    while(i>0&&j>0){
        if(s[i-1]==r[j-1]){
            lcs[index-1]=s[i-1];
            i--;j--;index--;
        }
        else if(L[i-1][j]>L[i][j-1])
            i--;
        else
            j--;
    }
    cout<<lcs<<endl;
}
int main()
{
    cin>>s>>r;
    int m=s.length();
    int n=r.length();
    cout<<lcs(m,n)<<endl;
    return 0;
}
