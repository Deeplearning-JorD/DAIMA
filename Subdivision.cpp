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
    vector<vector<int>> son(n + 1);
    rep(i, 1, m){
        int x, y; cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    vector<ll> dist(n + 1, -1);
    dist[1] = 0;
    vector<ll> d(n + 1);
    vector<int> fa(n + 1);
    vector<vector<int>> zson(n + 1);
    while(q.size()){
        auto t = q.front(); q.pop();
        for(auto x:son[t])if(fa[t] != x){
            if(dist[x] == -1){
                dist[x] = dist[t] + 1;
                fa[x] = t;
                q.push(x);
                zson[t].push_back(x);
                zson[x].push_back(t);
            }else{
                d[x] ++;
            }
        }
    }
    ll res = 0;
    vector<ll> depth(n + 1, -1);
    function<void(int,int)> dfs = [&](int now, int fa){
        depth[now] = depth[fa] + 1;
        res += depth[now] <= k;
        if(son[now].size() == 1 && now != 1){
            res += 1ll * max(d[now], 1ll) * (max(0ll, k - depth[now]));
        }else{
            res += 1ll * d[now] * (max(0ll, k - depth[now]));
        }
        for(auto x:zson[now])if(x != fa){
            dfs(x, now);
        }
    };
    dfs(1, 0);
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