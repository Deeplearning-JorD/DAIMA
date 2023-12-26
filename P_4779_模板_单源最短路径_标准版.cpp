/*
 * @Author: JorD
 * @LastEditTime: 2023-05-03 13:37:36
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
    cin >> n >> m >> s;
    vector<vector<pair<int,int>>> son(n + 1);
    while(m --){
        int a, b, c;
        cin >> a >> b >> c;
        son[a].push_back({b, c});
    }
    vector<int> dist(n + 1, 1e9);
    dist[s] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<int> st(n + 1);
    q.push({0, s});
    while(q.size()){
        auto [ui, now] = q.top(); q.pop();
        if(st[now]) continue;
        st[now] = 1;
        for(auto [x, w]:son[now]){
            if(dist[x] > dist[now] + w){
                dist[x] = dist[now] + w;
                q.push({dist[x], x});
            }
        } 
    }
    rep(i, 1, n) cout << dist[i] << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}