/*
 * @Author: JorD
 * @LastEditTime: 2023-01-08 18:55:18
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int mod = 1e9 + 7;
ll qmi(ll a,ll k,int p){
    ll res=1;
    while(k){
        if(k&1) res=res*a%p;
        k>>=1;
        a=a*a%p;
    }
    return res;
}
ll C(ll a,ll b,ll p){
    if(a<b) return 0;
    ll res=1;
    for(ll i=1,j=a;i<=b;i++,j--){
        res=res*j%p;
        res=res*qmi(i,p-2,p)%p;
    }
    return res;
}
ll lucas(ll a,ll b,ll p){
    if(a<p&&b<p) return C(a,b,p);
    return C(a%p,b%p,p)*lucas(a/p,b/p,p)%p;
}
void Solve(){
    int n; cin >> n;
    string s; cin >> s;
    int m = siz(s);
    ll res = 1;
    rep(i, 1, n){
        res *= 26;
        res %= mod;
    }
    res = res * lucas(n + m, m, mod) % mod;
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}