#include<iostream>
#define MAX 10000
using namespace std;
int n,arr[MAX];

void solution(){
    int total=(n+1)*((n+2)/2);
    for(int i=0;i<n;i++){
        total-=arr[i];
    }
    cout<<total<<endl;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    solution();
    return 0;
}
