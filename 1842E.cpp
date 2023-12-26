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
const int N = 2e5 + 10, inf = 2e9;
int dp[N];
// dp[i]表示0-i的上半个三角形中的最小代价
struct node{
    int a, b, c;
    bool operator <(const node &ji)const{
        return b > ji.b;
    }
};
struct Segtree{
    int mi, tag;
}tr[N << 2];
// dp[i] = dp[j] + (i - j) * A - (三角形覆盖的贡献和);
// 考虑将三角形覆盖的贡献和移到dp[j]中,即反向考虑这个点提供给哪些点贡献
//线段树中的点是g[i] = dp[i] - i * A - (覆盖点的贡献)
void pushup(int p){
    tr[p].mi = min(tr[p << 1].mi, tr[p << 1|1].mi);
}
void pushdown(int p){
    if(!tr[p].tag) return;
    tr[p << 1].mi += tr[p].tag;
    tr[p << 1|1].mi += tr[p].tag;
    tr[p << 1].tag += tr[p].tag;
    tr[p << 1|1].tag += tr[p].tag;
    tr[p].tag = 0;
}
void build(int l, int r, int p){
    if(l == r){
        tr[p] = {inf, 0};
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    pushup(p);
    return;
}
inline void update(int cl, int cr, int l, int r, int p, int k){
    if(cl <= l && r <= cr){
        tr[p].mi += k;
        tr[p].tag += k;
        return;
    }
    pushdown(p);
    int mid = l + r >> 1;
    if(cl <= mid) update(cl, cr, l, mid, p << 1, k);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1, k);
    pushup(p);
}
inline void modify(int pos, int l, int r, int p, int k){
    if(l == r){
        tr[p].mi = k;
        return;
    }
    pushdown(p);
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, p << 1, k);
    else modify(pos, mid + 1, r, p << 1|1, k);
    pushup(p);
}
inline int query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p].mi;
    }
    pushdown(p);
    int res = inf;
    int mid = l + r >> 1;
    if(cl <= mid) res = min(res, query(cl, cr, l, mid, p << 1));
    if(cr > mid) res = min(res, query(cl, cr, mid + 1, r, p << 1|1));
    return res;
}
void Solve(){
    int n, k, A;
    cin >> n >> k >> A;
    vector<node> edge(n + 1);
    ll res = 0;
    rep(i, 1, n){
        int x, y, c;
        cin >> x >> y >> c;
        edge[i] = {x, y, c};
        res += c;
    }
    sort(edge.begin() + 1, edge.end());
    int idx = 1;
    build(0, k, 1);
    modify(0, 0, k, 1, 0);
    for(int i = 1, j = k - 1;i <= k;i ++, j --){
        while(idx <= n && edge[idx].b == j){
            update(0, edge[idx].a, 0, k, 1, - edge[idx].c);
            idx ++;
        }
        dp[i] = min(dp[i - 1], query(0, i - 1, 0, k, 1) + i * A);
        modify(i, 0, k, 1, dp[i] - i * A);
    }
    cout << res + dp[k] << endl;
    return;
} 

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}