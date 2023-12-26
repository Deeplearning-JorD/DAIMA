/*
 * @Author: JorD
 * @LastEditTime: 2022-12-28 00:19:11
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
    vector<vector<int>> a(n + 1, vector<int> (m + 1));
    rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
    auto check = [&](int mid){
        vector<vector<int>> dp(n + 1, vector<int> (m + 1));
        vector<vector<int>> r(n + 1, vector<int> (m + 1));
        vector<vector<int>> c(n + 1, vector<int> (m + 1));
        //dp[i][j]表示在(i, j)时能够构成的最大正方形
        rep(i, 1, n){
            rep(j, 1, m){
                if(a[i][j] < mid) continue;
                r[i][j] = max(1, r[i - 1][j] + 1);
                c[i][j] = max(1, c[i][j - 1] + 1);
                dp[i][j] = 1;
            }
        }
        rep(i, 1, n){
            rep(j, 1, m){
                if(a[i][j] < mid) continue;
                int w = min(c[i][j], r[i][j]);
                dp[i][j] = max(dp[i][j], min(w, dp[i - 1][j - 1] + 1));
                if(dp[i][j] >= mid) return true;
            }
        }
        return false;
    };
    auto check = [&](int mid){

    };
    int l = 1, r = 1e6;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}