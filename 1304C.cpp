/*
 * @Author: JorD
 * @LastEditTime: 2023-04-30 22:42:18
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
struct node{
    int t, l, r;
    bool operator < (const node &ji)const{
        return t < ji.t;
    }
};
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<node> a(n + 1);
    rep(i, 1, n){
        auto &[t, l, r] = a[i];
        cin >> t >> l >> r;
    } 
    sort(a.begin() + 1, a.end());
    vector<vector<int>> dp(n + 1, vector<int> (2));
    // dp[i][0/1]表示延续上一个状态的上下界
    dp[0][0] = dp[0][1] = m;
    a[0].t = 0;
    rep(i, 1, n){
        auto [t, l, r] = a[i];
        int up = dp[i - 1][1], down = dp[i - 1][0];
        up += t - a[i - 1].t,  down -= t - a[i - 1].t;
        if(up < l || down > r){
            cout << "NO\n";
            return;
        }
        dp[i][0] = max(down, l);
        dp[i][1] = min(up, r);
    }
    cout << "YES\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}