/*
 * @Author: JorD
 * @LastEditTime: 2023-01-18 16:20:49
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
void Solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> f(n + 1, vector<int> (4));
    vector<vector<bool>> st(n + 1, vector<bool> (4));
    vector<vector<bool>> vis(n + 1, vector<bool> (4));
    rep(i, 1, k){
        int x, y;
        cin >> x >> y;
        f[x][y] ^= 1;
    }
    function<void(int,int)> dfs1 = [&](int x, int y){
        if(x < 1 || y < 1 || y > 3 || x > n || f[x][y]) return;
        if(st[x][y]) return;
        st[x][y] = true;
        dfs1(x + 1, y);
        dfs1(x, y + 1);
        return;
    };
    function<void(int,int)> dfs2 = [&](int x, int y){
        if(x < 1 || y < 1 || y > 3 || x > n || f[x][y]) return;
        if(vis[x][y]) return;
        vis[x][y] = true;
        dfs2(x - 1, y);
        dfs2(x, y - 1);
        return;
    };
    dfs1(1, 1);
    dfs2(n, 3);
    int res = 0;
    rep(i, 1, n) rep(j, 1, 3) res += st[i][j] && vis[i][j];
    cout << max(0, res - 1) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}