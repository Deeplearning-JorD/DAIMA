/*
 * @Author: JorD
 * @LastEditTime: 2022-11-18 12:05:35
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
const int N = 5e5 + 10;
vector<int> son[N];
int depth[N], zson[N], siz[N], fat[N];
int n, root, t;
void dfs1(int now, int fa){
    fat[now] = fa;
    depth[now] = depth[fa] + 1;
    siz[now] = 1;
    int mx = 0;
    for(auto x:son[now]){
        if(x == fa) continue;
        dfs1(x, now);
        siz[now] += siz[x];
        if(mx < siz[x]){
            mx = siz[x];
            zson[now] = x;
        }
    }
}
int top[N];
void dfs2(int now, int fa, int T){
    top[now] = T;
    if(!zson[now]) return;
    dfs2(zson[now], now, T);
    for(auto x:son[now]){
        if(x == fa||x == zson[now]) continue;
        dfs2(x, now, x);
    }
}
int lca(int a, int b){
    while(top[a] != top[b]){
        if(depth[top[a]] < depth[top[b]]) swap(a, b);
        a = fat[top[a]];
    }
    if(depth[a] > depth[b]) swap(a, b);
    return a;
}
void Solve(){
    cin >> n >> t >> root;
    rep(i, 2, n){
        int a, b;
        cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    dfs1(root, 0);
    dfs2(root, 0, root);
    while(t --){
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Solve();
    return 0;
}