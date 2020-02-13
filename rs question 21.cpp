#include<iostream>
#define MAX 10000
using namespace std;
int n,arr[MAX];
/// merge
void MergeNow(int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++)
        L[i]=arr[l+i];
    for(int i=0;i<n2;i++)
        R[i]=arr[m+i+1];

    int i=0;
    int j=0;
    int k=l;
    while(i<n1&&j<n2){
        if(L[i]<R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}
void MergeSort(int l,int r){
    if(l<r){
        int m=(l+r)/2;
        MergeSort(l,m);
        MergeSort(m+1,r);
        MergeNow(l,m,r);
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    MergeSort(0,n-1);

    int k;
    cin>>k;
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=(arr[i])*(n-i);
        for(int j=i+1;j<n;j++){
            arr[j]=arr[j]-arr[i];
        }
    }
    cout<<sum<<endl;
    return 0;
}
