/*
 * @Author: JorD
 * @LastEditTime: 2023-01-02 15:32:35
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
int tr[N << 2], lazy[N << 2];
int id[N], mp[N], idx, siz[N];
vector<int> son[N];
int a[N];
void dfs(int now, int fa){
    id[now] = ++ idx;
    mp[idx] = now;
    siz[now] = 1;
    for(auto x:son[now])if(x != fa){
        dfs(x, now);
        siz[now] += siz[x];
    }
}
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
void build(int l, int r, int p){
    if(l == r){
        tr[p] = a[mp[l]];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    pushup(p);
}
void update(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        tr[p] = r - l + 1 - tr[p];
        lazy[p] ^= 1;
        return;
    }
    pushdown(l, r, p);
    int mid = l + r >> 1;
    if(cl <= mid) update(cl, cr, l, mid, p << 1);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1);
    pushup(p);
}
int query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p];    
    }
    pushdown(l, r, p);
    int mid = l + r >> 1;
    int res = 0;
    if(cl <= mid) res += query(cl, cr, l, mid, p << 1);
    if(cr > mid) res += query(cl, cr, mid + 1, r, p << 1|1);
    return res;
}
void Solve(){
    int n;
    cin >> n;
    rep(i, 2, n){
        int x; cin >> x;
        son[x].push_back(i);
    } 
    rep(i, 1, n) cin >> a[i];
    dfs(1, 0);
    build(1, n, 1);
    int m; cin >> m;
    while(m --){
        string s; cin >> s;
        int v; cin >> v;
        if(s == "get"){
            cout << query(id[v], id[v] + siz[v] - 1, 1, n, 1) << endl;
        }else{
            update(id[v], id[v] + siz[v] - 1, 1, n, 1);
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