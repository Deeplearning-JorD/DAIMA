#pragma GCC optimize(2)
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
const int N = 2e3 + 10;
ll tr[N << 2];
ll a[N];
void build(int l, int r, int p){
    if(l == r){
        tr[p] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    if(tr[p << 1] < 0 || tr[p << 1|1] < 0){
        tr[p] = max(tr[p << 1], tr[p << 1|1]);
    }else tr[p] = tr[p << 1] + tr[p << 1|1];
    // tr[p] = max({tr[p << 1], tr[p << 1|1], tr[p << 1] + tr[p << 1|1]});
}
ll query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    int mid = l + r >> 1;
    if(cr <= mid) return query(cl, cr, l, mid, p << 1);
    if(cl > mid) return query(cl, cr, mid + 1, r, p << 1|1);
    ll L = query(cl, cr, l, mid, p << 1);
    ll R = query(cl, cr, mid + 1, r, p << 1|1);   
    if(L < 0 || R < 0) return max(L, R);
    return L + R;
}
void Solve(){
    ll n, k; cin >> n >> k;
    rep(i, 1, n) cin >> a[i];
    build(1, n, 1);
    rep(i, 1, n){
        rep(j, i, n){
            cout << i << ' ' << j << ' ' << query(i, j, 1, n, 1) << endl;
        }
    }
    cout << query(2, 5, 1, n, 1) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}