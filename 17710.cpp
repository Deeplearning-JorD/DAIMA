/*
 * @Author: JorD
 * @LastEditTime: 2022-12-11 23:52:11
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
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    vector<ll> s(2e6);
    map<ll,ll> q;
    rep(i, 1, n){
        cin >> a[i];
        q[a[i]] ++;
        s[a[i]] ++;
    }
    sort(all1(a));
    ll mx = a.back() - a[1];
    ll res = 0;
    if(mx == 0){
        cout << n * (n - 1) << endl;
        return;
    }
    for(auto [x, y]:q){
        res += y * s[x + mx];
        if(x - mx > 0){
            res += y * s[x - mx];
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