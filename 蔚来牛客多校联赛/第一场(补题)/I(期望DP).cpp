/*
 * @Author: JorD
 * @LastEditTime: 2022-07-26 19:32:07
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int mod =1e9+7;
ll f[10][150]; 
ll qsm(ll a,ll b=mod-2){
    ll res=1;
    for(;b;b>>=1,a=a*a%mod)
        if(b&1) res=res*a%mod;
    return res;
}
int idx;
void Solve(){
    string s;
    cin>>s;
    idx++;  
    map<int,int> q;
    rep(i,0,s.size()-1){
        int now=(s[i]-'0')*100+s[i+1]-'a';
        i++;
        q[now]++;
    }
    int js=0;
    for(auto x:q) js+=x.second==2;
    cout<<"Case #"<<idx<<": "<<f[js][123]<<'\n';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    rep(j,1,123){
        rep(i,0,6){
            if(j<(13-2*i)*3) continue;
            ll p=(13-2*i)*3;
            f[i][j]=(1+f[i+1][j-1]*p%mod*qsm(j)%mod+f[i][j-1]*(j-p)%mod*qsm(j)%mod)%mod;
                //能够到达的状态之后所需要的期望*到达这个状态的概率
        }
    }
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}