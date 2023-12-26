/*
 * @Author: JorD
 * @LastEditTime: 2022-12-28 00:30:31
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
const int mod = 1e9 + 7;
ll qsm(ll x, ll p){
    ll res = 1;
    while(p){
        if(p & 1) res = res * x % mod;
        x *= x;
        x %= mod;
        p >>= 1;
    }
    return res;
}
void Solve(){
    ll n;
    cin >> n;
    if(n == 2){
        cout << 14154 << endl;
        return;
    }
    if(n == 3){
        cout << 44484 << endl;
        return;
    }
    ll res = 7;
    n -= 2;

    x / 2
    x * qsm(2, mod - 2)
    
    res += ((((((n * (n + 1) % mod * (2 * n + 1) % mod) % mod) * qsm(3, mod - 2)) % mod) + (1 + n) * n % mod * qsm(2, mod - 2) * 7 % mod) % mod + 6 * n % mod);
    res %= mod;
    res *= 2022;
    res %= mod;
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