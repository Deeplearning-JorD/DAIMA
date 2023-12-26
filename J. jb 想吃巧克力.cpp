/*
 * @Author: JorD
 * @LastEditTime: 2023-05-04 19:32:50
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
#define ls tr[p].l
#define rs tr[p].r
const int N = 2e5 + 10, inf = 1e9;
struct Segtree{
    int l, r, mx, tag;
}tr[N * 66];
int idx, root;
void pushdown(int p){
    if(!ls) ls = ++ idx;
    if(!rs) rs = ++ idx;
    tr[ls].mx += tr[p].tag;
    tr[rs].mx += tr[p].tag;
    tr[ls].tag += tr[p].tag;
    tr[rs].tag += tr[p].tag;
    tr[p].tag = 0;
}
void update(int cl, int cr, int l, int r, int &p, int k){
    if(!p) p = ++ idx;
    if(cl <= l && r <= cr){
        tr[p].mx += k;
        tr[p].tag += k;
        return;
    }
    pushdown(p);
    int mid = l + r >> 1;
    if(cl <= mid) update(cl, cr, l, mid, ls, k);
    if(cr > mid) update(cl, cr, mid + 1, r, rs, k);
    tr[p].mx = max(tr[ls].mx, tr[rs].mx);
}
void Solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    rep(i, 1, n){
        int x; cin >> x;
        a[i] = x;
        update(max(1, x - k), x, 1, inf, root, 1);
    }
    int m;
    cin >> m;
    while(m --){
        int id, x;
        cin >> id >> x;
        update(max(1, a[id] - k), a[id], 1, inf, root, -1);
        a[id] = x;
        update(max(1, a[id] - k), a[id], 1, inf, root, 1);
        cout << tr[root].mx << endl;
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