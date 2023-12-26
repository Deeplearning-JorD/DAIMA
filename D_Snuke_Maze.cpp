/*
 * @Author: JorD
 * @LastEditTime: 2023-07-04 05:54:15
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
const string mb = "snuke";
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> f(n + 1, vector<char> (m + 1));
    rep(i, 1, n) rep(j, 1, m) cin >> f[i][j];
    vector<vector<int>> dp(n + 1, vector<int> (m + 1));
    queue<pair<int,int>> q;
    q.push({1, 0});
    int d = 1;
    while(q.size()){
        auto [x, y] = q.front(); q.pop();
        int now = dp[x][y]%5;
        for(int i = 0;i < 4;i ++){
            int sx = x + dx[i], sy = y + dy[i];
            if(sx >= 1 && sx <= n && sy >= 1 && sy <= m && mb[now] == f[sx][sy] && !dp[sx][sy]){
                dp[sx][sy] = dp[x][y] + 1;
                q.push({sx, sy});
            }
        }
    }
    if(dp[n][m]){
        cout << "Yes";
    }else cout << "No\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}