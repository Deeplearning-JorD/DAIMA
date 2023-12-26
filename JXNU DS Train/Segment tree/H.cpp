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
const int N = 2e5 + 10, mod = 1e9 + 7, M = 1e6 + 5;
vector<int> prime;
vector<int> fac[M];
int n, q, a[N], mul[M], del[M], res[N], last[M];
ll qsm(ll x, ll p){
    ll res = 1;
    while(p){
        if(p & 1) res = res * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return res;
}
void init(){
    for(int i = 2;i < M;i ++){
        if(siz(fac[i])) continue;
        prime.push_back(i);
        for(int j = i;j < M;j += i)
            fac[j].push_back(i);
    }   
    for(auto x:prime){
        mul[x] = 1ll * (x - 1) * qsm(x, mod - 2) % mod;
        del[x] = qsm(mul[x], mod - 2);
    }
}
ll tr[N << 2];
void build(int l, int r, int p){
    if(l == r){
        tr[p] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    tr[p] = tr[p << 1] * tr[p << 1|1] % mod;
}
void update(int pos, int l, int r, int p, int k){
    if(l == r){
        tr[p] *= k;
        tr[p] %= mod;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) update(pos, l, mid, p << 1, k);
    else update(pos, mid + 1, r, p << 1|1, k);
    tr[p] = tr[p << 1] * tr[p << 1|1] % mod;
}
ll query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    int mid = l + r >> 1;
    if(cr <= mid) return query(cl, cr, l, mid, p << 1);
    if(cl > mid) return query(cl, cr, mid + 1, r, p << 1|1);
    return query(cl, cr, l, mid, p << 1) * query(cl, cr, mid + 1, r, p << 1|1) % mod;
}
void Solve(){
    init();
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    build(1, n, 1);
    int m; cin >> m;
    vector<vector<pair<int,int>>> q(n + 1);
    for(int i = 1;i <= m;i ++){
        int l, r; cin >> l >> r;
        q[l].push_back({r, i});
    }
    for(int i = n; i >= 1;i --){
        for(auto x:fac[a[i]]){
            if(last[x]) update(last[x], 1, n, 1, del[x]);
            update(i, 1, n, 1, mul[x]);
            last[x] = i;
        }
        for(auto [x, id]:q[i]){
            res[id] = query(i, x, 1, n, 1);
        }
    }
    rep(i, 1, m) cout << res[i] << endl; 
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}