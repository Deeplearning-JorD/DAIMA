/*
 * @Author: JorD
 * @Date: 2023-11-17 20:26:46
 * @LastEditTime: 2023-11-24 12:55:02
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
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
const int N = 310, M = 2010;
double dist[N][N];
double dp[M][M][2];
void Solve(){
    memset(dist, 127, sizeof dist);
    int n, m, v, e;
    cin >> n >> m >> v >> e;
    rep(i, 1, v) dist[i][i] = 0;
    vector<int> c(n + 1), d(n + 1);
    vector<double> p(n + 1);
    rep(i, 1, n) cin >> c[i];
    rep(i, 1, n) cin >> d[i];
    rep(i, 1, n) cin >> p[i];
    rep(i, 1, e){
        int x, y; double w; cin >> x >> y >> w;
        dist[x][y] = min(dist[x][y], w);
        dist[y][x] = min(dist[y][x], w);   
    }
    rep(k,1,v)rep(i,1,v)rep(j,1,v)
    dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
    memset(dp, 127, sizeof dp);
    dp[1][0][0]=0;
    dp[1][1][1]=0;
    rep(i, 2, n){
        dp[i][0][0] = dp[i - 1][0][0] + dist[c[i-1]][c[i]];
        for(int j = 1;j <= m;j ++){
            dp[i][j][0] = min(dp[i - 1][j][0] + dist[c[i-1]][c[i]],
                              dp[i - 1][j][1] + dist[c[i-1]][c[i]] * (1-p[i-1]) + dist[d[i-1]][c[i]] * p[i-1]);  
            dp[i][j][1] = min(dp[i - 1][j - 1][0] + dist[c[i-1]][c[i]] * (1-p[i]) + dist[c[i-1]][d[i]] * p[i],
                              dp[i - 1][j - 1][1] + dist[c[i-1]][c[i]] * (1-p[i-1])*(1-p[i]) + dist[c[i-1]][d[i]] * (1-p[i-1]) * p[i] + dist[d[i-1]][c[i]] * p[i-1] * (1-p[i]) + dist[d[i-1]][d[i]] * p[i-1] * p[i]);
        }
    }
    double res = 1e18;
    rep(i, 0, m) res = min({res, dp[n][i][0], dp[n][i][1]});
    cout << SPO(2) << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}