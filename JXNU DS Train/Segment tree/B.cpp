/*
 * @Author: JorD
 * @LastEditTime: 2022-12-19 09:17:56
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
int n;  
vector<int> son[N];
int zson[N], depth[N], siz[N], fat[N];
void dfs1(int now, int fa){
    int mx = 0;
    siz[now] = 1;
    depth[now] = depth[fa] + 1;
    fat[now] = fa;
    for(auto x:son[now]){
        if(x == fa) continue;
        dfs1(x, now);
        siz[now] += siz[x];
        if(siz[x] > mx){
            mx = siz[x];
            zson[now] = x;
        }
    }
}
int top[N], id[N], idx, mid[N];
void dfs(int now, int fa, int T){
    top[now] = T;
    id[now] = ++ idx;
    mid[now] = idx;
    if(!zson[now]) return;
    dfs(zson[now], now, T);
    for(auto x:son[now]){
        if(x == zson[now] || x == fa) continue;
        dfs(x, now, x);
    }
}
int tr[N << 2], lazy[N << 2];
void pushdown(int l, int r, int p){
    int mid = l + r >> 1;
    if(lazy[p] == 1){
        tr[p << 1] = mid - l + 1;
        tr[p << 1|1] = r - mid;
        lazy[p << 1] = lazy[p << 1|1] = lazy[p];
    }else if(lazy[p] == -1){
        tr[p << 1] = tr[p << 1|1] = 0;
        lazy[p << 1] = lazy[p << 1|1] = lazy[p];
    }
    lazy[p] = 0;
}
void update(int cl, int cr, int l, int r, int p, int k){
    if(cl <= l && r <= cr){
        if(k == 1){
            tr[p] = r - l + 1;
        }else{
            tr[p] = 0;
        }
        lazy[p] = k;
        return;
    }
    int mid = l + r >> 1;
    pushdown(l, r, p);
    if(cl <= mid) update(cl, cr, l, mid, p << 1, k);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1, k);
    tr[p] = tr[p << 1] + tr[p << 1|1];
}
bool check(int pos, int l, int r, int p){
    if(l == r){
        return tr[p];
    }
    int mid = l + r >> 1;
    bool st = false;
    pushdown(l, r, p);
    if(pos <= mid) st |= check(pos, l, mid, p << 1);
    if(pos > mid) st |= check(pos, mid + 1, r, p << 1|1);
    tr[p] = tr[p << 1] + tr[p << 1|1];
    return st;
}
void filldown(int v){
    update(id[v], id[v] + siz[v] - 1, 1, n, 1, 1);
}
void fillup(int v){
    while(v){
        update(id[top[v]], id[v], 1, n, 1, -1);
        v = fat[top[v]];
    }
}
void Solve(){
    cin >> n;
    rep(i, 2, n){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    dfs1(1, 0);
    dfs(1, 0, 1);
    int m;
    cin >> m;
    while(m --){
        int op, v;
        cin >> op >> v;
        if(op == 1){
            filldown(v);
        }else if(op == 2){
            fillup(v);
        }else{
            cout << check(id[v], 1, n, 1) << endl;
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