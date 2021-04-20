/*
4 8
0 1
0 3
1 0
1 2
2 1
2 3
3 0
3 2
*/

#include<iostream>
#define MAX 1000
using namespace std;
int grid[MAX][MAX],v,e;
int color[MAX];
///queue
class Queue{
public:
    int arr[MAX],fnt,rear,num_ele;
    Queue(){
        fnt=-1;
        rear=-1;
        num_ele=0;
    }
    void push(int data){
        if(fnt==-1) fnt=0;
        arr[++rear]=data;
        num_ele++;
    }
    void pop(){
        if(fnt>rear || fnt==-1) return;
        fnt++;
        num_ele--;
    }
    bool isEmpty(){
        if(fnt==-1||fnt>rear) return true;
        else return false;
    }
    int Front(){
        return arr[fnt];
    }
};
///bipartite
bool isBipartite(int u){
    Queue q;
    q.push(u);
    color[u]=1;
    while(!q.isEmpty()){
        int u=q.Front();
        q.pop();

        if(grid[u][u]==1)  /// IMPORTANT! self-loop
            return true;

        for(int i=0;i<v;i++){
            if(grid[u][i]){
                if(color[i]==-1){
                    color[i]=1-color[u];
                    q.push(i);
                }
                else if(color[u]==color[i])
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        grid[x][y]=1;
    }
    for(int i=0;i<v;i++)
        color[i]=-1;
    cout<<isBipartite(0)<<endl;
    return 0;
}
