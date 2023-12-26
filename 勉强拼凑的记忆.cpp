/*
 * @Author: JorD
 * @LastEditTime: 2023-01-20 15:25:50
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
    ll n;
    cin >> n;
    ll up = n + 1 >> 1;
    auto check = [&](ll x){
        ll res = n;
        res -= x / up * x;
        res -= x / up * (x % up);
        res -= x % up;
        return res >= 0;
    };
    if(n == 2){
        cout << -1 << endl;
        return;
    }
    ll l = n / 2, r = n;
    while(l < r){
        ll mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}