/*
 * @Author: JorD
 * @LastEditTime: 2022-09-22 15:02:07
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
const int N = 1e5 + 10;
vector<int> son[N];
char res[N];
int a[N];
int deep[N], f[N][25];
int dist[N];
inline int find(int x){
    if(x != a[x]) a[x] = find(a[x]);
    return a[x];
}
inline bool same(int x, int y){
    return find(x) == find(y);
}
inline void merge(int x, int y){
    a[find(y)] = find(x);
    return;
}
inline void dfs(int now, int fa){
    deep[now] = deep[fa] + 1;
    f[now][0] = fa;
    rep(i, 1, 20) 
        f[now][i] = f[f[now][i - 1]][i - 1];
    for(auto x:son[now]){
        if(x == fa) continue;
        dfs(x, now);
    }
}
inline int lca(int x, int y){
    if(deep[x] < deep[y]) swap(x, y);
    per(i, 20, 0){
        if(deep[f[x][i]] >= deep[y])
            x = f[x][i];
    }
    if(x == y) return x;
    per(i, 20, 0){
        if(f[x][i] == f[y][i]) continue;
        x = f[x][i];
        y = f[y][i];
    }
    return f[x][0];
}
inline void Dfs(int now, int fa){
    if(dist[now]) res[now] = '0';
    else res[now] = '1';
    for(auto x:son[now]){
        if(x == fa) continue;
        dist[x] += dist[now];
        Dfs(x, now);
    }
}
void Solve(){
    int n, m;
    cin >> n >> m;  
    rep(i, 1, n) a[i] = i;
    vector<pair<int,int>> corss;
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        if(same(x, y)){
            corss.push_back({x, y});
        }else{
            merge(x, y);
            son[x].push_back(y);
            son[y].push_back(x);
        }
    }
    dfs(1, 0);
    for(auto x:corss){
        int c = x.first, d = x.second;
        if(deep[c] > deep[d]) swap(c, d);
        int p = lca(c, d);
        if(c == p){
            int s = d;
            per(i, 20, 0)
                if(deep[f[s][i]] > deep[c]) s = f[s][i];
            dist[s] ++;
            dist[d] --;
        }else{  
            dist[1] ++;
            dist[c] --;
            dist[d] --;
        }
    }
    Dfs(1, 0);
    rep(i, 1, n) cout << res[i];
    return;
}
int main(){
    //搜一边的时候会dfs搜到低然后就会有加入横叉边的情况。
    //如果遍历到当前点的时候，横叉边对应的点还没有被搜到，就有可能被加入。
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Solve();
    return 0;
}