#include<iostream>
#define MAX 10000
using namespace std;
int n,arr[MAX];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++)
                cout<<arr[k]<<" ";
            cout<<endl;
        }
    }

    return 0;
}
