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
const ll inf = 1e18;
struct edge{
    ll a, b, w;
};
int st[1010];
void Solve(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<edge> e(m + 1);
    int idx = 0;
    rep(i, 1, m){
        int x, y, z;
        cin >> z >> x >> y;
        e[i] = {x, y, z}; 
        if(!st[x]) st[x] = ++ idx;
        if(!st[y]) st[y] = ++ idx;
    }
    n --;
    vector<vector<ll>> dist(idx + 1, vector<ll> (idx + 1, inf));
    rep(i, 1, m){
        auto [a, b, w] = e[i];
        a = st[a];
        b = st[b];
        dist[a][b] = dist[b][a] = w;
    }
    s = st[s];
    t = st[t];
    auto res = dist;
    while(n){
        if(n & 1){
            vector<vector<ll>> ls(idx + 1, vector<ll> (idx + 1, inf));
            rep(k, 1, idx)
            rep(i, 1, idx){
                rep(j, 1, idx){
                    ls[i][j] = min(ls[i][j], res[i][k] + dist[k][j]);
                }
            }
            res = ls;
        }
        vector<vector<ll>> last(idx + 1, vector<ll> (idx + 1, inf));
        rep(k, 1, idx)
        rep(i, 1, idx){
            rep(j, 1, idx){
                last[i][j] = min(last[i][j], dist[i][k] + dist[k][j]);
            }   
        }
        dist = last;
        n >>= 1;
    }
    cout << res[s][t] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}