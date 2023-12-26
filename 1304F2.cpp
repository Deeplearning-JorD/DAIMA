/*
 * @Author: JorD
 * @LastEditTime: 2023-05-02 15:24:49
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
#define rep(i, l, r) for (auto(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 2e4 + 10;
ll a[55][N];
ll sum[55][N];
ll dp[N];
struct Segtree{
    int w, tag;
}tr[N << 2];
void build(int l, int r, int p){
    tr[p] = {0, 0};
    if(l == r){
        tr[p].w = dp[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    tr[p].w = max(tr[p << 1].w, tr[p << 1|1].w);
}
void pushdown(int p){
    if(!tr[p].tag) return;
    tr[p << 1].w += tr[p].tag;
    tr[p << 1|1].w += tr[p].tag;
    tr[p << 1].tag += tr[p].tag;
    tr[p << 1|1].tag += tr[p].tag;
    tr[p].tag = 0;
}
void update(int cl, int cr, int l, int r, int p, int k){
    if(cl > cr) return;
    if(cl <= l && r <= cr){
        tr[p].w += k;
        tr[p].tag += k;
        return;
    }
    pushdown(p);
    int mid = l + r >> 1;
    if(cl <= mid) update(cl, cr, l, mid, p << 1, k);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1, k);
    tr[p].w = max(tr[p << 1].w, tr[p << 1|1].w);
} 
void Solve(){
    int n, m, k;
    cin >> n >> m >> k;
    rep(i, 1, n)
    rep(j, 1, m)
    cin >> a[i][j];
    rep(i, 1, n) rep(j, 1, m) sum[i][j] = a[i + 1][j] + a[i][j];
    ll res = 0;
    vector<ll> pre(m + 1);
    rep(i, 1, m) pre[i] = pre[i - 1] + sum[1][i];
    rep(i, 1, m - k + 1) dp[i] = pre[i + k - 1] - pre[i - 1];
    rep(i, 2, n){
        build(1, m - k + 1, 1);
        rep(j, 1, m) pre[j] = pre[j - 1] + a[i + 1][j];
        for(int j = 1;j <= k;j ++) update(j + 1, m - k + 1, 1, m - k + 1, 1, a[i][j]);
        dp[1] = tr[1].w + pre[k];
        for(int j = 2;j <= m - k + 1;j ++){
            int id = j - 1;
            update(1, id - k, 1, m - k + 1, 1, -a[i][id]);
            update(id + 1, m - k + 1, 1, m - k + 1, 1, -a[i][id]);
            id += k;
            update(1, id - k, 1, m - k + 1, 1, a[i][id]);
            update(id + 1, m - k + 1, 1, m - k + 1, 1, a[i][id]);
            dp[j] = tr[1].w + pre[j + k - 1] - pre[j - 1];
        }
    }
    build(1, m - k + 1, 1);
    res = tr[1].w;
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