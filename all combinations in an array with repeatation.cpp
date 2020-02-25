#include<iostream>
#define MAX 10000
using namespace std;
int n,arr[MAX],k,data[MAX];

void print(int idx){
    for(int i=0;i<idx;i++)
        cout<<data[i]<<" ";
    cout<<endl;
}
/// dfs
void combinations(int idx ,int i){
    if(idx==k){
        print(idx);
        return;
    }
    for(int j=i;j<n;j++){
        data[idx]=arr[j];
        combinations(idx+1,j);
    }
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int idx=0;
    combinations(idx,0);
    return 0;
}
