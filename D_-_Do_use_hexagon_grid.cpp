/*
 * @Author: JorD
 * @LastEditTime: 2022-09-17 20:41:22
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
const int N = 2010;
int st[N][N];
bool vis[N][N];
int idx;
int dx[6] = {-1, -1, 0, 0, 1, 1};
int dy[6] = {-1, 0, -1, 1, 0, 1}; 
void dfs(int x, int y){
    if(x < 0 || y > 2000 || y < 0 || x > 2000) return;
    for(int i = 0;i < 6; i ++){
        int sx = x + dx[i], sy = y + dy[i];
        if(!vis[sx][sy]&&st[sx][sy]){
            vis[sx][sy] = true;
            dfs(sx, sy);
        } 
    }
}
void Solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> a;
    rep(i, 1, n){
        int x, y;
        cin >> x >> y;
        x += 1000;
        y += 1000;
        a.push_back({x, y});
        st[x][y] = 1;
    }
    for(auto x:a){
        if(vis[x.first][x.second]) continue;
        idx ++;
        vis[x.first][x.second] = true;
        dfs(x.first, x.second);
    }
    cout << idx << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}