/*
 * @Author: JorD
 * @LastEditTime: 2023-06-24 22:50:39
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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<set<int>> s(n + 1);
    vector<int> dp(n + 1), sum(n + 1);
    int mx = 0;
    for(int i = 1;i <= n;i ++){
        int col = a[i];
        if(s[col].size()){
            int val = *s[col].rbegin();
            dp[i] = val - (n - i);
            dp[i] = max(dp[i], mx);
        }else{
            dp[i] = max(dp[i], mx);
        }
        mx = max(mx, dp[i]);
        s[col].insert(dp[i - 1] + n - (i - 1));
    }
    cout << mx << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}