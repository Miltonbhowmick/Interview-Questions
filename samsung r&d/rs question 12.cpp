#include<iostream>
#define MAX 10000
using namespace std;
int v,e,grid[MAX][MAX],dis[MAX];
int color[MAX];
/// Queue
class Queue{
public:
    int fnt,rear,num_ele;
    int arr[MAX];
    Queue(){
        fnt=rear=-1;
        num_ele=0;
    }
    void push(int data){
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
    int Front(){
        return arr[fnt];
    }
};

bool isBipartite(int u){
    color[u]=1;

    Queue q;
    q.push(u);
    while(!q.isEmpty()){
        int u=q.Front();
        q.pop();
        if(grid[u][u]==1) return false;

        for(int i=0;i<v;i++){
            if(grid[u][i]){
                if(color[i]==-1){
                    color[i]=1-color[u];
                    q.push(i);
                }
                else if(color[i]==color[u])
                    return false;
            }
        }
    }
    return true;
}
void reset(){
    for(int i=0;i<v;i++){
        color[i]=-1;
        dis[i]=0;
    }
}
int main()
{
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        grid[x][y]=1;
    }
    reset();
    /// for disconnected
    bool ck=true;
    for(int i=0;i<v;i++){
        if(color[i]==-1){
            if(isBipartite(i)==false){
                ck=false;
                break;
            }
        }
    }
    if(ck==true){
        for(int i=0;i<v;i++){
            cout<<color[i]<<"--"<<i<<endl;
        }
    }
    else{
        cout<<"No bipartite"<<endl;
    }
    return 0;
}
