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
struct Segtree{
    int pre, now, sum;
}tr[N << 2];
int a[N], res[N];
int st[N];
void pushup(int p){
    if(tr[p << 1].sum < tr[p << 1|1].sum){
        tr[p] = tr[p << 1];
    }else tr[p] = tr[p << 1|1];
}
void build(int l, int r, int p){
    if(l == r){
        tr[p] = {inf, a[l], inf};
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    pushup(p);
}
void modify(int pos, int l, int r, int p, int k){
    if(l == r){
        tr[p].pre = k;
        tr[p].sum = k;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, p << 1, k);
    else modify(pos, mid + 1, r, p << 1|1, k);
    pushup(p);
}
Segtree query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    int mid = l + r >> 1;
    if(cr <= mid) return query(cl, cr, l, mid, p << 1);
    if(cl > mid) return query(cl, cr, mid + 1, r, p << 1|1);
    auto L = query(cl, cr, l, mid, p << 1);
    auto R = query(cl, cr, mid + 1, r, p << 1|1);
    if(L.sum < R.sum) return L;
    else return R;
}
void Solve(){
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    build(1, n, 1);
    auto now = query(2, 3, 1, n, 1);
    int m; cin >> m;
    vector<vector<pair<int,int>>> q(n + 1);
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        q[y].push_back({x, i});
    }
    rep(i, 1, n){
        if(st[a[i]]) modify(st[a[i]], 1, n, 1, inf);
        modify(i, 1, n, 1, st[a[i]]);
        st[a[i]] = i;
        for(auto [x, id]:q[i]){
            auto now = query(x, i, 1, n, 1);
            if(now.sum < x) res[id] = now.now;
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