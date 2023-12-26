/*
 * @Author: JorD
 * @LastEditTime: 2023-07-08 19:34:08
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
set<ll> s;
void Solve(){
    ll x; cin >> x;
    if(s.count(x)) cout << "YES\n";
    else{
        ll l = 2, r = 1e9;
        while(l < r){
            ll mid = l + r >> 1;
            if(1 + mid + mid * mid >= x) r = mid;
            else l = mid + 1;
        }
        if(1 + r + r * r == x) cout << "YES\n";
        else cout << "NO\n";
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    rep(i, 2, 1000000){
        ll now = i * i;
        ll sum = 1 + i + i * i;
        while(1){
            s.insert(sum);
            if(now > 1e18 / i) break;
            now *= i;
            sum += now;
        }
    }
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}