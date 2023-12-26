/*
 * @Author: JorD
 * @LastEditTime: 2022-10-08 20:49:45
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> f(n + 1, vector<int> (n + 1, -1));
    queue<pair<int,int>> q;
    vector<int> dx, dy;
    rep(i, 0, n){
        rep(j, 0, n){
            if(i * i + j * j == m){
                dx.push_back(i);
                dy.push_back(j);
            }
        }
    }
    auto check = [&](int x, int y){
        return 1 <= x&&x <= n&&1 <= y&&y <= n;
    };
    q.push({1, 1});
    f[1][1] = 0;
    int idx = dx.size() - 1;
    vector<vector<bool>> vis(n + 1, vector<bool> (n + 1));
    vis[1][1] = true;
    int ddx[4] = {1,1,-1,-1};
    int ddy[4] = {1,-1,1,-1};
    while(q.size()){
        auto t = q.front(); q.pop();
        rep(i, 0, idx){
            rep(j, 0 ,3){
                int nx = dx[i] * ddx[j], ny = dy[i] * ddy[j];
                int x = t.first + nx, y = t.second + ny;
                if(!check(x, y)) continue;
                if(vis[x][y]) continue;
                vis[x][y] = true;
                f[x][y] = f[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
    }
    rep(i, 1, n){
        rep(j, 1, n){
            cout << f[i][j] << ' ';
        }
        cout << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}