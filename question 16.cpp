#include<iostream>
#define MAX 100005
using namespace std;

void mergeNow(int arr[],int l,int m,int r){
    /// For two temp array
    int n1=m-l+1;
    int n2=r-m;
    /// Create and push values in two temp array
    int L[n1],R[n2];
    for(int i=0;i<n1;i++)
        L[i]=arr[l+i];
    for(int j=0;j<n2;j++)
        R[j]=arr[m+1+j];
    /// Merge temp arrays and send back to arrays
    int i=0;
    int j=0;
    int k=l;
    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
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
void mergeSort(int arr[],int l,int r){

    if(l<r){
        int m = l+(r-l)/2;  /// IMPORTANT!!!!!!!
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        mergeNow(arr,l,m,r);
    }
}
void MinStone(int arr[MAX], int n, int k){
    int ans=n*arr[0];
    for(int i=1;i<k;i++){
        ans +=(n-i)*(arr[i]-arr[i-1]);
    }
    cout<<ans<<endl;
}
int main()
{
    int n,arr[MAX],k;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    mergeSort(arr,0,n-1);
    MinStone(arr,n,k);
    return 0;
}
