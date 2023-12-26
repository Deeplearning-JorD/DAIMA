/*
 * @Author: JorD
 * @LastEditTime: 2022-12-12 00:17:47
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
int tr[N << 2];
int R[N];
void build(int l, int r, int p){
    if(l == r){
        tr[p] = R[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    tr[p] = min(tr[p << 1], tr[p << 1|1]);
}
int query(int l, int r, int cl, int cr, int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    int mid = l + r >> 1;
    int res = 1e9;
    if(cl <= mid) res = min(res, query(l, mid, cl, cr, p << 1));
    if(cr > mid) res = min(res, query(mid + 1, r, cl, cr, p << 1|1));
    return res;
}
void Solve(){
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) R[i] = n + 1;
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        R[x] = min(R[x], y);
    }
    build(1, n, 1);
    ll res = 0;
    rep(i, 1, n){
        res += query(1, n, i, n, 1) - i;
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}