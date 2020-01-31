#include<iostream>
#define MAX 100000
using namespace std;
int arr[MAX];

void swp(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void FindSmallNumber(int n){
    int start=0,mx=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            swp(&arr[i],&arr[start++]);
        }
    }
    int j,i;
    for(i=0;i<=start;i++){
        for(j=0;j<=start;j++){
            if(i==arr[j])
                break;
        }
        if(j>start){
            break;
        }
    }
    if(i>start&&j>start)
        cout<<start+1<<endl;
    else if(i<=start&&j>start)
        cout<<i<<endl;
    else
        cout<<0<<endl;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    FindSmallNumber(n);

    return 0;
}

