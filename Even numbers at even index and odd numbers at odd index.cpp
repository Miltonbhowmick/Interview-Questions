#include<iostream>
#define MAX 100000
using namespace std;
int n,arr[MAX];

void swp(int *a,int *b){
    if(*a==*b) return;
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}
void solution(){
    int e=0;
    for(int i=0;i<n;i++){
        if((arr[i]%2)==0){
            swp(&arr[i],&arr[e]);
            e+=2;
        }
    }
    int o=1;
    for(int i=0;i<n;i++){
        if((arr[i]%2)==1){
            swp(&arr[i],&arr[o]);
            o+=2;
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    solution();

    return 0;
}
