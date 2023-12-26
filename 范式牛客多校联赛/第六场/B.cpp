/*
 * @Author: JorD
 * @LastEditTime: 2023-08-04 14:11:17
 * how to Get
 */
#pragma GCC optimize(2)
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
const int mod = 998244353;
const int N = 1e6 + 10;
ll fact[N], infact[N], inv[N];
ll fpow(ll a,ll k,const ll p){
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
ll C(ll b, ll a){
    return fact[a] * infact[b] % mod * infact[a - b] % mod;
}
int a[N], b[N];
void Solve(){
    
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    fact[0] = infact[0] = 1;
    inv[1] = 1;
    for (int i = 1; i < N; i ++ ){
        fact[i] = fact[i - 1] * i % mod;
        if(i > 1)  inv[i] = (long long)(mod - mod / i) * inv[mod % i] % mod;
        infact[i] = infact[i - 1] * inv[i] % mod;
    }
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}