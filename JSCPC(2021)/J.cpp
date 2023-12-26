/*
 * @Author: JorD
 * @LastEditTime: 2022-12-02 00:30:21
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
const int N = 510;
int n, m;
int f[N][N];
int col[N][N];
bool st[N][N];
vector<vector<pair<int,int>>> res;
int gs;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void bfs(int xx, int yy){
    queue<pair<int,int>> q;
    q.push({xx, yy});
    int cnt = 0;
    vector<pair<int,int>> no, yes;
    st[xx][yy] = true;
    no.push_back({xx, yy});
    while(q.size()){
        auto [sx, sy] = q.front(); q.pop();
        for(int i = 0;i < 4;i ++){
            int x = sx + dx[i], y = sy + dy[i];
            if(x < 1 || x > n || y < 1 || y > m || st[x][y] || f[x][y] != f[sx][sy]) continue;
            if(col[sx][sy]){
                no.push_back({x, y});
                st[x][y] = true;
            }else{
                col[x][y] = 1;
                st[x][y] = true;
                yes.push_back({x, y});
            }
            q.push({x, y});
        }
    }
    if(siz(no) < siz(yes)) res.push_back(no);
    else res.push_back(yes);
    gs += min(siz(no), siz(yes));
}
void Solve(){
    cin >> n >> m;
    rep(i, 1, n)rep(j, 1, m) cin >> f[i][j];
    rep(i, 1, n)rep(j ,1, m)if(!st[i][j]){
        bfs(i, j);
    }
    if(gs) cout << 1 << ' ';
    else cout  << 0 << ' ';
    cout << gs << endl;
    for(auto u:res){
        for(auto [x, y]:u){
            cout << x << ' ' << y << ' ' << 1 << endl;
        }
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