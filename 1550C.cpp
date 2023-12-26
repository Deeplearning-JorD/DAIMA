/*
 * @Author: JorD
 * @LastEditTime: 2022-11-25 12:20:26
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
    ll res = n + n - 1;
    auto calc = [&](int l, int r){
        if(r > n) return false;
        vector<int> dp(r - l + 1, 1);
        vector<int> dp1(r - l + 1, 1);
        bool st = true;
        rep(i , 0, r - l){
            rep(j, 0, i - 1){
                if(a[j + l] <= a[i + l]) dp[i] = max(dp[i], dp[j] + 1);
                if(a[j + l] >= a[i + l]) dp1[i] = max(dp1[i], dp1[j] + 1);
            }
            if(dp[i] >= 3||dp1[i] >= 3) st = false;
        }
        return st;
    }; 
    rep(i, 1, n){
        res += calc(i, i + 2);
        res += calc(i, i + 3);
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