/*
 * @Author: JorD
 * @LastEditTime: 2023-04-12 23:03:54
 */
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
#define int long long 
const int mod = 1e9+7;
int qmi(int a,int b){
    int res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<4){
            cout<<0<<endl;
            continue;
        }
        int x=qmi(2,n-1);
        x=x*(n-3);
        x%=mod;
        x=x*qmi(3,mod-2)%mod;
        int y=n-4;
        int m = (n-1)%3;
        int x2=((qmi(2,n-1)-qmi(2,m))%mod+mod)%mod*qmi(9,mod-2)%mod;
        x=(x+x2)%mod;
        x=x*qmi(3,mod-2)%mod;
        cout<<x<<endl;
    }
    return 0;
}