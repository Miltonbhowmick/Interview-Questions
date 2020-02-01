#include<iostream>
#define MAX 10000
using namespace std;

int sumKtree(string tree, int k){
    int l=tree.length(),level=0,arr[MAX];
    for(int i=0;i<l;i++){
        if(tree[i]=='('){
            level++;
        }
        else if(tree[i]>='0'&&tree[i]<='9'){
            cout<<tree[i]<<"--"<<level<<endl;
            arr[tree[i]-'0']=level-1;
        }
        else
            level--;

        cout<<i<<"++"<<level<<endl;
    }
    int sum=0;
    for(int i=0;i<l;i++){
        if((arr[tree[i]-'0'])==k)
            sum+=tree[i]-'0',cout<<tree[i]<<" ";
    }
    return sum;
}
int main()
{
    string tree;
    int k;
    cin>>tree;
    cin>>k;
    cout<<sumKtree(tree,k)<<endl;

    return 0;
}
