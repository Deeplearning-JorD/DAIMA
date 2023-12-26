/*
 * @Author: JorD
 * @LastEditTime: 2023-01-06 23:31:05
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
const int N = 1e6 + 10;
struct Segtree{
    int l, r, cnt;
}tr[N << 5];
int n, m;
int a[N], root[N], idx;
void build(int l, int r, int &p){
    if(!p) p = ++ idx;
    if(l == r){
        tr[p].cnt = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, tr[p].l);
    build(mid + 1, r, tr[p].r);
}
void update(int pos, int l, int r, int p, int &clone, int k){
    clone = ++ idx;
    tr[clone] = tr[p];
    if(l == r){
        tr[clone].cnt = k;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) update(pos, l, mid, tr[p].l, tr[clone].l, k);
    else update(pos, mid + 1, r, tr[p].r, tr[clone].r, k);
}
int query(int pos, int l, int r, int p, int &clone){
    clone = ++ idx;
    tr[clone] = tr[p];
    if(l == r){
        return tr[p].cnt;
    }
    int mid = l + r >> 1;
    if(pos <= mid) return query(pos, l, mid, tr[p].l, tr[clone].l);
    else return query(pos, mid + 1, r, tr[p].r, tr[clone].r);
}
void Solve(){
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    build(1, n, root[0]);
    rep(i, 1, m){
        int v, op;
        cin >> v >> op;
        if(op == 1){
            int x, y;
            cin >> x >> y;
            update(x, 1, n, root[v], root[i], y);
        }else{
            int x;
            cin >> x;
            cout << query(x, 1, n, root[v], root[i]) << endl;
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