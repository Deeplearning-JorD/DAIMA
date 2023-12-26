/*
 * @Author: JorD
 * @LastEditTime: 2022-12-26 17:04:51
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
double get(pair<double,double> a, pair<double,double> b){
    auto [x, y] = a;
    auto [sx, sy] = b;
    return sqrt((x - sx) * (x - sx) + (y - sy) * (y - sy));
}
const int N = 155;
int f[N];
int find(int x){
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];
}
void Solve(){
    int n;
    cin >> n;
    vector<pair<double,double>> a(n + 1);
    vector<vector<double>> g(n + 1, vector<double> (n + 1, 1e9));
    rep(i, 1, n) f[i] = i;
    rep(i, 1, n){
        auto &[x, y] = a[i];
        cin >> x >> y;
        g[i][i] = 0;
    }
    rep(i, 1, n){
        string s;
        cin >> s;
        s = ' ' + s;
        rep(j, 1, n){
            if(s[j] == '1'){
                g[i][j] = g[j][i] = get(a[i], a[j]);
                int x = find(i), y = find(j);
                if(y != j) f[x] = y;
                else f[y] = x;
            } 
        }
    }
    vector<double> dist(n + 1);
    vector<double> mx(n + 1);
    rep(k, 1, n)
    rep(i, 1, n)
    rep(j, 1, n)
    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    double res = 1e9;
    rep(i, 1, n)
    rep(j, 1, n)
    if(find(i) == find(j)){
    dist[i] = max(dist[i], g[i][j]);
    mx[find(i)] = max(mx[find(i)], dist[i]);
    }
    rep(i, 1, n)
    rep(j, 1, n)
    if(find(i) != find(j))
    res = min(res, max({mx[find(i)], mx[find(j)], dist[i] + dist[j] + get(a[i], a[j])}));
    sort(dist.begin(), dist.end());
    cout << SPO(6) << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    
    return 0;
}