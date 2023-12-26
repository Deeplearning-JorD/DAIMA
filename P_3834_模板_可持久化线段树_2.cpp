/*
 * @Author: JorD
 * @LastEditTime: 2023-01-07 07:23:47
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
const int N = 2e5 + 10, inf = 1e9;
struct Segtree{
    int l, r, sum;
}tr[N << 5];
int a[N], root[N], idx;
void update(int pos, int l, int r, int p, int &clone){
    clone = ++ idx;
    tr[clone]= tr[p];
    if(l == r){
        tr[clone].sum ++;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) update(pos, l, mid, tr[p].l, tr[clone].l);
    else update(pos, mid + 1, r, tr[p].r, tr[clone].r);
    tr[clone].sum = tr[tr[clone].l].sum + tr[tr[clone].r].sum;
}
int query(int l, int r, int L, int R, int k){
    if(l == r){
        return l;
    }
    int mid = l + r >> 1;
    int sum = tr[tr[R].l].sum - tr[tr[L].l].sum;
    if(k > sum) return query(mid + 1, r, tr[L].r, tr[R].r, k - sum);
    else return query(l, mid, tr[L].l, tr[R].l, k); 
}
void Solve(){
    int n, m;
    cin >> n >> m;
    rep(i, 1, n){
        int x; cin >> x;
        update(x, - inf, inf, root[i - 1], root[i]);
    }
    while(m --){
        int l, r, k;
        cin >> l >> r >> k; 
        cout << query(- inf, inf, root[l - 1], root[r], k) << endl;
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