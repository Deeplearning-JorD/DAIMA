/*
 * @Author: JorD
 * @LastEditTime: 2023-03-22 14:04:57
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
    map<ll,ll>q;
    int n,k,s;
    cin >> n >> k >> s;
    while(s --){
        ll x, y;
        cin >> x >> y;
        q[x] += y;
    }
    ll res = 0;
    rep(i, 1, n){
        res += q[i] < k;
    }cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}