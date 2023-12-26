/*
 * @Author: JorD
 * @LastEditTime: 2023-03-11 20:12:45
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
ll res = 0;
set<int> s;
int n, m;
int f[15][15];
void dfs(int x, int y){
    if(x == n && y == m){
        if(s.size() == n + m - 1) res ++;
        return;
    }
    if(x + 1 <= n && !s.count(f[x + 1][y])){
        s.insert(f[x + 1][y]);
        dfs(x + 1, y);
        s.erase(f[x + 1][y]);
    }
    if(y + 1 <= m && !s.count(f[x][y + 1])){
        s.insert(f[x][y + 1]);
        dfs(x, y + 1);
        s.erase(f[x][y + 1]);
    }
}
void Solve(){
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >> f[i][j];
    s.insert(f[1][1]);
    dfs(1, 1);
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}