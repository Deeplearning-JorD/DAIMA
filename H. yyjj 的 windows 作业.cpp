/*
 * @Author: JorD
 * @LastEditTime: 2023-05-04 01:44:06
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
struct node{
    int x, y, t;
};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ddx[4] = {2, 0, -2, 0};
int ddy[4] = {0, 2, 0, -2};
void Solve(){   
    int n, m;
    cin >> n >> m;
    vector<vector<char>> f(n + 1, vector<char> (m + 1));
    rep(i, 1, n) rep(j, 1, m) cin >> f[i][j];
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (m + 1, vector<int> (3)));
    // dp[i][j][0/1/2]分别表示在i,j这个位置积木有没有到达以及状态
    dp[1][1][0] = 1;
    queue<node> q;
    q.push({1, 1, 0});
    while(q.size()){
        auto [x, y, k] = q.front(); q.pop();
        if(k == 0){
            for(int i = 0;i < 4;i ++){
                int sx = x + dx[i], sy = y + dy[i];
                int ex = x + ddx[i], ey = y + ddy[i];
                if(ex < 1 || ex > n || ey < 1 || ey > m) continue;
                if(f[sx][sy] == '0' || f[ex][ey] == '0') continue;
                if(dx[i]){
                    if(dx[i] == 1 && dp[ex][ey][2]) continue;
                    if(dx[i] == -1 && dp[sx][ey][2]) continue;
                    if(dx[i] == 1){
                        dp[ex][ey][2] = 1;
                        q.push({ex, ey, 2});
                    }else{
                        dp[sx][ey][2] = 1;
                        q.push({sx, ey, 2});
                    }
                }else{
                    if(dy[i] == 1 && dp[ex][ey][1]) continue;
                    if(dy[i] == -1 && dp[ex][sy][1]) continue;
                    if(dy[i] == 1){
                        dp[ex][ey][1] = 1;
                        q.push({ex, ey, 1});
                    }else{
                        dp[ex][sy][1] = 1;
                        q.push({ex, sy, 1});
                    }
                }
            }
        }else if(k == 1){
            if(y + 1 <= m && f[x][y + 1] != '0' && !dp[x][y + 1][0]){
                dp[x][y + 1][0] = 1;
                q.push({x, y + 1, 0});
            }
            if(y - 2 >= 1 && f[x][y - 2] != '0' && !dp[x][y - 2][0]){
                dp[x][y - 2][0] = 1;
                q.push({x, y - 2, 0});
            }
            if(x - 1 >= 1 && f[x - 1][y - 1] != '0' && f[x - 1][y] != '0' && !dp[x - 1][y][1]){
                dp[x - 1][y][1] = 1;
                q.push({x - 1, y, 1});
            }
            if(x + 1 <= n && f[x + 1][y - 1] != '0' && f[x + 1][y] != '0' && !dp[x + 1][y][1]){
                dp[x + 1][y][1] = 1;
                q.push({x + 1, y, 1});
            }
        }else{
            if(x + 1 <= n && f[x + 1][y] != '0' && !dp[x + 1][y][0]){
                dp[x + 1][y][0] = 1;
                q.push({x + 1, y, 0});
            }
            if(x - 2 >= 1 && f[x - 2][y] != '0' && !dp[x - 2][y][0]){
                dp[x - 2][y][0] = 1;
                q.push({x - 2, y, 0});
            }
            if(y - 1 >= 1 && f[x - 1][y - 1] != '0' && f[x][y - 1] != '0' && !dp[x][y - 1][2]){
                dp[x][y - 1][2] = 1;
                q.push({x, y - 1, 2});
            }
            if(y + 1 <= m && f[x - 1][y + 1] != '0' && f[x][y + 1] != '0' && !dp[x][y + 1][2]){
                dp[x][y + 1][2] = 1;
                q.push({x, y + 1, 2});
            }
        }
    }
    rep(i, 1, n) rep(j, 1, m) rep(k, 0, 2)if(dp[i][j][k]){
        if(k == 0) f[i][j] = '2';
        else if(k == 1){
            f[i][j] = f[i][j - 1] = '2';
        }else f[i][j] = f[i - 1][j] = '2';
    }
    int res = 0;
    rep(i, 1, n) rep(j, 1, m) res += f[i][j] == '2';
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); //cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}