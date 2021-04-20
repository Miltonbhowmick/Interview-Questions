#include<iostream>
#include<climits>
using namespace std;
int n,gt1,gt2,gt3,fn1,fn2,fn3;

int abs(int x){
    if(x<0) return -1*x;
    return x;
}
void solution(){
    int c_m=INT_MAX;
    for(int i=1;i<=n-fn2-fn3;i++){
        for(int j=i+fn1;j<=n-fn3;j++){
            for(int k=j+fn2;k<=n;k++){
                int c=0;

                for(int p=i;p<i+fn1;p++)
                    c+=abs(gt1-p);
                for(int p=j;p<j+fn2;p++)
                    c+=abs(gt2-p);
                for(int p=k;p<k+fn3;p++)
                    c+=abs(gt3-p);
                c+=fn1+fn2+fn3;
                c_m=min(c_m,c);
            }
        }
    }
    cout<<c_m<<endl;
}
int main()
{
    cin>>n;
    cin>>gt1>>gt2>>gt3;
    cin>>fn1>>fn2>>fn3;
    solution();
    return 0;
}
