/*
 * @Author: JorD
 * @Date: 2023-11-07 18:11:42
 * @LastEditTime: 2023-11-07 23:52:43
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
    ll sum = 0, res = 0;
    rep(i, 1, n){
        ll x; cin >> x;
        ll now = sum, t = 0, y = x;
        while(now || x){
            t = (now % 10) + (x % 10) + t >= 10;
            res += t;
            now /= 10;
            x /= 10;
        }
        sum += y;
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