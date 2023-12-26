/*
 * @Author: JorD
 * @LastEditTime: 2023-01-05 21:45:34
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
const int N = 1e5 + 10;
ll tr[N << 2], lazy[N << 2];
void pushup(int p){
    tr[p] = tr[p << 1] + tr[p << 1|1];
}
void pushdown(int l, int r, int p){
    int mid = l + r >> 1;
    if(lazy[p]){
        tr[p << 1] = mid - l + 1 - tr[p << 1];
        tr[p << 1|1] = r - mid - tr[p << 1|1];
        lazy[p << 1] ^= lazy[p];
        lazy[p << 1|1] ^= lazy[p]; 
    }
    lazy[p] = 0;
}
void update(int cl, int cr, int l, int r, int p, int k){
    if(cl <= l && r <= cr){
        tr[p] += k;
        return;
    }
    // pushdown(l, r, p);
    int mid = l + r >> 1;
    if(cl <= mid) update(cl, cr, l, mid, p << 1, k);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1, k);
    pushup(p);
}
ll query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    // pushdown(l, r, p);
    ll mid = l + r >> 1, res = 0;
    if(cl <= mid) res += query(cl, cr, l, mid, p << 1);
    if(cr > mid) res += query(cl, cr, mid + 1, r, p << 1|1);
    return res;
}
void Solve(){
    int n, m;
    cin >> n >> m;
    while(m --){
        int x, y;
        char op;
        cin >> op >> x >> y;
        if(op == 'x'){
            update(x, x, 1, n, 1, y);
        }else cout << query(x, y, 1, n, 1) << endl;
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