#include<iostream>
#define MAX 1000
using namespace std;
int n,arr[MAX],dp[MAX][MAX];

int solution(){
    for(int len=1;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int j=i+len-1;
            for(int k=i;k<=j;k++){
                int leftval=1;
                int rightval=1;
                if(i!=0){
                    leftval=arr[i-1];
                }
                if(j!=n-1){
                    rightval=arr[j+1];
                }

                int before=0;
                int after=0;
                if(i!=k){
                    before=dp[i][k-1];
                }
                if(j!=k){
                    after=dp[k+1][j];
                }
                dp[i][j]=max(dp[i][j],before+after+(leftval*rightval*arr[k]));
            }
        }
    }
    return dp[0][n-1];
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<solution()<<endl;

    return 0;
}
