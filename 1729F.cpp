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
    int m, t;
    string s;
    cin >> s >> m >> t;
    int n = s.size();
    s = '0' + s;
    vector<ll> w(n - m + 2);
    vector<ll> pre(n + 1);
    ll sum = 0;
    rep(i, 1, m - 1) sum += s[i] - '0';
    rep(i, 1, n) pre[i] = pre[i - 1] + (s[i] - '0');
    int l = 1, r = m;
    for(int i = 1;r <= n;l ++, r ++, i ++){
        sum += s[r] - '0';
        w[i] = sum % 9;
        sum -= s[i] - '0';
    }
    vector<vector<ll>> qq(10);
    vector<vector<pair<ll,ll>>> q(10);
    rep(i, 1, n - m + 1){
        rep(j, 0, 8){
            ll now = (w[i] * j) % 9;
            q[j].push_back({i, now});
        }
        qq[w[i]].push_back(i);
    }
    vector<vector<pair<ll,ll>>> res(10, vector<pair<ll,ll>> (10));
    rep(i, 0, 8)
        sort(qq[i].begin(), qq[i].end());
    rep(i, 0, 8){
        sort(q[i].begin(), q[i].end());
        rep(j, 0, 8){
            bool st = false;
            for(auto x:q[i]){
                ll id = x.first, sum = x.second;
                ll k = ((sum <= j) ? (j - sum):(9 - sum + j));
                if(qq[k].empty()) continue;
                for(auto x:qq[k]){
                    if(x == id) continue;
                    st = true;
                    res[i][j] = {id, x};
                    break;
                }
                if(st) break;
            }
            if(!st) res[i][j] = {-1, -1};
        }
    }
    while(t --){
        ll L, R, k;
        cin >> L >> R >> k;
        ll p = (pre[R] - pre[L - 1]) % 9;
        cout << res[p][k].first << ' ' << res[p][k].second << endl;
    }
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