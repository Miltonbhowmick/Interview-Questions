#include<iostream>
#define MAX 100000
using namespace std;

int KadaneAlgo(int arr[MAX], int n, int med, int msf){
    for(int i=0;i<n;i++){
        med = med + arr[i];
        if(med < arr[i])
            med = arr[i];
        if(msf<med)
            msf=med;
    }
    return msf;
}
int main()
{
    int arr[MAX],n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int med=0, msf=-1; /// med = max ending , msf= max so far
    cout<<KadaneAlgo(arr,n,med,msf)<<endl;
    return 0;
}
