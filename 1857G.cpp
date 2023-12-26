/*
 * @Author: JorD
 * @LastEditTime: 2023-10-12 20:42:27
 * how to Get
 */
// S - 边权 + 1 的（sizx *sizy-1）次方
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
const int N = 2e5 + 10;
int f[N], cnt[N];
int find(int x){
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}
struct edge{
    int a, b, c;
};
void Solve(){
    int n, s;
    cin >> n >> s;
    rep(i, 1, n){
        f[i] = i;
        cnt[i] = 1;
    }
    vector<edge> e(n + 1);
    rep(i, 2, n){
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
    }
    sort(e.begin() + 2, e.end(), [](edge x, edge y){
        return x.c < y.c;
    });
    ll res = 1;
    //两部分的点连边，每一条边有k个值可以选
    //每两个点之间可以选择连或不连。每部分点中有一对点不能相连。问方案数
    rep(i, 2, n){
        auto [x, y, c] = e[i];
        x = find(x), y = find(y);
        res = (res * fpow(s - c + 1, 1ll * cnt[x] * cnt[y] - 1, mod)) % mod;
        f[x] = y;
        cnt[y] += cnt[x];
    }
    cout << res << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}