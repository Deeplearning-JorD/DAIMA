/*
 * @Author: JorD
 * @LastEditTime: 2022-11-19 19:23:57
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 1e6 + 10;
int a[N];
int tr[N << 2];
void build(int l, int r, int p){
    if(l == r){
        tr[p] = a[l];
        return; 
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1,r, p << 1|1);
    tr[p] = min(tr[p << 1], tr[p << 1|1]);
}
int query(int l, int r, int cl, int cr, int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    int mid = l + r >> 1;
    int res = 1e9;
    if(cl <= mid) res = query(l, mid, cl, cr, p << 1);
    if(cr > mid) res = min(res, query(mid + 1, r, cl, cr, p << 1|1));
    return res;
}
void Solve(){
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    build(1, n, 1);
    rep(i, 1, n){
        int l = i + 1, r = n;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(a[i] > query(1, n, mid, n, 1)) l = mid;
            else r = mid - 1;
        }
        if(a[i] <= query(1, n, l, n, 1)) cout << -1 << ' ';
        else cout << l - i - 1 << ' ';
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Solve();
    return 0;
}