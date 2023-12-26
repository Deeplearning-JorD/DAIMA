/*
 * @Author: JorD
 * @LastEditTime: 2022-12-29 18:26:41
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
int n, m, MAXN;
vector<int> son[N];
int C[N], L[N];
struct Segtree{
    int l, r;
    ll cnt, sum;
}tr[N * 70];
int idx, root[N]; 
int rk[N], mp[N]; // rk[i]表示i对应第几便宜，mp[i]表示第i便宜所对应的价钱
inline void pushup(int p){
    tr[p].cnt = tr[tr[p].l].cnt + tr[tr[p].r].cnt;
    tr[p].sum = tr[tr[p].l].sum + tr[tr[p].r].sum;
}
inline void modify(int pos, int l, int r, int &p){
    if(!p) p = ++ idx;
    if(l == r){
        tr[p].cnt ++;
        tr[p].sum += mp[pos];
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, tr[p].l);
    else modify(pos, mid + 1, r, tr[p].r);
    pushup(p);
}
inline void merge(int &x, int y, int l = 1, int r = MAXN){
    if(!x || !y) x |= y;
    else if(l == r){
        tr[x].cnt += tr[y].cnt;
        tr[x].sum += tr[y].sum;
    }else{
        int mid = l + r >> 1;
        merge(tr[x].l, tr[y].l, l, mid);
        merge(tr[x].r, tr[y].r, mid + 1, r);
        pushup(x);
    }
}
inline int query(int p, int l, int r, int lim){
    if(!p) return 0;
    if(l == r){
        if(tr[p].sum <= lim) return 1;
        else return 0;
    }
    int mid = l + r >> 1;
    if(tr[tr[p].l].sum < lim) return tr[tr[p].l].cnt + query(tr[p].r, mid + 1, r, lim - tr[tr[p].l].sum);
    else return query(tr[p].l, l, mid, lim);
}
ll res;
void dfs(int now){
    for(auto x:son[now]){
        dfs(x);
        merge(root[now], root[x]);
    }
    res = max(res, 1ll * L[now] * query(root[now], 1, MAXN, m));
}
void Solve(){
    cin >> n >> m;
    MAXN = n;
    vector<pair<int,int>> a(n + 1);
    rep(i, 1, n){
        int x;
        cin >> x >> C[i] >> L[i];
        son[x].push_back(i);
        a[i] = {C[i], i};
    }
    sort(a.begin() + 1, a.end());
    rep(i, 1, n){
        auto [x, y] = a[i];
        rk[y] = i;
        mp[i] = x;
        modify(i, 1, MAXN, root[y]);
    }
    dfs(1);
    printf("%lld", res);
    return;
}
int main(){
    Solve();
    return 0;
}