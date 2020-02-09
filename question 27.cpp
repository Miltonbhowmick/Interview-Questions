#include<iostream>
#include<climits>
#define MAX 10000
using namespace std;
int n,arr[MAX];

void Kadane(){
    int msf=INT_MIN,med=0;
    for(int i=0;i<n;i++){
        med = med+arr[i];
        if(msf<med){
            msf=med;
        }
        if(med<0)
            med=0;
    }
    cout<<msf<<endl;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Kadane();
    return 0;
}
