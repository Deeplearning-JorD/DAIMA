/*
 * @Author: JorD
 * @LastEditTime: 2023-04-17 21:25:36
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
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (int(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 410;
int dist[N][N];
struct node{
    int a, b, c;
}e[N];
void Solve(){
    int n, m, q, t, s;
    cin >> n >> m >> q >> t >> s;
    memset(dist, 0x3f, sizeof dist);
    rep(i, 1, n) dist[i][i] = 0;
    rep(i, 1, m){
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
    }
    rep(k, 1, n)
    rep(i, 1, n)
    rep(j, 1, n)
    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    rep(i, 1, q){
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = {a, b, c};
    }
    sort(e + 1, e + 1 + q, [](node x, node y){
        return x.a < y.a;
    });
    e[0] = {0,0,1};
    vector<vector<int>> dp(q + 1, vector<int> (q + 1, -1));
    // dp[i][j]表示最后一节上了第i节课，一共上了j节课时时休息的最大时间
    dp[0][0] = 0;    
    for(int i = 1;i <= q;i ++){
        for(int j = 1;j <= i;j ++){
            for(int k = 0;k < i;k ++){
                auto [a, b, c] = e[k];
                if(b + dist[c][e[i].c] > e[i].a || dp[k][j - 1] == -1) continue;
                int w = max(0, e[i].a - b - dist[c][1] - dist[1][e[i].c]);
                dp[i][j] = max(dp[i][j], dp[k][j - 1] + w);
            }
        }
    }
    int res = 0;
    rep(i, 1, q)
    rep(j, 1, i)if(dp[i][j] != - 1){
        int w = t - e[i].b - dist[1][e[i].c];
        if(w < 0 || w + dp[i][j] < s) continue;
        res = max(res, j);
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