/*
 * @Author: JorD
 * @LastEditTime: 2022-12-03 01:55:01
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
#define rep(i, l, r) for (auto(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 5e5 + 10;
int n, m;
vector<pair<int,ll>> son[N];
ll w[N];
ll dist[N];
void Solve(){
    cin >> n >> m;
    rep(i, 1, n){
        cin >> w[i];
        rep(j, 1, min(m, n - i + 1)){
            int val; cin >> val;
            son[i].push_back({i + j, w[i] - val});
        }
    }
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pair<int,ll>, vector<pair<int,ll>>, greater<pair<int,ll>>> q;
    q.push({0, 1});
    dist[1] = 0;
    while(q.size()){
        auto [val, now] = q.top(); q.pop();
        for(auto [ne, z]:son[now]){
            if(dist[ne] > dist[now] + z){
                dist[ne] = dist[now] + z;
                q.push({dist[ne], ne});
            }
        }  
    }
    cout << dist[n + 1];
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}