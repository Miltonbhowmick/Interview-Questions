#include<iostream>
using namespace std;
int a,b;

int FlippedCount(int d){
   int cnt=0;
   while(d){
        cnt+=(d&1);
        d>>=1;
   }
   return cnt;
}
int main()
{
    cin>>a>>b;
    cout<<FlippedCount(a^b)<<endl;
    return 0;
}
