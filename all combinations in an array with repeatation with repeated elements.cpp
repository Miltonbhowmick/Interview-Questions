#include<iostream>
#define MAX 10000
using namespace std;
int n,arr[MAX],k,data[MAX];

void print(int idx){
    for(int i=0;i<idx;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}
void combinations(int idx,int i){

    if(idx==k){
        print(idx);
        return ;
    }

    for(int j=i;j<n;j++){
        data[idx]=arr[j];
        combinations(idx+1,j);

        while(j<n-1&&arr[j]==arr[j+1])
            j++;
    }
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i];
//    sort(arr,arr+n);
    int idx=0;
    combinations(idx,0);
    return 0;
}

