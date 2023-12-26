/*
 * @Author: JorD
 * @Date: 2023-10-19 11:39:37
 * @LastEditTime: 2023-10-19 19:51:30
 * how to Get
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
const int N = 2e5 + 10;
struct Segtree{
    int l, r, cnt;
}tr[N * 60];
int root[N];
vector<int> son[N];
int depth[N], fat[N][20];
void dfs1(int now, int fa){
    depth[now] = depth[fa] + 1;
    fat[now][0] = fa;
    for(int i = 1;i <= 18;i ++)
        fat[now][i] = fat[fat[now][i - 1]][i - 1];
    for(auto x:son[now]){
        dfs1(x, now);
    }
}
int find(int x, int k){
    for(int i = 18;i >= 0;i --)if(k - (1 << i) >= 0 && depth[fat[x][i]] > 1){
        x = fat[x][i];
        k -= 1 << i;
    }
    if(k) return -1;
    return x;
}
int idx;
#define ls tr[p].l
#define rs tr[p].r
void modify(int pos, int l, int r, int &p){
    if(!p) p = ++ idx;
    if(l == r){
        tr[p].cnt ++;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, ls);
    if(pos > mid) modify(pos, mid + 1, r, rs);
}
int query(int pos, int l, int r, int p){
    if(!p) return 0;
    if(l == r) return tr[p].cnt;
    int mid = l + r >> 1;
    if(pos <= mid) return query(pos, l, mid, ls);
    return query(pos, mid + 1, r, rs);
}
int n; 
void merge(int &x, int y, int l, int r){
    if(!x || !y) x |= y;
    else if(l == r) tr[x].cnt += tr[y].cnt;
    else{
        int mid = l + r >> 1;
        merge(tr[x].l, tr[y].l, l, mid);
        merge(tr[x].r, tr[y].r, mid + 1, r);
    }
}
vector<pair<int,int>> need[N];
int res[N];
void dfs(int now){
    for(auto x:son[now]){
        dfs(x);
        merge(root[now], root[x], 0, n);
    }
    for(auto [x, y]:need[now]){
        res[x] = query(depth[now] + y, 0, n, root[now]) - 1;
    }
}
void Solve(){
    cin >> n;
    rep(i, 1, n){
        int x; cin >> x;
        if(x == 0) son[n + 1].push_back(i);
        else son[x].push_back(i);
    }
    dfs1(n + 1, 0);
    rep(i, 1, n){
        modify(depth[i], 0, n, root[fat[i][0]]);
    }
    int m; cin >> m;
    rep(i, 1, m){
        int x, k; cin >> x >> k;
        x = find(x, k);
        if(x == -1) continue;
        need[x].push_back({i, k});
    }
    dfs(n + 1);
    rep(i, 1, m) cout << res[i] << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}