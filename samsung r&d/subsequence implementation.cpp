#include<iostream>
#define MAX 10000
using namespace std;
int n,arr[MAX];
string s;

int pow(int x,int y){
    int val=1;
    for(int i=0;i<y;i++)
        val*=2;
    return val;
}
void printPowerSet(){
    int powerset=pow(2,n);
    for(int counter=0;counter<powerset;counter++){
        for(int j=0;j<n;j++){
            if(counter&(1<<j))
                cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    printPowerSet();
    return 0;
}
