/*
 * @Author: JorD
 * @LastEditTime: 2022-09-23 20:15:06
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
    int n;
    cin >> n;
    vector<ll> a(n + 1, -1e9);
    rep(i, 1, n) cin >> a[i];
    sort(a.begin(),a.end());
    ll res = 1e9;
    rep(i, 1, n){
        if(i + 2 > n) break;
        ll x = a[i], y = a[i + 1], z = a[i + 2];
        ll sum = x + y + z;
        sum /= 3;
        sum --;
        for(int j = 1;j <= 5;j ++, sum ++)
        if(sum > 0)
        res = min(res, abs(sum - x) + abs(sum - y) + abs(sum - z));
        sum = x;
        res = min(res, abs(sum - x) + abs(sum - y) + abs(sum - z));
        sum = y;
        res = min(res, abs(sum - x) + abs(sum - y) + abs(sum - z));
        sum = z;
        res = min(res, abs(sum - x) + abs(sum - y) + abs(sum - z));
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}