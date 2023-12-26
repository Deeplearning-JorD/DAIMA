/*
 * @Author: JorD
 * @LastEditTime: 2023-09-09 01:04:03
 * how to Get
 */
#pragma GCC optimize(2)
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
const int N = 2e5 + 10;
void Solve(){
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> h(n + 1), T(n + 1);
    rep(i, 1, n) cin >> h[i];
    auto need = h;
    vector<int> d(n + 1);
    vector<vector<int>> son(n + 1);
    while(m --){
        int x, y; cin >> x >> y;
        d[y] ++;
        son[x].push_back(y);
    }
    queue<pair<ll,ll>> q;
    rep(i, 1, n)if(!d[i])q.push({h[i], i});
    while(q.size()){
        auto [t, i] = q.front(); q.pop();
        for(auto x : son[i]){
            ll w = h[x];
            ll l = 0, r = 1e9;
            while(l < r){
                ll mid = l + r >> 1;
                if(w + mid * k >= t) r = mid;
                else l = mid + 1;
            }
            w += r * k;
            need[x] = max(need[x], w);
            if(-- d[x] == 0){
                q.push({need[x], x});
            }
        }
    }
    multiset<ll> s;
    vector<int> id(n + 1);
    rep(i, 1, n){
        id[i] = i;
        s.insert(need[i]);
    }
    sort(id.begin() + 1, id.end(), [&](int i, int j){
        return need[i] < need[j];
    });
    function<void(int)> update = [&](int i){
        for(auto x : son[i]){
            ll w = need[x];
            if(need[x] >= need[i]) continue;
            s.erase(s.find(need[x]));
            need[x] += k;
            s.insert(need[x]);
            update(x);
        }
    };
    ll res = *s.rbegin() - *s.begin();
    rep(i, 1, n){
        if(need[id[i]] % k != need[id[i]]) continue;
        s.erase(s.find(need[id[i]]));
        need[id[i]] += k;
        s.insert(need[id[i]]);
        update(id[i]); 
        res = min(res, *s.rbegin() - *s.begin());
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