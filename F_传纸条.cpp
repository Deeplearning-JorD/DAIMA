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
const int N = 55;
int dp[N][N][N][N];
// dp[i][j][x][y]表示从左上角开始走，现在走到了i,j和想x,y点的最大好感度
int a[N][N];
bool st[N][N][N][N];
int n, m;
int dx[2] = {1, 0};
int dy[2] = {0, 1};
bool check(int x, int y, int sx, int sy){
    if(x > n || sx > n || y > m || sy > m) return true;
    if(x == sx && y == sy) return true;
    return false;
}
struct node{
    int x, y, sx, sy;
};
void dfs(){
    queue<node> q;
    q.push({1, 1, 1, 1});
    while(q.size()){
        auto [x, y, sx, sy] = q.front(); q.pop();
        for(int i = 0;i < 2;i ++){
            int newx = x + dx[i], newy = y + dy[i];
            for(int j = 0;j < 2;j ++){
                int newsx = sx + dx[j], newsy = sy + dy[j];
                if(check(newx, newy, newsx, newsy)) continue;
                auto &now = dp[newx][newy][newsx][newsy];
                auto &last = dp[x][y][sx][sy];
                now = max(now, last + a[newx][newy] + a[newsx][newsy]);
                if(!st[newx][newy][newsx][newsy]){
                    st[newx][newy][newsx][newsy] = 1;
                    q.push({newx, newy, newsx, newsy});
                }
            }    
        }
    }
}
void Solve(){
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
    dfs();
    cout << dp[n - 1][m][n][m - 1];
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}