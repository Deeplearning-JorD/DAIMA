/*
 * @Author: JorD
 * @LastEditTime: 2023-02-27 21:28:27
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
const int N = 5e5 + 10;
int a[N];
struct Segtree{
    int val, lmax, rmax, sum;
    
}tr[N << 2];
Segtree operator +(Segtree L, Segtree R){
    Segtree now;
    now.val = max({L.val, R.val, L.rmax + R.lmax});
    now.lmax = max(L.sum + R.lmax, L.lmax);
    now.rmax = max(R.sum + L.rmax, R.rmax);
    now.sum = L.sum + R.sum;
    return now;
}
void build(int l, int r, int p){
    if(l == r){
        tr[p] = {a[l], a[l], a[l], a[l]};
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    tr[p] = tr[p << 1] + tr[p << 1|1];
}
Segtree query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    int mid = l + r >> 1;
    if(cl > mid) return query(cl, cr, mid + 1, r, p << 1|1);
    if(cr <= mid) return query(cl, cr, l, mid, p << 1);
    auto L = query(cl, cr, l, mid, p << 1);
    auto R = query(cl, cr, mid + 1, r, p << 1|1);
    return (L + R); 
}
void modify(int l, int r, int pos, int p, int k){
    if(l == r){
        tr[p] = {k,k,k,k};
        return;
    }
    int mid = l + r >> 1;
    if(mid < pos) modify(mid + 1, r, pos, p << 1|1, k);
    else modify(l, mid, pos, p << 1, k);
    tr[p] = tr[p << 1] + tr[p << 1|1];
    return;
}
void Solve(){
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    build(1, n, 1);
    while(m --){
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1){
            if(x > y) swap(x, y);
            cout << query(x, y, 1, n, 1).val << endl;
        }else{
            modify(1, n, x, 1, y);
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