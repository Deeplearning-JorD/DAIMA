/*
 * @Author: JorD
 * @Date: 2023-11-17 22:38:43
 * @LastEditTime: 2023-11-17 22:43:49
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
    ll n; cin >> n;
    vector<ll> pre(n + 1);
    rep(i, 1, n){
        ll x; cin >> x;
        pre[i] = pre[i - 1] + x;
    }
    ll res = 0;
    for(int i = 1;i <= n;i ++)if(n % i == 0){
        vector<ll> v;
        for(int l = 0, r = i;r <= n;l += i, r += i){
            v.push_back(pre[r] - pre[l]);
        }
        sort(v.begin(), v.end());
        res = max(res, *v.rbegin() - *v.begin());
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