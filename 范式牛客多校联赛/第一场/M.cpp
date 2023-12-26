/*
 * @Author: JorD
 * @LastEditTime: 2023-07-20 23:43:30
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
    ll a, b, k;
    cin >> a >> b >> k;
    ll x, y;
    ll d = exgcd(a, b, x, y);
    ll res = 1e18;
    if(k % d) cout << -1 << endl;
    else{
        a /= d;
        b /= d;
        k /= d;
        x *= k; y *= k;
        ll mid = x / b;
        // x - x / b * b 其实等价于 
        // 其实就是最小整数特解 x = (x % b + b) % b
        // 其中b = b / gcd(a, b)
        for(ll i = mid - 10;i <= mid + 10;i ++){
            ll nowx = x - i * b;
            ll nowy = y + i * a;
            ll w = abs(nowx) + abs(nowy);
            w *= 2;
            if(nowx < 0 || nowy < 0) w --;
            res = min(res, w);
        }
        cout << res << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}