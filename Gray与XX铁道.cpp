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
const int N = (1 << 20) + 10;
struct Segtree{
    int l, r;
}tr[N << 2];
int id[N];
void build(int l, int r, int p){
    // cout << p << ' ' << l << ' ' << r << endl;
    tr[p] = {l, r};
    if(l == r){
        id[l] = p;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
}
int query(int pos, int now, int l, int r, int p){
    if(pos == now) return 0;
    int mid = l + r >> 1;
    if(pos <= mid) return abs(now - l) + query(pos, l, l, mid, p << 1);
    return abs(now - r) + query(pos, r, mid + 1, r, p << 1|1);
}
void Solve(){
    int n, m; cin >> n >> m;
    build(1, 1 << n, 1);
    while(m --){
        int x, y; cin >> x >> y;
        if(x > y) swap(x, y);
        int sx = id[x], sy = id[y];
        int root = sx;
        while(sx != sy){
            sx >>= 1;
            sy >>= 1;
            root = sx;
        }
        int res = tr[root].r - tr[root].l;
        res += query(x, tr[root].l, tr[root].l, tr[root].r, root);
        res += query(y, tr[root].r, tr[root].l, tr[root].r, root);
        cout << res << endl;
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