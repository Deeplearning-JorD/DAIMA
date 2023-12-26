/*
 * @Author: JorD
 * @LastEditTime: 2023-01-31 16:58:21
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
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0}; 
const int N = 810;
pair<int,int> st[N][N][22];
void Solve(){
    int n, m, xs, ys, T;
    cin >> n >> m >> xs >> ys >> T;
    vector<vector<char>> f(n + 1, vector<char> (m + 1));
    rep(i, 1, n){
        rep(j, 1, m){
            cin >> f[i][j];
        }
    }
    rep(i, 1, n){
        rep(j, 1, m){
            if(f[i][j] == 'U'){
                if(f[i - 1][j] == '#') 
                f[i][j] = '.';
            }else if(f[i][j] == 'D'){
                if(f[i + 1][j] == '#') 
                f[i][j] = '.';
            }else if(f[i][j] == 'L'){
                if(f[i][j - 1] == '#') 
                f[i][j] = '.';
            }else if(f[i][j] == 'R'){
                if(f[i][j + 1] == '#') 
                f[i][j] = '.';
            }
        }
    }
    xs ++; ys ++;
    vector<vector<ll>> dist(n + 1, vector<ll> (m + 1));
    queue<pair<ll,ll>> q;
    dist[xs][ys] = 1;
    q.push({xs, ys});
    while(q.size()){
        auto [sx, sy] = q.front(); q.pop();
        for(int i = 0;i < 4;i ++){
            int x = sx + dx[i], y = sy + dy[i];
            if(f[x][y] == '#' || dist[x][y]) continue;
            dist[x][y] = dist[sx][sy] + 1;
            q.push({x, y});
        }
    }
    rep(i, 1, n) rep(j, 1, m){
        int x = i, y = j;
        if(f[i][j] == 'U') x --;
        if(f[i][j] == 'D') x ++;
        if(f[i][j] == 'L') y --;
        if(f[i][j] == 'R') y ++;
        st[i][j][0] = {x, y};
    }
    rep(k, 1, 19) rep(i, 1, n) rep(j, 1, m){
        auto [x, y] = st[i][j][k - 1];
        st[i][j][k] = st[x][y][k - 1];
    }
    auto check = [&](int x, int y, int up){
        int now = 0;
        for(int i = 19;i >= 0;i --){
            if(now + (1 << i) <= up){
                now += 1 << i;
                auto [xx, yy] = st[x][y][i];
                x = xx, y = yy;
            }
        }
        return dist[x][y] - 1 <= up;
    };
    while(T --){   
        ll xx, yy; cin >> xx >> yy;
        xx ++, yy ++;
        ll res = 0;
        if(!dist[xx][yy]){
            cout << -1 << endl;
            continue;
        }
        for(int i = 19;i >= 0;i --){
            auto [x, y] = st[xx][yy][i];
            if(dist[x][y] - 1 > res + (1 << i)){
                res += 1 << i;
                xx = x, yy = y;
            }
        }
        cout << res + 1 << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}