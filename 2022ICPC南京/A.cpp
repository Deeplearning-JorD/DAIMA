/*
 * @Author: JorD
 * @Date: 2023-11-20 19:23:02
 * @LastEditTime: 2023-11-21 12:23:34
 * how to Get
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
void Solve(){
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    int x = 0, y = 0;
    int d1 = 0, d2 = 0, d3 = 0, d4 = 0; 
    vector<vector<int>> pre(2 * m + 1, vector<int> (2 * n + 1));
    for(auto c:s){
        if(c == 'U') y ++;
        else if(c == 'L') x --;
        else if(c == 'R') x ++;
        else y --;
        if(m + x > 2 * m || m + x < 0 || y + n > 2 * n || y + n < 0){
            break;
        }
        pre[x + m][y + n] = 1; 
        d1 = max(d1, y);
        d2 = min(d2, y);
        d3 = max(d3, x);
        d4 = min(d4, x);
    }
    pre[m][n] = 1;
    d1 = abs(d1);d2 = abs(d2);d3 = abs(d3);d4 = abs(d4);
    d1 = min(d1, n);d2 = min(d2, n);d3 = min(d3, m);d4 = min(d4, m);
    int xl = d4 + 1, xr = m - d3, yl = d2 + 1, yr = n - d1;
    if(xl > xr || yl > yr){
        if(k == 0) cout << n * m << endl;
        else cout << 0 << endl;
        return;
    }
    k = (xr - xl + 1) * (yr - yl + 1) - k;
    for(int i = 1;i <= 2 * m;i ++){
        for(int j = 1;j <= 2 * n;j ++)
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    }
    auto query = [&](int y, int sy, int x, int sx){
        return pre[sx][sy] - pre[sx][y - 1] - pre[x - 1][sy] + pre[x - 1][y - 1];
    };
    int res = 0;
    for(int i = 1;i <= m;i ++){
        for(int j = 1;j <= n;j ++){
            int l1 = max(1, j - yr + n), r1 = max(1, j - yl + n);
            int l2 = max(1, i - xr + m), r2 = max(1, i - xl + m);
            int now = query(l1, r1, l2, r2);
            if(now == k){
                res ++;
            }
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}