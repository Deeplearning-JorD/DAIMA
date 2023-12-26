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
    vector<vector<int>> f(m + 1, vector<int> (n + 1));
    rep(i, 1, n){
        rep(j, 1, m){
            cin >> f[j][i];
        }
    }
    ll res = 0;
    rep(i, 1, m) sort(f[i].begin() + 1, f[i].end());
    for(int i = 1;i <= m;i ++){
        vector<int> d(n + 1);
        ll pre = 0;
        for(int j = 2, l = n - 1;j <= n;j ++, l --){
            ll c = f[i][j] - f[i][j - 1];
            res += abs(c) * 1ll * (n - j + 1) * (j - 1);
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