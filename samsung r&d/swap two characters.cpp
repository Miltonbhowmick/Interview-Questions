#include<iostream>
using namespace std;

void swp(char *a,char *b){
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}
int main()
{
    char x='S';
    char y='8';
    cout<<x<<" "<<y<<endl;
    swp(&x,&y);
    cout<<x<<" "<<y<<endl;
    return 0;
}
