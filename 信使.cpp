/*
 * @Author: JorD
 * @LastEditTime: 2022-12-07 14:15:10
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
    vector<vector<pair<int,int>>> son(n + 1);
    rep(i, 1, m){
        int a, b, c;
        cin >> a >> b >> c;
        son[a].emplace_back(b, c);
        son[b].emplace_back(a, c);
    }
    priority_queue<PII, vector<PII>, greater<PII>> q;
    vector<int> dist(n + 1, 1e9);
    dist[1] = 0;
    q.emplace(0, 1);
    while(!q.empty()){
        auto [o, now] = q.top(); q.pop();
        for(auto [x, w]:son[now]){
            if(dist[x] > dist[now] + w){
                dist[x] = dist[now] + w;
                q.emplace(dist[x], x);
            }
        }
    }
    int res = 0;
    rep(i, 1, n){
        res = max(res, dist[i]);
    }
    if(res == 1e9) cout << -1 << endl;
    else cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}