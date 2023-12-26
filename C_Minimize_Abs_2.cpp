/*
 * @Author: JorD
 * @Date: 2023-11-25 20:12:21
 * @LastEditTime: 2023-11-25 20:22:23
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
    ll d; cin >> d;
    ll res = 1e18;
    for(ll i = 0;i <= 2e6;i ++){
        ll l = 0, r = 2e6;
        while(l < r){
            ll mid = l + r + 1 >> 1;
            if(i * i + mid * mid <= d) l = mid;
            else r = mid - 1;
        }
        res = min(res, abs(d - i * i - r * r));
        l = 0, r = 2e6;
        while(l < r){
            ll mid = l + r >> 1;
            if(i * i + mid * mid >= d) r = mid;
            else l = mid + 1;
        }
        res = min(res, abs(d - i * i - r * r));
    }
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}