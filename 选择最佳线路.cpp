/*
 * @Author: JorD
 * @LastEditTime: 2022-12-22 20:44:42
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
    int n, m, s;
    while(cin >> n >> m >> s){
        vector<vector<pair<int,int>>> son(n + 1);
        while(m --){
            int a, b, c;
            cin >> a >> b >> c;
            son[a].push_back({b, c});
        }
        priority_queue<PII, vector<PII>, greater<PII>> q;
        vector<int> dist(n + 1, 1e9);
        cin >> m;
        while(m --){
            int x;
            cin >> x;
            dist[x] = 0;
            q.push({0, x});
        }
        while(q.size()){
            auto [o, now] = q.top(); q.pop();
            for(auto [x, w]:son[now]){
                if(dist[x] > o + w){
                    dist[x] = o + w;
                    q.push({dist[x], x});
                }
            }
        }
        if(dist[s] == 1e9) cout << -1 << endl;
        else cout << dist[s] << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}