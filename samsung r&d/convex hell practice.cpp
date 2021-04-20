/*
6
1 1
2 2
1 0
0 10
10 10
3 3
*/
#include<iostream>
#define MAX 10000
#define LL long long
using namespace std;
int np,nc;
/// point
struct Point{
    LL x,y;
};
Point P[MAX],C[MAX],p0;
void swp(Point *x,Point *y){
    Point temp=*x;
    *x=*y;
    *y=temp;
}
/// stack
class Stack{
public:
    int top;
    Point arr[MAX];
    Stack(){
        top=-1;
    }
    void push(Point data){
        arr[++top]=data;
    }
    void pop(){
        if(top<0) return;
        top--;
    }
    bool isEmpty(){
        return (top<0);
    }
    Point Top(){
        return arr[top];
    }
};
/// distance of two points .... Dhal
int distSq(Point p,Point q){
    return ((p.x-q.x)*(p.x-q.x))+((p.y-q.y)*(p.y-q.y));
}
/// orientation  (x3-x2)*(y2-y1)-(y3-y2)*(x2-x1)
int orientation(Point p,Point q,Point r){
    int val= ((r.x-q.x)*(q.y-p.y))-((r.y-q.y)*(q.x-p.x));
    if(val==0) return 0;
    else{
        if(val>0) return 1;
        else return 2;
    }
}
/// compare two points with first point
int compare(Point *p1,Point *p2){


    int o=orientation(p0,*p1,*p2);
    if(o==0){
        if(distSq(p0,*p2)>=distSq(p0,*p1))
            return -1;
        else
            return 1;
    }
    else{
        if(o==2){
            return -1;
        }
        else
            return 1;
    }
}
/// bubble sort
void bs(){
    for(int i=1;i<np-1;i++){
        for(int j=1;j<np-i;j++){
            if(compare(&P[j],&P[j+1])>0){
                swp(&P[j],&P[j+1]);
            }
        }
    }
}
Point NextToTop(Stack &s){
    Point p=s.Top();
    s.pop();
    Point res=s.Top();
    s.push(p);
    return res;
}
void ConvexHull(int np,int &nc){
    int i,j;
    int ymin=P[0].y;
    int posMin=0;
    for(int i=1;i<np;i++){
        int y=P[i].y;
        if((y<ymin)||(ymin==y&&P[i].x<P[posMin].x)){
            ymin=P[i].y;
            posMin=i;
        }
    }
    swp(&P[0],&P[posMin]);
    p0=P[0];
    bs();

    int m=1;
    for(int i=1;i<np;i++){
        while(i<np-1 && orientation(p0,P[i],P[i+1])==0)
            i++;
        P[m]=P[i];
        m++;
    }
    if(m<3) return ;

    Stack s;
    s.push(P[0]);
    s.push(P[1]);
    s.push(P[2]);

    for(int i=3;i<m;i++){
        while(orientation(NextToTop(s),s.Top(),P[i])!=2)
            s.pop();
        s.push(P[i]);
    }
    while(!s.isEmpty()){
        Point p=s.Top();
        cout<<p.x<<" "<<p.y<<endl;
        s.pop();
    }
}
int main()
{
    cin>>np;
    for(int i=0;i<np;i++){
        cin>>P[i].x>>P[i].y;
    }
    ConvexHull(np,nc);
//    for(int i=0;i<np;i++)
//        cout<<P[i].x<<" "<<P[i].y<<endl;
    return 0;
}
