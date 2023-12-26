/*
 * @Author: JorD
 * @Date: 2023-11-23 00:41:13
 * @LastEditTime: 2023-11-24 12:13:08
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
vector<int> son[N];
ll a[N], f[N];
int find(int x){
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}
ll fa[N][23], e[N], mx[N][23];
void dfs(int now, int last){
    fa[now][0] = last;
    for(int i = 1;i <= 20;i ++){
        fa[now][i] = fa[fa[now][i - 1]][i - 1];
        mx[now][i] = max(mx[now][i - 1], mx[fa[now][i - 1]][i - 1]);
    }
    for(auto x:son[now]) dfs(x, now);
}
void Solve(){
    int n, m, q; cin >> n >> m >> q;
    rep(i, 1, 2 * n) f[i] = i;
    rep(i, 1, n) cin >> a[i];
    int idx = n;
    vector<array<int,3>> edge(m + 1);
    rep(i, 1, m){
        int x, y, w; cin >> x >> y >> w;
        edge[i] = {w, x, y};
    }
    sort(edge.begin() + 1, edge.end());
    for(int i = 1;i <= m;i ++){
        auto [w, x, y] = edge[i];
        x = find(x), y = find(y);
        if(x == y) continue;
        idx ++;
        e[idx] = w;
        son[idx].push_back(x);
        son[idx].push_back(y);
        f[x] = idx;
        f[y] = idx;
        a[idx] = a[x] + a[y];
        mx[x][0] = w - a[x];
        mx[y][0] = w - a[y];
    }
    dfs(idx, 0);
    e[0] = 3e9;
    while(q --){
        int x, v; cin >> x >> v;
        for(int i = 20;i >= 0;i --)if(fa[x][i] && mx[x][i] <= v){
            x = fa[x][i];
        }
        cout << v + a[x] << endl;
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