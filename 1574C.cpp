/*
 * @Author: JorD
 * @LastEditTime: 2022-11-23 14:47:28
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
    ll sum = accumulate(all(a),0ll);
    sort(all1(a));
    int t;
    cin >> t;
    while(t --){
        ll x, y;
        cin >> x >> y;
        int l = 1, r = n;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(a[mid] <= x)  l = mid;
            else r = mid - 1;
        }
        ll res = max(0ll, x - a[l]) + max(0ll, y - (sum - a[l]));
        if(l != n) l ++,res = min(res, max(0ll, x - a[l]) + max(0ll, y - (sum - a[l])));
        cout << res << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}