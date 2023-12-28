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
struct edge{
    ll l, r, w;
};
struct node{
    ll l, r, p, v;
};
ll us[110];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<edge> a(n + 1);
    int mx = 0;
    for(int i = 1;i <= n;i ++) cin >> a[i].l >> a[i].r >> a[i].w;
    vector<node> b(m);
    int res = 0;
    for(int i = 0;i < m;i ++) cin >> b[i].l >> b[i].r >> b[i].p >> b[i].v;
    for(int i = 1;i <= n;i ++) res += a[i].w;
    // for(int i = 0;i < m;i ++) mx = max(mx, b[i].r);
    // for(int i = 1;i <= n;i ++) mx = max(mx, a[i].r);
    // cout << mx << endl;
    
    for(int i = 1;i <= n;i ++){
        for(int j = a[i].l;j <= a[i].r;j ++){
            us[j] = max(us[j], a[i].w);
        }
    }
    for(int bit = 1;bit < (1 << m);bit ++){
        vector<ll> c(100 + 1), d(101);
        int need = 0;
        for(int i = 0;i < m;i ++){
            if(bit >> i & 1){
                need += b[i].v;
                c[b[i].l] += b[i].p;
                c[b[i].r + 1] -= b[i].p;
            }
        }
        bool can = true;
        for(int i = 1;i <= 100;i ++){
            d[i] = d[i - 1] + c[i];
            if(d[i] < us[i]) can = false;
        }
        if(can) res = min(res, need);
    }
    cout << res << endl;
    return 0;
}