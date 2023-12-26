/*
 * @Author: JorD
 * @LastEditTime: 2022-09-23 19:56:32
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
const int N = 3e5 + 10;
int a[N], pos[N];
struct node{
    int mx, mi;
}tr[N << 2];
void build(int l, int r, int p){
    if(l == r){
        tr[p] = {a[l], a[l]};
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    tr[p].mx = max(tr[p << 1].mx, tr[p << 1|1].mx);
    tr[p].mi = min(tr[p << 1].mi, tr[p << 1|1].mi);
}
int query1(int l, int r, int cl, int cr, int p){
    if(cl <= l && r <= cr) return tr[p].mx;
    int mid = l + r >> 1;
    int res = 0;
    if(mid >= cl) res = query1(l, mid, cl, cr, p << 1);
    if(mid < cr) res = max(res, query1(mid + 1, r, cl, cr, p << 1|1));
    return res;
}
int query2(int l, int r, int cl, int cr, int p){
    if(cl <= l && r <= cr) return tr[p].mi;
    int mid = l + r >> 1;
    int res = N;
    if(mid >= cl) res = query2(l, mid, cl, cr, p << 1);
    if(mid < cr) res = min(res, query2(mid + 1, r, cl, cr, p << 1|1));
    return res;
}
int n;
int dfs(int l, int r){
    if(l + 1 == r) return 1;
    if(l >= r) return 0;
    int L = query2(1, n, l, r, 1);
    int R = query1(1, n, l, r, 1);
    L = pos[L];
    R = pos[R];
    if(L > R) swap(L, R);
    return dfs(l, L) + dfs(R, r) + 1;
}
void Solve(){
    cin >> n;
    rep(i, 1, n) cin >> a[i], pos[a[i]] = i;
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    build(1, n, 1);
    cout << dfs(1, n) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}