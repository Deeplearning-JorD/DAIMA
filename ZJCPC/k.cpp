/*
 * @Author: JorD
 * @LastEditTime: 2023-04-16 23:45:33
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
const int N = 410;
int dist[N][N];
struct node{
    int a, b, c;
}e[N];
map<int,int> dp[N], slep[N], st[N];
void Solve(){
    int n, m, qq, t, s;
    cin >> n >> m >> qq >> t >> s;
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
    rep(i, 1, qq){
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = {a, b, c};
    }
    queue<pair<int,int>> q;
    q.push({1, 0});
    st[1][0] = 1;
    while(q.size()){
        auto [i, tt] = q.front(); q.pop();
        st[i][tt] = 0;
        for(int j = 1;j <= qq;j ++){
            auto [a, b, c] = e[j];
            int lasta = dp[c][b], lastb = slep[c][b];
            if(tt + dist[c][i] <= a){
                int suij = 0;
                if(dist[i][1] + dist[1][c] <= dist[i][c])
                    suij = a - (tt + dist[i][1] + dist[1][c]);
                dp[c][b] = max(dp[c][b], dp[i][tt] + 1);
                slep[c][b] = max(slep[c][b], slep[i][tt] + suij);
                if(lasta != dp[c][b] || lastb != slep[c][b]){
                    if(!st[c][b]){
                        q.push({c, b});
                        st[c][b] = 1;
                    }
                }
            }
        }
    }
    int res = 0;
    rep(i, 1, n){
        for(auto [a, b]:dp[i]){
            if(a + dist[i][1] <= t){
                if(slep[i][a] + t - a - dist[1][i] < s) continue;
                res = max(res, b);
            }
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