/*
 * @Author: JorD
 * @LastEditTime: 2022-12-10 15:21:07
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
    int n, p, k;
    cin >> n >> p >> k;
    vector<vector<pair<int,int>>> son((n + 1) * (k + 3));
    rep(i, 1, p){
        int a, b, c;
        cin >> a >> b >> c;
        son[a].emplace_back(b, c);
        son[b].emplace_back(a, c);
        for(int j = 0;j < k;j ++){
            son[j * n + a].emplace_back((j + 1) * n + b, 0);
            son[j * n + b].emplace_back((j + 1) * n + a, 0);
            son[(j + 1) * n + a].emplace_back((j + 1) * n + b, c);
            son[(j + 1) * n + b].emplace_back((j + 1) * n + a, c);
        }
    }
    for(int i = 0;i <= k;i ++)
        son[i * n].emplace_back((i + 1) * n, 0);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    vector<int> dist((n + 1) * (k + 3), 1e9);
    dist[1] = 0;
    q.emplace(0, 1);
    while(!q.empty()){
        auto [o, now] = q.top(); q.pop();
        for(auto [x, ww]:son[now]){
            int w = max(dist[now], ww);
            if(dist[x] > w){
                dist[x] = w;
                q.emplace(dist[x], x);
            }
        }
    }
    if(dist[(k + 1) * n] == 1e9) cout << -1 << endl;
    else cout << dist[(k + 1) * n];
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}