#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
const int mod = 1e9 + 9;
ll fpow(ll a,ll k,ll p){
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
void Solve(){
    ll m, k; cin >> m >> k;
    ll res = 0, last = 0;
    for(int i = 1;i <= k;i ++){
        ll inv = (i - 1) * (m - 1) + 1;
        inv = fpow(inv, mod - 2, mod);
        res += last * inv % mod + 1 % mod;
        res %= mod;
        last = (1 + (m - 1) * inv % mod) % mod * last % mod + m;
        last %= mod;
    }
    cout << m * res % mod << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}