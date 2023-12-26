/*
 * @Author: JorD
 * @Date: 2023-12-19 23:26:01
 * @LastEditTime: 2023-12-22 14:31:47
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
    int n; cin >> n;
    vector<ll> a(n + 1), b(n + 1), id1(n + 1), id2(n + 1);
    vector<bool> st(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    ll res = - (n & 1);
    res += accumulate(a.begin() + 1, a.end(), 0ll) - accumulate(b.begin() + 1, b.end(), 0ll);
    rep(i, 1, n) id1[i] = id2[i] = i;
    sort(id1.begin() + 1, id1.end(), [&](int i, int j){
        return b[i] - a[j] > b[j] - a[i];
    });
    int l = 1, r = 1;
    for(int i = 1;i <= n;i ++)
        if(i & 1){
            res += b[id1[i]];
        }else{
            res -= a[id1[i]];
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