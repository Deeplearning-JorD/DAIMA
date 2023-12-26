/*
 * @Author: JorD
 * @LastEditTime: 2023-05-19 17:07:54
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
const int N = 2e6 + 10;
ll fpow(ll a,ll k,ll p){
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
ll a[N], p[N];
char s[N];
ll inv = fpow(100, mod - 2, mod);
void Solve(){
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    rep(i, 1, n - 1){
        int x; cin >> x;
        p[i] = x;
    }
    ll dp = 1;
    ll ans = s[n] - '0';
    for(int i = n - 1;i >= 1;i --){
        dp = ((p[i] * inv % mod) + 10 * dp % mod * (100 - p[i]) % mod * inv % mod)%mod;
        ans += dp * (s[i] - '0') % mod;
        ans += mod;
        ans %= mod;
    }
    cout << ans << endl;
    return;
}
int main(){
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}