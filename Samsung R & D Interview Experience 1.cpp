#include<iostream>
#define MAX 10000
using namespace std;
int n,arr[MAX],freq[MAX],mx;

void solution(){

    for(int i=0;i<n;i++){
        if(freq[arr[i]]>1){
            for(int j=arr[i]+1;j<=mx+1;j++){
                if(freq[j]==0){
                    freq[arr[i]]--;
                    arr[i]=j;
                    freq[j]++;
                    mx=max(mx,j);
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i],freq[arr[i]]++;
        mx=max(mx,arr[i]);
    }
    solution();
    return 0;
}
