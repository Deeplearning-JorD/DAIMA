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
const int N = 310;
struct augment_path {
  vector<vector<int> > g;
  vector<int> pa;  // 匹配
  vector<int> pb;
  vector<int> vis;  // 访问
  int n, m;         // 两个点集中的顶点数量
  int dfn;          // 时间戳记
  int res;          // 匹配数

  augment_path(int _n, int _m) : n(_n), m(_m) {
    assert(0 <= n && 0 <= m);
    pa = vector<int>(n, -1);
    pb = vector<int>(m, -1);
    vis = vector<int>(n);
    g.resize(n);
    res = 0;
    dfn = 0;
  }

  void add(int from, int to) {
    assert(0 <= from && from < n && 0 <= to && to < m);
    g[from].push_back(to);
  }

  bool dfs(int v) {
    vis[v] = dfn;
    for (int u : g[v]) {
      if (pb[u] == -1) {
        pb[u] = v;
        pa[v] = u;
        return true;
      }
    }
    for (int u : g[v]) {
      if (vis[pb[u]] != dfn && dfs(pb[u])) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    return false;
  }

  int solve() {
    while (true) {
      dfn++;
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (pa[i] == -1 && dfs(i)) {
          cnt++;
        }
      }
      if (cnt == 0) {
        break;
      }
      res += cnt;
    }
    return res;
  }
};
ll n, m, p, q;
int get(int x, int y){
    return (x - 1) * m + y;
}
pair<int,int> fet(int x){
    return {x / m + 1, x % n};
}
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void Solve(){
    cin >> n >> m >> p >> q;
    augment_path flow = augment_path((n + 1) * (m + 1), 2 * (n + 1) * (m + 1));
    vector<vector<char>> f(n + 1, vector<char> (m + 1));
    rep(i, 1, n)rep(j, 1, m) cin >> f[i][j];
    int cnt = 0;
    rep(i, 1, n)rep(j, 1, m)if(f[i][j] == '1'){
        cnt ++;
        for(int k = 0;k < 4;k ++){
            int x = i + dx[k], y = j + dy[k];
            if(x < 1 || x > n || y < 1 || y > m || f[x][y] == '0') continue;
            if((i + j) & 1)
            flow.add(get(i, j), get(x, y));
            else flow.add(get(x, y), get(i, j));
        }
    }
    int now = flow.solve();
    int l = cnt - now * 2, r = now;
    ll res = p * l + r * q;
    while(r){
        l += 2; r --;
        res = max(res, p * l + r * q);
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}