/*
 * @Author: JorD
 * @Date: 2023-11-21 18:16:18
 * @LastEditTime: 2023-11-22 23:54:34
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
    ll p, q; cin >> p >> q;
    ll d = __gcd(p, q);
    p /= d;
    q /= d;
    ll delta = p * p - 4 * q * q;
    if(delta < 0){
        cout << "0 0\n";
        return;
    }
    ll c = sqrt(delta);
    if(c * c != delta){
        cout << "0 0\n";
        return;
    }
    ll resl, resr;
    auto check = [&](ll k){
        ll d = __gcd(2 * q, k);
        resr = k / d;
        resl = 2 * q / d;
        if(resr <= 1e9 && resl <= 1e9 && resl >= 1 && resr >= 1){
            return true;
        }
        return false;
    };
    // __int128 w;
    if(check(c + p)){
        cout << resl << ' ' << resr << endl;
        return;
    }
    if(check(p - c)){
        cout << resl << ' ' << resr << endl;
        return;
    }
    cout << 0 << ' ' << 0 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}