/*
 * @Author: JorD
 * @LastEditTime: 2022-12-08 03:28:29
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
    cin >> m >> n;
    vector<vector<PII>> son(n + 1);
    vector<int> L(n + 1);
    rep(i, 1, n){
        int p, idx;
        cin >> p >> L[i] >> idx;
        son[0].push_back({i, p});
        rep(j, 1, idx){
            int t, v;
            cin >> t >> v;
            son[t].push_back({i, v});
        }
    }
    int res = 1e9;
    auto work = [&](int l, int r){
        priority_queue<PII, vector<PII>, greater<PII>> q;
        vector<int> dist(n + 1, 1e9);
        dist[0] = 0;
        q.push({0, 0});
        while(!q.empty()){
            auto [o, now] = q.top(); q.pop();
            for(auto [x, w]:son[now]){
                if(L[x] < l || L[x] > r) continue;
                if(dist[x] > dist[now] + w){
                    dist[x] = dist[now] + w;
                    q.push({dist[x], x});
                }
            }
        }
        res = min(res, dist[1]);
    };
    rep(i, L[1] - m, L[1]) work(i, i + m);
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