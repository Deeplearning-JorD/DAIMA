/*
 * @Author: JorD
 * @LastEditTime: 2022-12-31 00:42:26
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
    int n, m;
    cin >> n >> m;
    priority_queue<int,vector<int>,greater<int>> q;
    rep(i, 1, n){
        int x; cin >> x;
        q.push(x);
    }
    rep(i, 1, m){
        int x; cin >> x;
        auto t = q.top(); q.pop();
        q.push(x);
    }
    ll res = 0;
    while(q.size()){
        auto t = q.top(); q.pop();
        res += t;
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