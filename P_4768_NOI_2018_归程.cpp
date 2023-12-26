/*
 * @Author: JorD
 * @LastEditTime: 2023-10-14 17:34:35
 * how to Get
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
const int N = 4e5 + 10;
vector<vector<pair<int,int>>> son;
struct edge{
    int a, b, c;
    bool operator <(const edge &ji)const{
        return c > ji.c;
    }
};
int f[N], fat[22][N];
int find(int x){
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}
void Solve(){
    int n, m;
    cin >> n >> m;
    son.resize(n + 1);
    rep(i, 1, n << 1) f[i] = i;
    vector<edge> e(m + 1);
    rep(i, 1, m){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        son[a].push_back({b, c});
        son[b].push_back({a, c});
        e[i] = {a, b, d};
    }
    sort(e.begin() + 1, e.end());
    vector<int> dist(n << 1|1, 1e9);
    vector<bool> st(n + 1);
    dist[1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, 1});
    while(q.size()){
        auto [t, now] = q.top(); q.pop();
        if(st[now]) continue;
        st[now] = true;
        for(auto [x, w] : son[now])if(dist[x] > t + w){
            dist[x] = t + w;
            q.push({dist[x], x});
        }
    }
    int idx = n;
    vector<int> w(n << 1|1);
    vector<vector<int>> zson(n << 1|1);
    rep(i, 1, m){
        auto [a, b, c] = e[i];
        a = find(a); b = find(b);
        if(a == b) continue;
        f[a] = f[b] = ++ idx;
        fat[0][a] = fat[0][b] = idx;
        zson[idx].push_back(a);
        zson[idx].push_back(b);
        w[idx] = c;
    }
    vector<int> mi(idx + 1, 1e9);
    function<void(int)> dfs = [&](int now){
        mi[now] = dist[now];
        for(auto x:zson[now]){
            dfs(x);
            mi[now] = min(mi[now], mi[x]);
        }
    };
    dfs(idx);
    fat[0][idx] = 0;
    for(int i = 1;i <= 20;i ++){
        for(int j = 1;j <= idx;j ++){
            fat[i][j] = fat[i - 1][fat[i - 1][j]];
        }
    }
    int T, k, s, res = 0;
    cin >> T >> k >> s;
    while(T --){
        int v, p;
        cin >> v >> p;
        v = (v + k * res - 1) % n + 1;
        p = (p + k * res) % (s + 1);
        for(int i = 20;i >= 0;i --)if(w[fat[i][v]] > p){
            v = fat[i][v];
        }
        res = mi[v];
        cout << res << endl;
    }
    son.clear();
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}