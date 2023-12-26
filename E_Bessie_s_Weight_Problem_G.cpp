/*
 * @Author: JorD
 * @LastEditTime: 2023-04-18 20:02:39
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
    swap(n, m);
    vector<vector<int>> dp(2, vector<int> (m + 1, - 1e9));
    // dp[i][j]表示考虑前i个，体积为j的最大价
    dp[0][0] = 0;
    for(int i = 1;i <= n;i ++){
        int x; cin >> x;
        for(int j = 0;j <= m;j ++){
            dp[i & 1][j] = dp[(i - 1) & 1][j];
            if(j >= x && dp[(i - 1) & 1][j - x] != - 1e9)
            dp[i & 1][j] = max(dp[(i - 1) & 1][j - x] + x, dp[i & 1][j]);        
        }
    }
    for(int i = m;i >= 0;i --){
        if(dp[n & 1][i] != -1e9){
            cout << i << endl;
            break;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --
    Solve();
    return 0;
}