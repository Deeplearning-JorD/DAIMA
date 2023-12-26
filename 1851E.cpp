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
    int k, n;
    cin >> n >> k;
    vector<ll> w(n + 1);
    vector<vector<int>> son(n + 1);
    rep(i, 1, n) cin >> w[i];
    vector<ll> dist(n + 1, 2e18);
    vector<bool> st(n + 1);
    rep(i, 1, k){
        ll x; cin >> x;
        w[x] = 0;
    }
    rep(i, 1, n){
        int m; cin >> m;
        rep(j, 1, m){
            int x; cin >> x;
            son[i].push_back(x);
        }
    }
    function<ll(ll)> dfs = [&](ll now){
        if(st[now]) return dist[now];
        st[now] = 1;
        ll sum = 0;
        if(son[now].empty()){
            dist[now] = w[now];
            return dist[now];
        }
        for(auto x:son[now]){
            sum += dfs(x);
        }
        dist[now] = min(w[now], sum);
        return dist[now];
    };
    rep(i, 1, n)if(!st[i])dfs(i);
    rep(i, 1, n) cout << dist[i] << ' ';
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}