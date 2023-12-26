/*
 * @Author: JorD
 * @Date: 2023-11-21 18:10:17
 * @LastEditTime: 2023-11-21 18:15:26
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
    int n, k; cin >> n >> k;
    vector<int> a(n + 1), dp(n + 1);
    rep(i, 1, n) cin >> a[i];
    sort(a.begin() + 1, a.end());
    int id = 0;
    a[0] = -k;
    int mx = 0;
    for(int i = 1;i <= n;i ++){
        while(id < i && a[id] + k <= a[i]){
            mx = max(mx, dp[id]);
            id ++;
        }
        dp[i] = mx + 1;
    }
    cout << *max_element(dp.begin() + 1, dp.end());
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}