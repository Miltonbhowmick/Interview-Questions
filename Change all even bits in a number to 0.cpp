#include<iostream>
using namespace std;
int t,n;
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        /// 0xAAAAAAAA
        n=n&0xAAAAAAAA;     /// 30=00011110&10101010
        cout<<n<<endl;
    }
    return 0;
}
