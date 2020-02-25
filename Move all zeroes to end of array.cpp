#include <iostream>
#define MAX 100000
using namespace std;
void swap(int *a,int *b){
    if(*a==*b) return;
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}
int t,n,arr[MAX],ans[MAX];
int main() {
    cin>>t;
    while(t--){
        cin>>n;
        int cnt=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]>0)
                cnt++;
            ans[i]=0;
        }
        int j=0;
        for(int i=0;i<n;i++){
            if(arr[i]>0&&j<cnt)
                ans[j++]=arr[i];
        }
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
	return 0;
}
