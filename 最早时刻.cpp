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
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> son(n + 1);
    rep(i, 1, m){
        ll x, y, z;
        cin >> x >> y >> z;
        son[x].push_back({y, z});
        son[y].push_back({x, z});
    }
    map<int,int> ban[n + 1];
    rep(i, 1, n){
        ll k; cin >> k;
        per(j, k, 1){
            int x; cin >> x;
            ban[i][x] = 1;
        }
    }
    vector<ll> dist(n + 1, 1e18);
    priority_queue<pair<ll,ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>>> q;
    q.push({0, 1});
    dist[1] = 0;
    while(q.size()){
        auto [WW, t] = q.top(); q.pop();
        ll w = dist[t];
        while(ban[t][w]){w ++;}
        for(auto [x, y]:son[t]){
            if(dist[x] > w + y){ 
                dist[x] = w + y;
                q.push({dist[x], x});
            }
        }
    }
    if(dist[n] == 1e18) dist[n] = -1;
    cout << dist[n];
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)111
    Solve();
    return 0;
}