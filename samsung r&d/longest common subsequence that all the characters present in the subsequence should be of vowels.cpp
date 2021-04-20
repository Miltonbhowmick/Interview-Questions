#include<iostream>
using namespace std;
string x,y;
int n,m;

bool isVowel(char ch){
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        return true;
    return false;
}
void lcs(){
    int L[n+1][m+1];
    int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            if(i==0||j==0)
                L[i][j]=0;
            else if(x[i-1]==y[j-1]&&isVowel(x[i-1]))
                L[i][j]=L[i-1][j-1]+1;
            else
                L[i][j]=max(L[i-1][j],L[i][j-1]);
        }
    }
    cout<<L[n][m]<<endl;
}
int main()
{
    cin>>x>>y;
    n=x.length();
    m=y.length();
    lcs();
    return 0;
}
