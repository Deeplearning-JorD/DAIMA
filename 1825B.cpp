/*
 * @Author: JorD
 * @LastEditTime: 2023-05-08 21:31:02
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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n * m + 1);
    rep(i, 1, n * m) cin >> a[i];
    vector<ll> v;
    sort(a.begin() + 1, a.end());
    v.push_back(a[1]);
    v.push_back(a[2]);
    v.push_back(a[n * m]);
    v.push_back(a[n * m - 1]);
    ll res = 0;
    sort(v.begin(), v.end());
    ll c1 = 0, c2 = 0, c3;
    c1 = v[0], c2 = v[2], c3 = v[3];
    ll w = max((max(c1, c2) - min(c1, c2)), (max(c1, c3) - min(c1, c3))) * (n - 1) * (m - 1);
    w += (max(c1, c2) - min(c1, c2)) * (n - 1);
    w += (max(c1, c3) - min(c1, c3)) * (m - 1);
    res = max(res, w);
    swap(c2, c3);
    w = max((max(c1, c2) - min(c1, c2)), (max(c1, c3) - min(c1, c3))) * (n - 1) * (m - 1);
    w += (max(c1, c2) - min(c1, c2)) * (n - 1);
    w += (max(c1, c3) - min(c1, c3)) * (m - 1);
    res = max(res, w);
    c1 = v[3], c2 = v[0], c3 = v[1];
    w = max((max(c1, c2) - min(c1, c2)), (max(c1, c3) - min(c1, c3))) * (n - 1) * (m - 1);
    w += (max(c1, c2) - min(c1, c2)) * (n - 1);
    w += (max(c1, c3) - min(c1, c3)) * (m - 1);
    res = max(res, w);
    swap(c2, c3);
    w = max((max(c1, c2) - min(c1, c2)), (max(c1, c3) - min(c1, c3))) * (n - 1) * (m - 1);
    w += (max(c1, c2) - min(c1, c2)) * (n - 1);
    w += (max(c1, c3) - min(c1, c3)) * (m - 1);
    res = max(res, w);
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