/*
 * @Author: JorD
 * @LastEditTime: 2023-01-25 23:08:07
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
    vector<int> idx(n + 1);
    rep(i, 1, n){
        int x; cin >> x;
        idx[x] ++;
    }
    priority_queue<ll> q, qq;
    rep(i, 1, n) if(idx[i]) q.push(idx[i]);
    rep(i, 1, m){
        int x; cin >> x;
        qq.push(x);
    }
    ll res = 0;
    while(qq.size() && q.size()){
        auto t = qq.top(); qq.pop();
        auto tt = q.top(); q.pop();
        res += min(t, tt);
        if(tt > t){
            q.push(tt - t);
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