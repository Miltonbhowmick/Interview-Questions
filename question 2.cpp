#include<iostream>
#include<cstdlib>
#define MAX 10000
using namespace std;
int n,m,mat[MAX][MAX],keyvalue,no_zeros,k;

int pow(int x,int y){
    int val=1;
    for(int i=0;i<y;i++)
        val*=2;
    return val;
}
void MAX_ROW(){
    int sz=1;
    for(int i=1;i<=20;i++)
        sz*=2;

    int *has = (int *)calloc(sz,sizeof(int));
    for(int i=0;i<n;i++){
        int keyvalue = 0;
        int no_zeros = 0;
        for(int j=0;j<m;j++){
            keyvalue+=(mat[i][j]*pow(2,j));
            if(mat[i][j]==0)
                no_zeros+=1;
        }
        if((k-no_zeros)%2==0&&(k-no_zeros)>=0) ///IMPORTANT!
            has[keyvalue]+=1;
    }
    int keyWithMaxVal=0, MaxVal=0;
    for(int i=0;i<sz;i++){
        if(has[i]>MaxVal){
            MaxVal=has[i];
            keyWithMaxVal=i;
        }
    }
    cout<<MaxVal<<endl;
}
int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    MAX_ROW();
    return 0;
}
