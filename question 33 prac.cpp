#include<iostream>
using namespace std;
int t;
string s;

int main()
{
    cin>>t;
    while(t--){
        cin>>s;
        int cnt=0;
        int l = s.length();
        for(int i=0;i<l;i++){
            if(s[i]=='1'){
                int zero=0;
                int other=0;
                int j;
                for(j=i+1;j<l;j++){
                    if(s[j]=='0')
                        zero++;
                    else if(s[j]=='1'){
                        if(other==0&&zero>0) cnt++;
                        break;
                    }
                    else other++;
                }

            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
