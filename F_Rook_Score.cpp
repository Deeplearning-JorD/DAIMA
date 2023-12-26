/*
 * @Author: JorD
 * @LastEditTime: 2023-04-30 18:36:40
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define int long long
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
    int n;
    cin >> n;
    vector<int> r(n + 1), c(n + 1);
    vector<ll> rsum(n + 1), csum(n + 1);
    int cnt = 0, idx = 0;
    map<pair<int,int>,int> q;
    map<int,int> row, cow;
    rep(i, 1, n){
        int x, y, w;
        cin >> x >> y >> w;
        q[{x, y}] = w;
        row[x] = 1;
        cow[y] = 1;
    }
    for(auto &[x, y]:row){
        r[++ idx] = x;
        y = idx;
    }
    for(auto &[x, y]:cow){
        c[++ cnt] = x;
        y = cnt;
    }
    for(auto [u, w]:q){
        auto [x, y] = u;
        rsum[row[x]] += w;
        csum[cow[y]] += w;
    }
    ll res = 0;
    for(auto [u, w]:q){
        auto [x, y] = u;
        res = max(res, csum[cow[y]] + rsum[row[x]] - w);
    }
    vector<int> id(n + 2);
    rep(i, 1, n) id[i] = i;
    sort(id.begin() + 1, id.begin() + idx + 1, [&](int i, int j){
        return csum[i] > csum[j];
    });
    rep(i, 1, cnt) res = max(res, csum[i]);
    rep(i, 1, idx) res = max(res, rsum[i]);
    for(int i = 1;i <= idx;i ++){
        for(int j = 1;j <= cnt;j ++){
            int x = r[i], y = c[id[j]];
            if(q.count({x, y})) continue;
            res = max(res, csum[id[j]] + rsum[i]);
            break;
        }
    }
    cout << res << endl;
    return;
}
signed main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}