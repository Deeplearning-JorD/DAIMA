/*
 * @Author: JorD
 * @LastEditTime: 2023-07-30 01:00:16
 * how to Get
 */
#pragma GCC optimize(2)
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
    int n; cin >> n;
    vector<ll> b(n + 1), c(n + 1);
    vector<pair<ll,ll>> a(n + 1);
    vector<pair<ll,ll>> resl,resr;
    rep(i, 1, n){
        cin >> b[i];
        a[i] = {b[i], i};
        c[i] = b[i];
    }
    sort(a.begin() + 1, a.end());
    
    while(abs(b[a[1].second]) > abs(b[a[n].second]) && a[n].first != 0){
        b[a[n].second] += b[a[n].second];
        resl.push_back({a[n].second, a[n].second});
    }
    rep(i, 1, n) if(b[i] < 0) resl.push_back({i, a[n].second});
    rep(i, 1, n - 1){
        resl.push_back({i + 1, i});
    }
    while(abs(c[a[1].second]) < abs(c[a[n].second]) && a[1].first != 0){
        c[a[1].second] += c[a[1].second];
        resr.push_back({a[1].second, a[1].second});
    }
    rep(i, 1, n) if(c[i] > 0) resr.push_back({i, a[1].second});
    per(i, n, 2){
        resr.push_back({i - 1, i});
    }
    if(resl.size() > resr.size()) swap(resl,resr);
    if(resl.empty()){
        cout << 0 << endl;
        return;
    }
    cout << resl.size() << endl;
    for(auto [x, y] : resl) cout << x << ' ' << y << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}