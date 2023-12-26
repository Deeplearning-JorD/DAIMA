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
int dp[2][2][81][85 * 85];
int g[100][100];
void upd(int &x, int y){
    x = min(x, y);
}
void Solve(){
    int n, m;
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    memset(dp, 0x3f, sizeof dp);
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        g[x][y] = 1; 
    }
    rep(i, 1, n) g[i][i] = 0;
    rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) 
    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    cin >> m;
    int x; cin >> x;
    dp[0][0][1][g[1][x]] = 0;
    dp[0][1][1][0] = g[1][x];
    int st = 0;
    int last = x;
    rep(i, 2, m){
        int x; cin >> x;
        int l = st, r = st ^ 1;
        for(int p = 1;p <= n;p ++){
            for(int j = 0;j <= n * m;j ++){
                // dp[l][0][p][j] 
                // A: last, B: p;
                upd(dp[r][0][p][j + g[last][x]], dp[l][0][p][j]);
                upd(dp[r][1][last][j], dp[l][0][p][j] + g[p][x]);
                // dp[l][1][p][j]
                // A: p, B: last
                upd(dp[r][0][last][j + g[p][x]], dp[l][1][p][j]);
                upd(dp[r][1][p][j], dp[l][1][p][j] + g[last][x]);   
                dp[l][0][p][j] = dp[l][1][p][j] = 0x3f3f3f3f;
            }
        }
        st ^= 1;
        last = x;
    }
    int res = 1e9;
    for(int i = 0;i < 2;i ++){
        for(int p = 1;p <= n;p ++){
            for(int j = 0;j <= n * m;j ++)
                res = min(res, max(j, dp[st][i][p][j]));
        }
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