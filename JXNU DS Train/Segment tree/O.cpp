/*
 * @Author: JorD
 * @LastEditTime: 2023-01-02 22:59:52
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
const int N = 3e5 + 10;
struct Segtree{
    int l, r, sum;
}tr[N * 50];
int lazy[N * 50];
int root, idx;
void pushup(int p){
    tr[p].sum = tr[tr[p].l].sum + tr[tr[p].r].sum;
}
void pushdown(int l, int r, int p){
    int mid = l + r >> 1;
    if(!tr[p].l) tr[p].l = ++ idx;
    if(!tr[p].r) tr[p].r = ++ idx;
    if(lazy[p] == 1){
        tr[tr[p].l].sum = mid - l + 1;
        tr[tr[p].r].sum = r - mid;
        lazy[tr[p].l] = lazy[p];
        lazy[tr[p].r] = lazy[p];
    }else if(lazy[p] == -1){
        tr[tr[p].l].sum = 0;
        tr[tr[p].r].sum = 0;
        lazy[tr[p].l] = lazy[p];
        lazy[tr[p].r] = lazy[p];
    }
    lazy[p] = 0;
}
void update(int cl, int cr, int l, int r, int &p, int k){
    if(!p) p = ++ idx;
    if(cl <= l && r <= cr){
        if(k == 1){
            tr[p].sum = r - l + 1;
            lazy[p] = 1;
        }else{
            tr[p].sum = 0;
            lazy[p] = -1;
        }
        return;
    }
    pushdown(l, r, p);
    int mid = l + r >> 1;
    if(cl <= mid) update(cl, cr, l, mid, tr[p].l, k);
    if(cr > mid) update(cl, cr, mid + 1, r, tr[p].r, k);
    pushup(p);
}
void Solve(){
    int n, m;
    cin >> n >> m;
    update(1, n, 1, n, root, 1);
    while(m --){
        int x, y, k;
        cin >> x >> y >> k;
        if(k == 2) update(x, y, 1, n, root, 1);
        else update(x, y, 1, n, root, 0);
        cout << tr[root].sum << endl;
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