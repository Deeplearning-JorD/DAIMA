/*
 * @Author: JorD
 * @LastEditTime: 2022-09-03 20:57:48
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    vector<ll> pre(n + 1);
    vector<ll> sum(n + 1);
    rep(i, 1, n){
        ll x;
        cin >> x;
        sum[i] = sum[i - 1] + x;
        a[i] = x * i;
        pre[i] = pre[i - 1] + a[i];
    }
    ll l = 0, r = m;
    ll res = -1e18;
    while(r <= n){
        res = max(res, pre[r] - pre[l] - l*(sum[r] - sum[l]));
        l ++, r ++;
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}