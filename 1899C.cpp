/*
 * @Author: JorD
 * @Date: 2023-11-17 22:46:36
 * @LastEditTime: 2023-11-17 22:53:58
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
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> son(n + 1);
    int idx = 0;
    rep(i, 1, n){
        cin >> a[i];
    }
    vector<int> dp(n + 1);
    a[0] = a[1];
    for(int i = 1;i <= n;i ++){
        if((a[i] ^ a[i - 1]) & 1){
            dp[i] = max(a[i], dp[i - 1] + a[i]);
        }else dp[i] = a[i];
    }
    cout << *max_element(dp.begin() + 1, dp.end()) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}