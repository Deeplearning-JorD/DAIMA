/*
 * @Author: JorD
 * @LastEditTime: 2022-12-07 14:05:57
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
    int t, c, ts, te;
    cin >> t >> c >> ts >> te;
    vector<vector<pair<int,int>>> son(t + 1);
    rep(i, 1, c){
        int a, b, w;
        cin >> a >> b >> w;
        son[a].push_back({b, w});
        son[b].push_back({a, w});
    }
    vector<int> dist(t + 1, 1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, ts});
    dist[ts] = 0;
    while(!q.empty()){
        auto [val, now] = q.top(); q.pop();
        for(auto [x, w]:son[now]){
            if(dist[x] > dist[now] + w){
                dist[x] = dist[now] + w;
                q.push({dist[x], x});
            }
        }
    }
    cout << dist[te] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}