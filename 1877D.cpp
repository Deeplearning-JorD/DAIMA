/*
 * @Author: JorD
 * @LastEditTime: 2023-10-09 13:04:01
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
ll fpow(ll a,ll k,ll p){
    if(k < 0) return 1;
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
void Solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<int> mx(n + 1);
    for(int i = 1;i <= n;i ++){
        for(int j = 1;i * j <= n;j ++){
            mx[i] = max(mx[i], a[i * j]);
        }
    }
    map<int,int> st;
    rep(i, 1, n){
        st[mx[i]] ++;
    }
    int idx = 0;
    ll res = 0;
    for(auto [x, y] : st){
        res += 1ll * x * (fpow(2, y, mod) - 1) % mod * fpow(2, idx, mod) % mod;
        res %= mod;
        idx += y;
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Solve();
    return 0;
}