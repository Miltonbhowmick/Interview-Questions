#include<iostream>
#define MAX 100000
using namespace std;
int arr[MAX];

void swp(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
bool CheckNumber(int ck,int start){
    for(int j=0;j<start;j++){
        if(ck==arr[j]){ /// IMPORTANT! is ck taking extra space ???
            return true;
        }
    }
    return false;
}
int FindSmallNumber(int n){
    int start=0,mx=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            swp(&arr[i],&arr[start++]);
        }
    }
    for(int i=0;i<=start;i++){
        if(CheckNumber(i,start)==false){
            return i;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<FindSmallNumber(n)<<endl;

    return 0;
}
