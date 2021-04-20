#include<iostream>
#include<cstdlib>
#define MAX 10000
using namespace std;
int n,t;
string s;

/// divide cell
struct Cell{
    int l;
    int r;
};
///Queue
class Queue{
public:
    int fnt,rear,num_ele;
    Cell arr[MAX];
    Queue(){
        fnt=rear=-1;
        num_ele=0;
    }
    void push(Cell data){
        if(fnt==-1) fnt=0;
        arr[++rear]=data;
    }
    void pop(){
        if(fnt==-1||fnt>rear) return;
        fnt++;
    }
    bool isEmpty(){
        if(fnt==-1||fnt>rear) return true;
        return false;
    }
    Cell Front(){
        return arr[fnt];
    }
};
void print(){
    for(int i=0;i<n;i++)
        cout<<s[i]<<" ";
    cout<<endl;
}
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++) s[i]='_';
        Queue q;

        Cell now;
        now.l=0; now.r=n-1;
        q.push(now);
        while(!q.isEmpty()){
            Cell now=q.Front();
            q.pop();

            int l=now.l, r=now.r;
            int m=(l+r)/2;
            s[m]='X';
            delete(&now); /// IMPORTANT!

            Cell left;
            left.l=l;
            left.r=m-1;
            if(left.r>=left.l){
                q.push(left);
            }

            Cell right;
            right.l=m+1;
            right.r=r;
            if(right.r>=right.l){
                q.push(right);
            }
            print();
        }
    }
    return 0;
}
