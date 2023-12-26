/*
 * @Author: JorD
 * @LastEditTime: 2023-07-19 17:38:05
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
const int mod = 998244353;
ll fpow(ll a,ll k,ll p){
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
void Solve(){
    int n, m;
    cin >> n >> m;
    int i = 0;
    ll res = 1;
    ll now = n;
    while(now <= n + m){
        ll l = 1ll << i, r = 1ll << (i + 1);
        l --, r --;
        i ++;
        if(l <= now && now < r){
            ll j = min(r - now, n + m - now);
            ll L = fpow(l, j, mod);
            ll R = fpow(l + 1, j, mod);
            R = fpow(R, mod - 2, mod);
            res *= L;
            res %= mod;
            res *= R;
            res %= mod;
            now = r;
        }
    }
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