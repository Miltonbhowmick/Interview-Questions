#include<iostream>
#include<cstdio>
using namespace std;

//void blust(int mat[][5],int rows){
//    for(int i=0;i<5;i++){
//        for(int j=0;j<5;j++){
//            if(mat[i][j]==2) mat[i][j]=0;
//        }
//    }
//}

int max_coin(int mat[][5], int rows,int bomb,int pos,int cnt){
    if(rows<0) return cnt;
    else if(mat[rows][pos]==2){
        if(bomb==1){
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(mat[i][j]==2) mat[i][j]=0;
                }
            } // blust
            bomb=0;
            max_coin(mat,rows,bomb,pos,cnt);
        }
        else return cnt;
    }
    else if(mat[rows][pos]==1){
        cnt++;
        max_coin(mat,rows-1,bomb,pos,cnt);
    }
    else if(mat[rows][pos-1]==1){
        cnt++;
        max_coin(mat,rows-1,bomb,pos-1,cnt);
    }
    else if(mat[rows][pos+1]==1){
        cnt++;
        max_coin(mat,rows-1,bomb,pos+1,cnt);
    }
    else max_coin(mat,rows-1,bomb,pos,cnt);
}
int main()
{
    int rows,mat[10000][5];
    cin>>rows;
    for(int i=0;i<rows;i++){
        for(int j=0;j<5;j++)
            cin>>mat[i][j];
    }
    cout<<max_coin(mat,rows-2,1,2,0)<<endl;

    return 0;
}
