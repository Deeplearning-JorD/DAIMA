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
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
void Solve(){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    s = ' ' + s;
    ll res = 1;
    rep(i, 2, n)if(s[i] == '?')res = (res * (i - 1)) % mod;
    if(s[1] == '?') cout << 0 << endl;
    else cout << res << endl;
    while(m --){
        int x; cin >> x;
        string c; cin >> c;
        if(x != 1){
            if(s[x] == '?' && c[0] != '?') res = res * fpow(x - 1, mod - 2, mod) % mod;
            if(s[x] != '?' && c[0] == '?') res = res * (x - 1) % mod;
        }
        s[x] = c[0];
        if(s[1] == '?') cout << 0 << endl;
        else cout << res << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}