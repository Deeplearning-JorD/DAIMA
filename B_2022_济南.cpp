/*
 * @Author: JorD
 * @Date: 2023-11-07 18:11:35
 * @LastEditTime: 2023-11-07 22:50:04
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
ll exgcd(ll a, ll b, ll &x, ll &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - a / b * y;
    return d;
}
void Solve(){
    ll n, k;
    cin >> n >> k;
    ll a = n / k, b = n / k + 1;
    ll l = k - n % k, r = k - l;
    ll x, y;
    ll d = exgcd(a, b, x, y);
    // cout << x << endl;
    b /= d;
    a /= d;
    x = (x * (n / 2) / d % b + b) % b;
    y = (y * (n / 2) / d % a + a) % a;
    if(x <= l && ((n / 2) - a * x) / b <= r && ((n / 2) - a * x) / b >= 0 && x >= 0 || y <= r && ((n / 2) - b * y) / a <= l && ((n / 2) - b * y) / a >= 0) cout << "Yes\n";
    else cout << "No\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}