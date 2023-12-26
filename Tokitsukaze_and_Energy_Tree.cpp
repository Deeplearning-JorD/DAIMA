/*
 * @Author: JorD
 * @LastEditTime: 2023-01-18 13:33:32
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
const int N = 2e5 + 10, inf = 1e5;
struct Segtree{
    int l, r;
    ll val;
}tr[N << 4];
int c[N], mp[N], id[N], cnt;
vector<int> son[N];
int depth[N], siz[N], mx;
int rt;
void dfs(int now, int fa){
    depth[now] = depth[fa] + 1;
    mx = max(depth[now], mx);
    siz[now] = 1;
    id[now] = ++ cnt;
    mp[cnt] = now;
    for(auto x:son[now])if(x != fa){
        dfs(x, now);
        siz[now] += siz[x];
    }
}
void pushup(int p){
    tr[p].val = tr[tr[p].l].val + tr[tr[p].r].val;
}
int root[N], idx;
void modify(int pos, int l, int r, int &p, int k){
    if(!p) p = ++ idx; 
    if(l == r){
        tr[p].val = k;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, tr[p].l, k);
    else modify(pos, mid + 1, r, tr[p].r, k);
    pushup(p);
}
int query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p].val;
    }
    int mid = l + r >> 1;
    int res = 0;
    if(cl <= mid) res += query(cl, cr, l, mid, tr[p].l);
    if(cr > mid) res += query(cl, cr, mid + 1, r, tr[p].r);
    return res;
}
vector<int> ceng[N];
void Solve(){
    int n;
    cin >> n;
    rep(i, 2, n){
        int fa; cin >> fa;
        son[fa].push_back(i);
    }
    rep(i, 1, n) cin >> c[i];
    dfs(1, 0);
    ll res = 0, j = 1;
    sort(depth + 1, depth + 1 + n);;
    sort(c + 1, c + 1 + n, [](int x, int y){return x > y;});
    per(i, n, 1){
        res += 1ll * depth[i] * c[j ++];
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