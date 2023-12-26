/*
 * @Author: JorD
 * @LastEditTime: 2022-12-20 03:16:08
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
const int N = 2e5 + 10;
vector<int> son[N];
int siz[N];
int a[N], st[N];
int n, m;
int id[N], idx, mid[N];
void dfs(int now, int fa){
    siz[now] = 1;
    st[now] = st[fa] ^ 1;
    id[now] = ++ idx;
    mid[idx] = now;
    for(auto x:son[now]){
        if(x == fa) continue;
        dfs(x, now);
        siz[now] += siz[x];
    }
}
int tr[2][N << 2], lazy[2][N << 2];
void pushup(int p, int o){
    tr[o][p] = tr[o][p << 1] + tr[o][p << 1|1];
}
void pushdown(int p, int l, int r, int o){
    int mid = l + r >> 1;
    auto &tree = tr[o];
    auto &mark = lazy[o];
    tree[p << 1] += (mid - l + 1) * mark[p];
    tree[p << 1|1] += (r - mid) * mark[p];
    mark[p << 1] += mark[p];
    mark[p << 1|1] += mark[p];
    mark[p] = 0;
}
void update(int cl, int cr, int l, int r, int p, int k, int o){
    if(cl <= l && r <= cr){
        tr[o][p] += (r - l + 1) * k;
        lazy[o][p] += k;
        return;
    }
    int mid = l + r >> 1;
    pushdown(p, l, r, o);
    if(cl <= mid) update(cl, cr, l, mid, p << 1, k, o);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1, k, o);
    pushup(p, o);
}
ll query(int pos, int l, int r, int p, int o){
    if(l == r){
        return a[mid[pos]] + tr[o][p] - tr[o ^ 1][p];
    }
    int mid = l + r >> 1;
    pushdown(p, l, r, o);
    pushdown(p, l, r, o ^ 1);
    ll res = 0;
    if(pos <= mid) res += query(pos, l, mid, p << 1, o);
    if(pos > mid) res += query(pos, mid + 1, r, p << 1|1, o);
    return res;
}
void add(int x, int k){
    update(id[x], id[x] + siz[x] - 1, 1, n, 1, k, st[x]);
}
void Solve(){
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    rep(i, 2, n){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    dfs(1, 0);
    while(m --){
        int op;
        cin >> op;
        if(op == 1){
            int x, val;
            cin >> x >> val;
            add(x, val);
        }else{
            int x;
            cin >> x;
            cout << query(id[x], 1, n, 1, st[x]) << endl;
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