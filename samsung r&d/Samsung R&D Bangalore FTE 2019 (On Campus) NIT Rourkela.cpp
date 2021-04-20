#include<iostream>
using namespace std;
int total_h,total_d,se[6][2];

void solution(){
    int powset=32,sum,check_eng,time,mn=123456;
    for(int counter=0;counter<powset;counter++){
        sum=0;
        check_eng=total_h;
        time=0;
        for(int j=0;j<5;j++){
            if(counter&(1<<j)){
                sum+=se[j][0];
                check_eng-=se[j][1];
                time++;
            }
        }
        cout<<sum<<" "<<check_eng<<endl;
        if(sum>=total_d&&check_eng>=0){
            mn=min(time,mn);
        }
    }
    if(mn<123456)
        cout<<mn<<endl;
    else
        cout<<-1<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>total_h>>total_d;
        for(int i=0;i<5;i++)
            cin>>se[i][0]>>se[i][1];
        solution();
    }
    return 0;
}
