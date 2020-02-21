#include<iostream>
using namespace std;
string s;

void NextPalin(string s,int l){
    if(l<=3){
        cout<<"Not Possible"<<endl;
        return;
    }
    int mid=(l/2)-1;
    int i,j;
    /// small > large loop
    for(i=mid-1;i>=0;i--){
        if(s[i]<s[i+1])
            break;
    }
    if(i<0){
        cout<<"Not Possible"<<endl;
        return;
    }
    int smallest=i+1;
    for(int j=i+2;j<=mid;j++){
        if(s[j]>s[i]&&s[j]<s[smallest])
            smallest=j;
    }

    swap(s[smallest],s[i]);
    swap(s[l-i-1],s[l-smallest-1]);
    /// reverse the rest of both side
    int p=i+1,q=mid;
    while(p<q){
            swap(s[p],s[q]);
            p++;
            q--;
        }

    if((l%2)==0){
        int p=mid+1,q=l-i-2;
        while(p<q){
            swap(s[p],s[q]);
            p++;
            q--;
        }
    }
    else{
        int p=mid+2,q=l-i-2;
        while(p<q){
            swap(s[p],s[q]);
            p++;
            q--;
        }
    }
    cout<<s<<endl;
}
int main()
{
    cin>>s;
    int l=s.length();

    NextPalin(s,l);

    return 0;
}
