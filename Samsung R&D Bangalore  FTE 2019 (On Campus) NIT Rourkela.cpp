/*
5
5 10
10 5
3 7
6 9
10 3
20 30
*/
#include<iostream>
#include<climits>
#define MAX 10000
using namespace std;
int n,pace[MAX][2],mn,dis,power;

void combinations(int i,int sum,int dis,int power){
    if(i==n)
        return;
    if(power<0) return;
    if(dis<0&&power<0) return;

    if(dis<=0&&power>=0){
        mn=min(sum,mn);
        return;
    }

    for(int j=i;j<n;j++){
        /// push
        combinations(j,sum+pace[j][1],dis-1,power-pace[j][0]);
        ///pop
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        int p,t;
        cin>>p>>t;
        pace[i][0]=p;
        pace[i][1]=t;
    }
    cin>>dis>>power;
    mn=INT_MAX;
    combinations(0,0,dis,power);
    cout<<mn<<endl;
    return 0;
}
