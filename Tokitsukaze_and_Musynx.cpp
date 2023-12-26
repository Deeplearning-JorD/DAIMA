/*
 * @Author: JorD
 * @LastEditTime: 2023-01-18 18:22:07
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
struct node{
    ll c, val, add;
    bool operator < (const node& ji)const{
        if(ji.add == add) return ji.c < c;
        return ji.add < add;
    }
};
void Solve(){    
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &x: arr) cin >> x;
    sort(all(arr));
    ll a, b, c, d, v1, v2, v3, v4, v5;
    cin >> a >> b >> c >> d;
    cin >> v1 >> v2 >> v3 >> v4 >> v5;
    ll res = -1e18;
    for (auto x: arr) {
        for (auto y: {a, b, c, d}) {
            ll k = x - y - 1;
            for (int t = 0; t < 3; ++t, ++k) {
                ll i1 = lower_bound(all(arr), a + k) - arr.begin();
                ll i2 = lower_bound(all(arr), b + k) - arr.begin();
                ll i3 = lower_bound(all(arr), c + k) - arr.begin();
                ll i4 = lower_bound(all(arr), d + k + 1) - arr.begin();
                res = max(res, i1 * v1 + (i2 - i1) * v2 + (i3 - i2) * v3 + (i4 - i3) * v4 + (n - i4) * v5);
            }
        }
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