#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 10000
using namespace std;
const char hasWord[10][5]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
char output[8];
int n,arr[MAX];

void solution(int curr_digit){

    if(curr_digit==n){
        printf("%s \n",output);
        return;
    }

    for(int i=0;i<strlen(hasWord[arr[curr_digit]]);i++){
        output[curr_digit]=hasWord[arr[curr_digit]][i];
        solution(curr_digit+1);
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    solution(0);
    return 0;
}
