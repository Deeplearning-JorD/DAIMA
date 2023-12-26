/*
 * @Author: JorD
 * @LastEditTime: 2022-08-26 20:27:35
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 2e5 + 10;
int f[N];
struct node{
    int a,b,c;
};
vector<node> son[N];
ll dist[N];
bool st[N];
int n, m;
void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0, 1});
    while(!q.empty()){
        auto t = q.top(); q.pop();
        int distance = t.first, val = t.second;
        if(st[val]) continue;
        st[val] = true;
        for(auto x:son[val]){
            int ww = min(distance + x.b,distance + x.c);
            if(dist[x.a] > ww){
                dist[x.a] = ww;
                q.push({dist[x.a],x.a});
            }
        }
    }
    cout << dist[n] << endl;
}
void Solve(){
    cin >> n >> m;
    int x, y, z;
    cin >> x >> y >> z;
    rep(i, 1, n) cin >> f[i];
    while(m --){
        int u, v;
        cin >> u >> v;
        son[u].push_back({v,f[u]==f[v]?x:y,f[u]!=f[v]?x+z:y+z});
        son[v].push_back({u,f[u]==f[v]?x:y,f[u]!=f[v]?x+z:y+z});
    }
    dijkstra();
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}