#pragma GCC optimize(2)
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
    int n, a, b; cin >> n >> a >> b;
    vector<vector<int>> son(n + 1);
    rep(i, 1, n){
        int x, y; cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    vector<int> in(n + 1), sta(n + 1), f(n + 1), st(n + 1);
    int idx = 0;
    function<void(int,int)> dfs = [&](int now, int fa){
        if(in[now]){
            for(int i = f[now];i <= idx;i ++){
                st[sta[i]] = 1;
            }
            return;
        }
        in[now] = 1;
        sta[++ idx] = now;
        f[now] = idx;
        for(auto x:son[now])if(x != fa){
            dfs(x, now);
        }
        in[now] = 0;
        idx --;
    };
    dfs(1, 0);
    vector<int> dist(n + 1, 1e9);
    queue<int> q;
    q.push(b);
    dist[b] = 0;
    int l = 0, r = 0, mb = 0;
    while(q.size()){
        auto t = q.front(); q.pop();
        if(st[t]){
            mb = t;
            l = dist[t];
            break;
        }
        for(auto x:son[t])if(dist[t] + 1 < dist[x]){
            dist[x] = dist[t] + 1;
            q.push(x);
        }
    }
    while(q.size()) q.pop();
    rep(i, 1, n) dist[i] = 1e9;
    q.push(a);
    dist[a] = 0;
    while(q.size()){
        auto t = q.front(); q.pop();
        if(t == mb){
            r = dist[t];
            break;
        }
        for(auto x:son[t])if(dist[t] + 1 < dist[x]){
            dist[x] = dist[t] + 1;
            q.push(x);
        }
    }
    if(l < r) cout << "YES\n";
    else cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}