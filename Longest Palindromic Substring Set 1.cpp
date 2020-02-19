#include<iostream>
using namespace std;
string s,ans;
int mx;
int main()
{
    mx=0;
    cin>>s;
    int l=s.length();
    for(int i=0;i<l;i++){
        for(int j=i;j<l;j++){
            string r="";
            for(int k=i;k<=j;k++){
                r+=s[k];
            }
            bool ck=true;

            int l=r.length()-1;
            int f=0;
            while(f<l){
                if(r[f]!=r[l]){
                    ck=false;
                    break;
                }
                f++,l--;
            }

            if(ck){
                if((l+1)>mx){
                    mx=l+1;
                    ans=r;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
