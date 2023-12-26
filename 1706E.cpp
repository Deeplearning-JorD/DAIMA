/*
 * @Author: JorD
 * @LastEditTime: 2022-09-22 21:48:00
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
const int N = 2e5 + 10;
int a[N];
int find(int x){
    if(x != a[x]) a[x] = find(a[x]);
    return a[x];
}
void merge(int x, int y){
    a[find(y)] = find(x);
}
bool same(int x, int y){
    return find(x) == find(y);
}
void Solve(){
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int>> son(n + 1);
    vector<vector<pair<int,int>>> edge(n + 1);
    vector<vector<int>> f(n + 1, vector<int> (20));
    vector<vector<int>> w(n + 1, vector<int> (20));
    vector<int> depth(n + 1);
    rep(i, 1, n) a[i] = i;
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        if(!same(x, y)){
            edge[x].push_back({y, i});
            edge[y].push_back({x, i});
            merge(x, y);
        }   
    }
    function<void(int,int,int)> dfs = [&](int now, int fa, int val){
        depth[now] = depth[fa] + 1;
        f[now][0] = fa;
        w[now][0] = val;
        rep(i, 1, 18){
            f[now][i] = f[f[now][i - 1]][i - 1];
            w[now][i] = max(w[now][i - 1], w[f[now][i - 1]][i - 1]);
        }
        for(auto x:edge[now]){
            if(x.first == fa) continue;
            dfs(x.first, now, x.second);
        }
    };
    auto lca = [&](int x, int y){
        int res = 0;
        if(depth[x] > depth[y]) swap(x, y);
        per(i, 18, 0)
            if(depth[f[y][i]] >= depth[x]){
                res = max(w[y][i], res);
                y = f[y][i];
            }
        if(x == y)  return res;
        per(i, 18, 0){
            if(f[x][i] == f[y][i])  continue;
            res = max(res, w[x][i]);
            res = max(res, w[y][i]);
            x = f[x][i];
            y = f[y][i];
        }
        res = max(res, w[x][0]);
        res = max(res, w[y][0]);
        return res;
    };
    dfs(1, 0, 0);
    vector<int> num(n + 1);
    vector<int> tr((n + 1) << 2);
    rep(i, 1, n - 1){
        num[i] = lca(i + 1, i);
    }
    function<void(int,int,int)> build = [&](int l, int r, int p){
        if(l == r){
            tr[p] = num[l];
            return;
        }
        int mid = l + r >> 1;
        build(l, mid, p << 1);
        build(mid + 1, r, p << 1|1);
        tr[p] = max(tr[p << 1], tr[p << 1|1]);
    };
    function<ll(int,int,int,int,int)> query = [&](int l, int r, int cl, int cr, int p) -> ll{
        if(cl > cr) return 0;
        if(cl <= l && r <= cr) return tr[p];
        int mid = l + r >> 1;
        ll res = 0;
        if(mid >= cl) res = query(l, mid, cl, cr, p << 1);
        if(mid < cr) res = max(res, query(mid + 1, r, cl, cr, p << 1|1));
        return res;
    };
    build(1, n - 1, 1);
    while(t --){
        int x, y;
        cin >> x >> y;
        y --;
        cout << query(1, n - 1, x, y, 1) << ' ';
    }
    cout << endl;
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