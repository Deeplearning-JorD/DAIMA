/*
 * @Author: JorD
 * @LastEditTime: 2022-12-15 22:59:17
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
    vector<ll> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    ll mi = 1e18;
    rep(i, 1, n) mi = min(mi, a[i]);
    ll sum = accumulate(all(a), 0ll);
    sum = min((ll)1e18, sum);
    vector<pair<ll,ll>> res;
    rep(i, 1, n){
        ll now = 1;
        for(int j = 0;j <= 60;j ++){
            ll x = 1ll << j;
            if(x >= a[i]){
                now = x;
                break;
            }
        }
        while(a[i] < now){
            ll x = min(a[i], now - a[i]);
            res.push_back({i, x});
            a[i] += x;
        }
    }
    cout << res.size() << endl;
    for(auto [x, y]:res){
        cout << x << ' ' << y << endl;
    }
    // rep(i, 1, n) cout << a[i] << ' ';
    // cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}