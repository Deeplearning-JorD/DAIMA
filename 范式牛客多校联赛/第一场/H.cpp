/*
 * @Author: JorD
 * @LastEditTime: 2023-07-19 09:43:27
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
    vector<ll> a(n + 1), b(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    ll res = 0;
    rep(i, 1, n){
        res += abs(a[i] - b[i]);
    }
    ll d = 0;
    vector<pair<ll,ll>> v1, v2;
    rep(i, 1, n){
        if(a[i] < b[i]) v1.push_back({a[i], b[i]});
        else v2.push_back({b[i], a[i]});
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    ll idx = 0;
    ll n1 = v1.size(), n2 = v2.size(), r = - 2e18;
    for(auto [x, y]:v1){
        while(idx < n2 && v2[idx].first <= x){
            r = max(r, v2[idx].second);
            idx ++;
        }
        d = max(d, min(y, r) - x);
    }
    idx = 0; r = - 2e18;
    for(auto [x, y]:v2){
        while(idx < n1 && v1[idx].first <= x){
            r = max(r, v1[idx].second);
            idx ++;
        }
        d = max(d, min(y, r) - x);
    }
    cout << res - d * 2ll << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}