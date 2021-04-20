#include<iostream>
#define MAX 10000
using namespace std;
int t,q;
class TwoStacks{
public:
    int *arr;
    int sz;
    int top1,top2;
    TwoStacks(int n){
        sz=n;
        arr = new int[n];
        top1=-1;
        top2=sz;
    }
    void push1(int x){
        if(top1<top2-1){
            top1++;
            arr[top1]=x;
        }
        else{
            return;
        }
    }
    int push2(int x){
        if(top1<top2-1){
            top2--;
            arr[top2]=x;
        }
        else{
            return -1;
        }
    }
    int pop1()
    {
        if(top1>=0){
            int x=arr[top1];
            top1--;
            return x;
        }
        else{
            return -1;
        }
    }
    int pop2(){
        if(top2>=sz){
            return -1;
        }
        else{
            return arr[top2++];
        }
    }
};
int main()
{
    cin>>t;
    while(t--){
        TwoStacks sq(100);
        cin>>q;
        for(int i=0;i<q;i++){
            int s,qt,a;
            cin>>s>>qt;
            if(qt==1){
                cin>>a;
                if(s==1){
                    sq.push1(a);
                }
                else if (s==2){
                    sq.push2(a);
                }
            }
            else if (qt==2){
                if(s==1){
                    cout<<sq.pop1()<<" ";
                }
                else if(s==2){
                    cout<<sq.pop2()<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
