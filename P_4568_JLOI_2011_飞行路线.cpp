/*
 * @Author: JorD
 * @LastEditTime: 2022-12-11 22:59:21
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
    int n, m, k;
    cin >> n >> m >> k;
    int s, t;
    cin >> s >> t;
    vector<vector<pair<int,int>>> son(n * (k + 2));
    rep(i, 1, m){
        int a, b, c;
        cin >> a >> b >> c;
        son[a].emplace_back(b, c);
        son[b].emplace_back(a, c);
        for(int j = 0;j < k;j ++){
            son[n * j + a].emplace_back(n * (j + 1) + b, 0);
            son[n * j + b].emplace_back(n * (j + 1) + a, 0);
            son[n * (j + 1) + a].emplace_back(n * (j + 1) + b, c);
            son[n * (j + 1) + b].emplace_back(n * (j + 1) + a, c);
        }
    }
    rep(i, 0, k){
        son[n * i + t].emplace_back(n * (i + 1) + t, 0);
    }
    priority_queue<PII, vector<PII>, greater<PII>> q;
    vector<int> dist(n * (k + 2), 1e9);
    dist[s] = 0;
    q.emplace(0, s);
    while(!q.empty()){
        auto [o, now] = q.top(); q.pop();
        for(auto [x, w]:son[now]){
            if(dist[x] > dist[now] + w){
                dist[x] = dist[now] + w;
                q.emplace(dist[x], x);
            }
        }
    }
    cout << dist[k * n + t] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}