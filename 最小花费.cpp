/*
 * @Author: JorD
 * @LastEditTime: 2022-12-07 20:21:33
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
        int x, y, z;
        cin >> x >> y >> z;
        son[x].emplace_back(y, z);
        son[y].emplace_back(x, z);
    } 
    int A, B;
    cin >> A >> B;
    vector<double> dist(n + 1, 2e9);
    priority_queue<pair<double,int>, vector<pair<double, int>> , greater<pair<double,int>>> q;
    q.emplace(100, B);
    dist[B] = 100;
    while(!q.empty()){
        auto [o, now] = q.top(); q.pop();
        for(auto [x, w]:son[now]){
            if(dist[x] > dist[now] * 100 / (100 - w)){
                dist[x] = dist[now] * 100 / (100 - w);
                q.emplace(dist[x], x);
            }
        }
    }
    cout << dist[A];
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    cout << SPO(8);
    Solve();
    return 0;
}