/*
 * @Author: JorD
 * @LastEditTime: 2022-12-30 19:25:46
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
const int N = 4e5 + 10;
int col[N], id[N], idx, siz[N], mp[N];
ll tr[N << 2], lazy[N << 2];
vector<int> son[N];
void dfs(int now, int fa){
    id[now] = ++ idx;
    mp[idx] = now;
    siz[now] = 1;
    for(auto x:son[now]){
        if(x == fa) continue;
        dfs(x, now);
        siz[now] += siz[x];
    }
}
void pushup(int p){
    tr[p] = tr[p << 1] | tr[p << 1|1];
}
void pushdown(int l, int r, int p){
    int mid = l + r >> 1;
    if(lazy[p]){
        tr[p << 1] = 1ll << lazy[p];
        tr[p << 1|1] = 1ll << lazy[p];  
        lazy[p << 1] = lazy[p << 1|1] = lazy[p];
    }
    lazy[p] = 0;
}
void build(int l, int r, int p){
    if(l == r){
        tr[p] = 1ll << col[mp[l]];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    pushup(p);
}
void update(int cl, int cr, int l, int r, int p, int k){
    if(cl <= l && r <= cr){
        tr[p] = 1ll << k;
        lazy[p] = k;
        return;
    }
    pushdown(l, r, p);
    int mid = l + r >> 1;
    if(cl <= mid) update(cl, cr, l, mid, p << 1, k);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1, k);
    pushup(p);
}
ll query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    pushdown(l, r, p);
    int mid = l + r >> 1;
    ll res = 0;
    if(cl <= mid) res |= query(cl, cr, l, mid, p << 1);
    if(cr > mid) res |= query(cl, cr, mid + 1, r, p << 1|1);
    return res;
}
void Solve(){
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) cin >> col[i];
    rep(i, 2, n){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    dfs(1, 0);
    build(1, n, 1);
    while(m --){
        int op, x, y;
        cin >> op;
        if(op == 1){
            cin >> x >> y;
            update(id[x], id[x] + siz[x] - 1, 1, n, 1, y);
        }else{
            cin >> x;
            ll res = query(id[x], id[x] + siz[x] - 1, 1, n, 1);
            int ans = 0;
            while(res){
                if(res & 1) ans ++;
                res >>= 1;
            }
            cout << ans << endl;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}