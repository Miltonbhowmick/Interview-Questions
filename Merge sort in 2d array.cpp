#include<iostream>
#define MAX 10000
using namespace std;
int n,arr[MAX][2];

void MergeNow(int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1][2],R[n2][2];
    for(int i=0;i<n1;i++){
        L[i][0]=arr[l+i][0];
        L[i][1]=arr[l+i][1];
    }
    for(int i=0;i<n2;i++){
        R[i][0]=arr[m+i+1][0];
        R[i][1]=arr[m+i+1][1];
    }

    int i=0;
    int j=0;
    int k=l;
    while(i<n1&&j<n2){
        if(L[i][0]<R[j][0]){
            arr[k][0]=L[i][0];
            arr[k][1]=L[i][1];
            i++;
        }
        else if(L[i][0]==R[j][0]){
            if(L[i][1]>R[j][1]){
                arr[k][0]=L[i][0];
                arr[k][1]=L[i][1];
                i++;
            }
            else{
                arr[k][0]=R[j][0];
                arr[k][1]=R[j][1];
                j++;
            }
        }
        else{
            arr[k][0]=R[j][0];
            arr[k][1]=R[j][1];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k][0]=L[i][0];
        arr[k][1]=L[i][1];
        i++;
        k++;
    }
    while(j<n2){
        arr[k][0]=R[j][0];
        arr[k][1]=R[j][1];
        j++;
        k++;
    }

}
void MergeSort(int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        MergeSort(l,mid);
        MergeSort(mid+1,r);
        MergeNow(l,mid,r);
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i][0]>>arr[i][1];
    MergeSort(0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
    return 0;
}
