/*
 * @Author: JorD
 * @LastEditTime: 2023-01-03 23:45:26
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
const int N = 2e5 + 10;
int a[N], b[N], h[N];
int n, m;
unordered_map<int,int> q;
int tr2[N << 2];
void build2(int l, int r, int p){
    if(l == r){
        tr2[p] = b[l];
        return;
    }
    int mid = l + r >> 1;
    build2(l, mid, p << 1);
    build2(mid + 1, r, p << 1|1);
    tr2[p] = max(tr2[p << 1], tr2[p << 1|1]);
}
int query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr2[p];
    }
    int mid = l + r >> 1;
    int res = 0;
    if(cl <= mid) res = query(cl, cr, l, mid, p << 1);
    if(cr > mid) res = max(res, query(cl, cr, mid + 1, r, p << 1|1));
    return res;
}
void Solve(){
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    cin >> m;
    vector<int> v;
    rep(i, 1, m) cin >> h[i];
    
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}