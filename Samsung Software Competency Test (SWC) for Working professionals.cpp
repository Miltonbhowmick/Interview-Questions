#include<iostream>
#define MAX 10000
using namespace std;
int n,idg_sum[MAX][2],trgt,target[MAX],store_idg[MAX],ans[MAX];

void MergeNow(int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1][2],R[n2][2];
    for(int i=0;i<n1;i++){
        L[i][0]=idg_sum[l+i][0];
        L[i][1]=idg_sum[l+i][1];
    }
    for(int i=0;i<n2;i++){
        R[i][0]=idg_sum[m+i+1][0];
        R[i][1]=idg_sum[m+i+1][1];
    }

    int i=0;
    int j=0;
    int k=l;
    while(i<n1&&j<n2){
        if(L[i][0]<R[j][0]){
            idg_sum[k][0]=L[i][0];
            idg_sum[k][1]=L[i][1];
            i++;
        }
        else{
            idg_sum[k][0]=R[j][0];
            idg_sum[k][1]=R[j][1];
            j++;
        }
        k++;
    }
    while(i<n1){
        idg_sum[k][0]=L[i][0];
        idg_sum[k][1]=L[i][1];
        i++;
        k++;
    }
    while(j<n2){
        idg_sum[k][0]=R[j][0];
        idg_sum[k][1]=R[j][1];
        j++;
        k++;
    }
}
void MergeSort(int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        MergeSort(l,mid);
        MergeSort(mid+1,r);
        MergeNow(l,mid,r);
    }
}
int pow(int x,int y){
    int val=1;
    for(int i=0;i<y;i++)
        val*=2;
    return val;
}
int solution(int t_sum){
    int cnt,sum,mn=12345;
    int powerset=pow(2,n);
    for(int counter=0;counter<powerset;counter++){
        sum=0;
        cnt=0;
        for(int j=n-1;j>=0;j--){
            if(counter&(1<<j)){
                sum+=idg_sum[j][0];
                store_idg[cnt++]=idg_sum[j][1]+1;
//                cout<<idg_sum[j][0]<<" "<<idg_sum[j][1]<<endl;
            }
        }
        if(sum==t_sum){
//            cout<<store_idg[cnt]<<endl;
            if(cnt<mn){
                for(int k=0;k<cnt;k++){
                    ans[k]=store_idg[k];
                }
                mn=cnt;
            }
        }
    }
    if(mn<12345) return mn;
    else return -1;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n>>trgt;
        for(int i=0;i<n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            idg_sum[i][0]=a+b+c;
            idg_sum[i][1]=i;
        }
        MergeSort(0,n-1);

    for(int i=0;i<n;i++)
        cout<<idg_sum[i][0]<<" "<<idg_sum[i][1]<<endl;

        for(int i=0;i<trgt;i++){
            int a,b,c;
            cin>>a>>b>>c;
            target[i]=a+b+c;

            int run=solution(target[i]);

            if(run>0){
                for(int p=0;p<run;p++){
                    cout<<ans[p]<<" ";
                }
                cout<<endl;
            }
            else
                cout<<-1<<endl;
        }
        /// all possible sum in idg_sum

    }
    return 0;
}
