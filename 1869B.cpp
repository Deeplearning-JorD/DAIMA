/*
 * @Author: JorD
 * @LastEditTime: 2023-09-10 22:41:43
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
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    vector<pair<ll,ll>> p(n + 1);
    rep(i, 1, n){
        cin >> p[i].first >> p[i].second;
    }
    ll dist1 = 4e9, dist2 = 4e9, dist3 = abs(p[b].first - p[a].first) + abs(p[b].second - p[a].second);
    rep(i, 1, k){
        dist1 = min(dist1, abs(p[i].first - p[a].first) + abs(p[i].second - p[a].second));
        dist2 = min(dist2, abs(p[i].first - p[b].first) + abs(p[i].second - p[b].second));
    }
    if(a <= k) dist1 = 0;
    if(b <= k) dist2 = 0;
    cout << min(dist1 + dist2, dist3) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}