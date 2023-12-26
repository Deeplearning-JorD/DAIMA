/*
 * @Author: JorD
 * @LastEditTime: 2022-12-22 23:07:07
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
const int N = 15;
int g[N][N][N][N];
int st[N][N];
bool vis[N][N][1 << N];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
struct node{
    int x, y, dist, state;
};
void Solve(){
    int n, m, p;
    cin >> n >> m >> p;
    int k;
    cin >> k;
    memset(g, -1, sizeof g);
    while(k --){
        int x1, y1, x2, y2, G;
        cin >> x1 >> y1 >> x2 >> y2 >> G;
        g[x1][y1][x2][y2] = G;
        g[x2][y2][x1][y1] = G;
    }
    cin >> k;
    while(k --){
        int x, y, G;
        cin >> x >> y >> G;
        st[x][y] |= 1 << G;
    }
    queue<node> q;
    vis[1][1][st[1][1]] = true;
    q.push({1, 1, 0, st[1][1]});
    while(q.size()){
        auto [sx, sy, last, t] = q.front(); q.pop();
        if(sx == n && sy == m){
            cout << last << endl;
            return;
        }
        for(int i = 0;i < 4;i ++){
            int x = sx + dx[i], y = sy + dy[i], dist = last + 1;
            if(x < 1 || y < 1 || x > n || y > m) continue;
            if(g[x][y][sx][sy] == 0 || vis[x][y][t | st[x][y]]) continue;
            if(g[x][y][sx][sy] > 0){
                if((1 << g[x][y][sx][sy]) & t){
                    vis[x][y][t | st[x][y]] = true;
                    q.push({x, y, dist, t | st[x][y]});
                }
            }else{
                vis[x][y][t | st[x][y]] = true; 
                q.push({x, y, dist, t | st[x][y]});
            }
        }
    }
    cout << -1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}