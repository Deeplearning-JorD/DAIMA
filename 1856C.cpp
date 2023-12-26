/*
 * @Author: JorD
 * @LastEditTime: 2023-08-05 23:26:47
 * how to Get
 */
#pragma GCC optimize(2)
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
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    // dp[i]表示i达到最高值所需要花费的最小代价
    ll res = 0;
    auto check = [&](ll mid, ll need){
        ll now = 0;
        for(int i = mid;i < n;i ++){
            if(a[i] >= need) return now <= k;
            now += need - a[i];
            need --;
        }
        if(a[n] >= need) return  now <= k;
        return false;
    };
    for(int i = 1;i <= n;i ++){
        ll l = a[i], r = 1e9;
        while(l < r){
            ll mid = l + r + 1 >> 1;
            if(check(i, mid)) l = mid;
            else r = mid - 1;
        }
        res = max(res, r);
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