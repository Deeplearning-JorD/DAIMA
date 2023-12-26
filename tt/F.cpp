#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
const int N = 2e5 + 10;
vector<vector<int>> son, zson;
int idx, scc_cnt;
int in[N], sta[N], top, dfn[N], low[N], id[N];
void trjan(int now){
    dfn[now] = low[now] = ++ idx;
    sta[++ top] = now, in[now] = 1;
    for(auto x:son[now]){
        if(!dfn[x]){
            trjan(x);
            low[now] = min(low[now], low[x]);
        }else if(in[x]){
            
            // cout << now << ' ' << x << ' ' << low[x] << endl;
            low[now] = min(low[now], dfn[x]);
        }
    }
    if(low[now] == dfn[now]){
        int y;
        scc_cnt ++;
        do{
            y = sta[top --];
            in[y] = 0;
            id[y] = scc_cnt;
        }while(y != now);
    }      
}
void Solve(){
    int n, m, a, b; cin >> n >> m >> a >> b;
    idx = 0, scc_cnt = 0, top = 0;
    rep(i ,1, n){
        dfn[i] = low[i] = 0;
    }
    son.clear();
    son.resize(n + 1);
    vector<pair<int,int>> edge(m + 1);
    rep(i, 1, m){
        int x, y; cin >> x >> y;
        son[x].push_back(y);
        // son[y].push_back(x);
        // cout << x << ' ' << y << endl;
        edge[i] = {x, y};
    }
    rep(i, 1, n)if(!dfn[i])trjan(i);
    zson.resize(scc_cnt + 1);
    rep(i, 1, n) cout << id[i] << ' ';
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}