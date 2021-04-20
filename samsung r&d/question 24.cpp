#include<iostream>
#define MAX 1000
using namespace std;

struct Interval{
    int buy;
    int sell;
};
void MaxProfit(int price[],int n){
    int cnt = 0;
    if(n==1)
        return ;
    int i=0;
    Interval sol[(n/2)+1]; ///  Storing buy cost and sell cost

    while(i<n-1){
        if(n==1)
            return;

        while(i<n && price[i]>=price[i+1]) /// 7 6 5 4 3 i.e no profit
            i++;
        if(i==n-1)
            break;
        sol[cnt].buy=i; /// start buy
        while(i<n-1 && price[i]<=price[i+1]) /// check until getting large profit
            i++;
        sol[cnt].sell=i;

        cnt++;
    }
    if(cnt==0) cout<<"There is no day to profit"<<endl;
    else{
        int sum=0;
        for(int i=0;i<cnt;i++){
//            cout<<sol[i].buy<<" "<<sol[i].sell<<endl;
            sum+=price[sol[i].sell]-price[sol[i].buy];
        }
        cout<<sum<<endl;
    }
}
int main()
{
    int price[1000],n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>price[i];
    MaxProfit(price,n);

    return 0;
}
