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
const int N = 5e5 + 10, inf = 1e9;
int idx = 0;
struct Segtree{
    int l, r, sum;
}tr[N * 40];
pair<int,int> a[N];
int root = 0;
inline void pushup(int p){
    tr[p].sum = tr[tr[p].l].sum + tr[tr[p].r].sum;
}
inline void modify(int l, int r, int pos, int& p, int k){
    if(!p) p = ++ idx;
    if(l == r){
        tr[p].sum += k;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(l, mid, pos, tr[p].l, k);
    else modify(mid + 1, r, pos, tr[p].r, k);
    pushup(p);
}
inline int query(int cl, int cr, int l, int r, int p){
    if(!p) return 0;
    if(cl <= l && r <= cr){
        return tr[p].sum;
    }
    int mid = l + r >> 1;
    int res = 0;
    if(cl <= mid) res = query(cl, cr, l, mid, tr[p].l);
    if(cr > mid) res += query(cl, cr, mid + 1, r, tr[p].r);
    return res;
}
inline int query0(int l, int r, int p, int k){
    if(l == r){
        return l;
    }
    int mid = l + r >> 1;
    if(tr[tr[p].l].sum >= k) return query0(l, mid, tr[p].l, k);
    return query0(mid + 1, r, tr[p].r, k - tr[tr[p].l].sum);
}
inline int query1(int l, int r, int p, int k){
    if(l == r){
        return l;
    }
    int mid = l + r >> 1;
    if(tr[tr[p].l].sum >= k) return query1(l, mid, tr[p].l, k);
    return query1(mid + 1, r, tr[p].r, k - tr[tr[p].l].sum);
}
void cleartree(int l, int r, int& p){
    if(!p) return;
    if(l == r){
        tr[p] = {0, 0, 0};
        return;
    }
    int mid = l + r >> 1;
    cleartree(l, mid, tr[p].l);
    cleartree(mid + 1, r, tr[p].r);
    tr[p] = {0, 0, 0};
    return;
} 
void Solve(){
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + 1 + n, [](pair<int,int> x, pair<int,int> y){
        return x.first > y.first;
    });
    int last = -inf;
    ll res = 1e18; 
    for(int i = 1;i <= n;i ++){
        modify(0, inf, a[i].second, root, 1);
    }
    for(int i = 1;i <= n;i ++){
        int now = a[i].first;
        int ji = last;
        modify(0, inf, a[i].second, root, -1);
        int l = 0, r = inf;
        int L = -inf, R = -inf;
        int mb = query(0, now, 0, inf, root);
        if(mb>0) L = max(last, query0(0, inf, root, mb));
        if(query(0, inf, 0, inf, root) > mb) R = max(last, query1(0, inf, root, mb + 1));
        res = min(res, 1ll * abs(now - max(L, last)));
        res = min(res, 1ll * abs(now - max(R, last)));
        last = max(last, a[i].second);
    }
    cout << res << endl;
    cleartree(0, inf, root);
    root = 0, idx = 0; 
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --) 
    Solve();
    return 0;
}