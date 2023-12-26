/*
 * @Author: JorD
 * @LastEditTime: 2022-12-24 18:58:18
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
    vector<vector<pair<int,int>>> son(n + 1), zson(n + 1);
    rep(i, 1, m){
        int a, b, c;
        cin >> a >> b >> c;
        son[a].push_back({b, c});
        zson[b].push_back({a, c});
    }
    vector<int> dist(n + 1, 1e9), zdist(n + 1, 1e9);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    dist[1] = 0;
    while(q.size()){
        auto [o, now] = q.top(); q.pop();
        for(auto [x, w]:son[now]){
            if(dist[x] > o + w){
                dist[x] = o + w;
                q.push({dist[x], x});
            }
        }
    }
    q.push({0, 1});
    zdist[1] = 0;
    while(q.size()){
        auto [o, now] = q.top(); q.pop();
        for(auto [x, w]:zson[now]){
            if(zdist[x] > o + w){
                zdist[x] = o + w;
                q.push({zdist[x], x});
            }
        }
    }
    int res = 0;
    rep(i, 2, n){
        res += dist[i] + zdist[i];
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}