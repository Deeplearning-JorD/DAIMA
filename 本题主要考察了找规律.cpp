/*
 * @Author: JorD
 * @LastEditTime: 2023-01-16 15:02:37
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
    int n, m;
    cin >> n >> m;
    vector<vector<double>> dp(n + 1, vector<double> (m + 1));
    vector<vector<bool>> st(n + 1, vector<bool> (m + 1));
    rep(j, 0, m){
        st[0][j] = true;
    }
    double res = 0;
    rep(i, 1, n){
        rep(j, 0, m)if(st[i - 1][j]){
            for(int y = 0;y <= m - j;y ++){
                st[i][j + y] = true;
                dp[i][j + y] = max(dp[i][j + y], dp[i - 1][j] + (double)(1.0 * y / (m - j)));
                res = max(res, dp[i][j + y]);
                // cout << i << ' ' << j + y << dp[i][j + y] << endl;
            }
        }
    }
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    cout << SPO(9);
    Solve();
    return 0;
}