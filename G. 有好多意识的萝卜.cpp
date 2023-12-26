/*
 * @Author: JorD
 * @LastEditTime: 2023-05-04 18:45:58
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
    int n;
    cin >> n;
    vector<ll> a(n + 1), w(n + 1);
    vector<int> f(n + 1);
    rep(i, 1, n) f[i] = i;
    function<int(int)> find = [&](int x){
        if(x != f[x]) f[x] = find(f[x]);
        return f[x];
    };
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> w[i];
    ll mi = *min_element(w.begin() + 1, w.end());
    rep(i, 1, n) f[find(i)] = find(a[i]);
    vector<vector<ll>> son(n + 1);
    rep(i, 1, n) son[find(i)].push_back(w[i]);
    ll res = 0;
    rep(i, 1, n)if(son[i].size()){
        sort(son[i].begin(), son[i].end());
        ll now = accumulate(son[i].begin(), son[i].end(), 0ll);
        ll L = now - son[i][0] + 1ll * (siz(son[i]) - 1) * son[i][0];
        ll R = son[i][0] + mi + siz(son[i]) * mi + now;
        res += min(L, R);
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