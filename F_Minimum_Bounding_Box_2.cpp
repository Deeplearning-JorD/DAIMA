/*
 * @Author: JorD
 * @LastEditTime: 2023-04-27 20:43:55
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
const int mod = 998244353, N = 1e6 + 10;
ll fpow(ll a,ll k,ll p){
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
ll add(ll x, ll y){
    return ((x + y) % mod + mod) % mod;
}
ll m(ll x, ll y){
    return (x * y) % mod;
}
// 反向考虑现在是n*m的矩形选了k个点且四个边上都有点的方案数
// 考虑容斥原理 分别考虑不沾着几条边
int in[N], inv[N];
void init(){
    in[0] = inv[0] = 1;
    for(int i = 1;i <= 1e6;i ++){
        in[i] = m(in[i - 1], i);
        inv[i] = m(inv[i - 1], fpow(i, mod - 2, mod));
    }
}
ll C(int a, int b){
    if(b > a) return 0;
    return m(in[a], m(inv[b], inv[a - b]));
}
ll calc(ll x, ll y, ll k){
    if(x * y < k) return 0;
    ll a = C(x * y, k);
    ll b = m(2, add(C((x - 1) * y, k),C(x * (y - 1), k)));
    ll c = add(C((x - 2) * y, k), add(C(x * (y - 2), k), m(4, C((x - 1) * (y - 1), k))));
    ll d = m(2, add(C((x - 1) * (y - 2), k), C((x - 2) * (y - 1), k)));
    ll e = C((x - 2) * (y - 2), k);
    a = add(a, -b);
    a = add(a, c);
    a = add(a, -d);
    a = add(a, e);
    return a;    
}
void Solve(){
    int n, M, k;
    init();
    cin >> n >> M >> k;
    if(k == 1){
        cout << 1 << endl;
        return;
    }
    int R = C(n * M, k);
    int res = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= M;j ++){
            res = add(res, m(m(m((n - i + 1), (M - j + 1)), m(i, j)), calc(i, j, k)));
        }
    }
    res = m(res, fpow(R, mod - 2, mod));
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}