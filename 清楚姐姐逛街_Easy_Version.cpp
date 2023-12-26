/*
 * @Author: JorD
 * @LastEditTime: 2023-01-30 23:34:41
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
    while(T --){   
        ll xx, yy; cin >> xx >> yy;
        xx ++, yy ++;
        vector<vector<ll>> dd(n + 1, vector<ll> (m + 1));
        queue<pair<ll,ll>> qq;
        dd[xx][yy] = 1;
        qq.push({xx, yy});
        ll bx, by;
        bool ji = false;
        ll cnt = 0;
        vector<pair<ll,ll>> ver;
        ll res = 1e9;
        while(qq.size()){
            auto [sx, sy] = qq.front(); qq.pop();
            cnt ++;
            ver.push_back({sx, sy});
            if(!dist[sx][sy]){
                res = -1;
                break;
            }
            if(f[sx][sy] == '.'){
                bx = sx, by = sy;
                break;
            }
            if(f[sx][sy] == 'U'){
                int x = sx - 1, y = sy;
                if(dd[x][y]){
                    bx = x, by = y;
                    ji = true;
                    break;
                }
                dd[x][y] = dd[sx][sy] + 1;
                qq.push({x, y});
            }else if(f[sx][sy] == 'D'){
                int x = sx + 1, y = sy;
                if(dd[x][y]){
                    bx = x, by = y;
                    ji = true;
                    break;
                }
                dd[x][y] = dd[sx][sy] + 1;
                qq.push({x, y});
            }else if(f[sx][sy] == 'L'){
                int x = sx, y = sy - 1;
                if(dd[x][y]){
                    bx = x, by = y;
                    ji = true;
                    break;
                }
                dd[x][y] = dd[sx][sy] + 1;
                qq.push({x, y});
            }else{
                int x = sx, y = sy + 1;
                if(dd[x][y]){
                    bx = x, by = y;
                    ji = true;
                    break;
                }
                dd[x][y] = dd[sx][sy] + 1;
                qq.push({x, y});
            }
        }
        if(ji){
            bool vis = false;
            int idx = 0;
            for(auto [x, y]:ver){
                if(bx == x && y == by){
                    vis = true;
                    cnt -= idx;
                }   
                if(!vis) idx ++;
                if(!dist[x][y]) continue;
                if(!vis){
                    if(dd[x][y] >= dist[x][y])
                    res = min(res, dd[x][y] - 1);
                    continue;
                }
                ll l = 0, r = 1e9;
                while(l < r){
                    ll mid = l + r >> 1;
                    if(cnt * mid + dd[x][y] >= dist[x][y]) r = mid;
                    else l = mid + 1;
                }
                res = min(res, dd[x][y] + r * cnt - 1);
            }
            if(res == 1e9) res = -1;
            cout << res << endl;
            continue;
        }
        rep(i, 1, n){
            rep(j, 1, m){
                if(!dd[i][j]||!dist[i][j]) continue;
                if(i == bx && j == by){
                    res = min(res, max(dist[i][j] - 1,dd[i][j] - 1));
                }else if(dd[i][j] >= dist[i][j]) res = min(res, dd[i][j] - 1);
            }
        }
        if(res == 1e9) res = -1;
        cout << res << endl;
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