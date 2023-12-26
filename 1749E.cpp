/*
 * @Author: JorD
 * @LastEditTime: 2022-10-22 14:16:24
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
    vector<vector<char>> f(n + 1, vector<char> (m + 1));
    rep(i, 1, n) rep(j, 1, m) cin >> f[i][j];
    auto check = [&](int x, int y){
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1}; 
        rep(i, 0, 3){
            int sx = x + dx[i], sy = y + dy[i];
            if(sx < 1||sx > n||sy < 1||sy > m) continue;
            if(f[sx][sy] == '#') return false; 
        }
        return true;
    };
    deque<pair<int,int>> q;
    vector<vector<int>> dist(n + 1, vector<int> (m + 1));
    vector<vector<bool>> vis(n + 1, vector<bool> (m + 1));
    rep(i, 1, n){
        if(f[i][1] == '#'){
            dist[i][1] = 0;
            vis[i][1] = true;
            q.push_front({i, 1});
        }else if(check(i, 1)){
            dist[i][1] = 1;
            vis[i][1] = true;
            q.push_back({i, 1});
        }
    }
    int dx[4] = {1,-1,1,-1};
    int dy[4] = {1,1,-1,-1};
    vector<vector<pair<int,int>>> pre(n + 1, vector<pair<int, int>> (m + 1, {-1, -1}));
    while(q.size()){
        auto t = q.front(); q.pop_front();
        rep(i, 0, 3){
            int sx = t.first + dx[i], sy = t.second + dy[i];
            if(sx < 1||sx > n||sy < 1||sy > m||!check(sx, sy)||vis[sx][sy]) continue;
            if(f[sx][sy] == '#'){
                dist[sx][sy] = dist[t.first][t.second];
                q.push_front({sx, sy});
            }else{
                dist[sx][sy] = dist[t.first][t.second] + 1;
                q.push_back({sx, sy});
            }
            vis[sx][sy] = true;
            pre[sx][sy] = t;
        }    
    }
    int mx = 1e9, id = -1;
    rep(i, 1, n){
        if(vis[i][m] && dist[i][m] < mx){
            id = i;
            mx = dist[i][m];
        }
    }
    if(id == -1){
        cout << "NO\n";
        return;
    }   
    cout << "YES\n";
    pair<int,int> now = {id, m}, zero = {-1, -1};
    while(now != zero){
        f[now.first][now.second] = '#';
        now = pre[now.first][now.second];
    }
    rep(i, 1, n){
        rep(j, 1, m){
            cout << f[i][j];
        }
        cout << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}