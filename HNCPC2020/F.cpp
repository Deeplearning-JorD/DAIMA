/*
 * @Author: JorD
 * @Date: 2023-11-29 13:44:06
 * @LastEditTime: 2023-11-29 20:26:45
 * how to Get
 */
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
int a[N], b[N];
int n, m;
vector<int> son[N];
pair<int,int> e[N];
int in[N], sta[N], top, dfn[N], low[N], idx;
int id[N], scc_cnt;
void tarjan(int now){
    dfn[now] = low[now] = ++ idx;
    sta[++ top] = now; in[now] = 1;
    for(auto x:son[now]){
        if(!dfn[x]){
            tarjan(x);
            low[now] = min(low[now], low[x]);
        }else if(in[x]) low[now] = min(low[now], dfn[x]);
    }
    if(dfn[now] == low[now]){
        scc_cnt ++;
        int y;
        do{ 
            y = sta[top --];
            in[y] = 0;
            id[y] = scc_cnt;
        }while(y != now);
    }
}
bool check(int mid){
    idx = 0, scc_cnt = 0;
    rep(i, 0, 2 * n){
        dfn[i] = 0;
        id[i] = 0;
        son[i].clear();
    }
    int cnt = 0;
    for(int i = 1;i <= m;i ++){
        auto [u, v] = e[i];
        // 这里如果用 <= mid 来判断判断不出来
        if(abs(a[u] - a[v]) > mid){
            son[u].push_back(v + n);
            son[v].push_back(u + n);
        }
        if(abs(a[u] - b[v]) > mid){
            son[u].push_back(v);
            son[v + n].push_back(u + n);
        }
        if(abs(b[u] - a[v]) > mid){
            son[u + n].push_back(v + n);
            son[v].push_back(u);
        }
        if(abs(b[u] - b[v]) > mid){
            son[u + n].push_back(v);
            son[v + n].push_back(u);
        }
    }
    rep(i, 1, 2 * n)if(!dfn[i]) tarjan(i);
    rep(i, 1, n) if(id[i] == id[i + n]) return 0;
    return 1;
}   
void Solve(){
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    rep(i, 1, m) cin >> e[i].first >> e[i].second;
    int l = 0, r = 1e9;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}