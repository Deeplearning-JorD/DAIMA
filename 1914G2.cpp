#pragma GCC optimize(2)
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
const int N = 2e6 + 10;
int dfn[N], low[N], idx;
int sta[N], id[N], in[N], top, scc_cnt;
vector<int> son[N];
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
void Solve(){
    int n, m;
    cin >> n >> m;
    rep(t, 1, m){
        int x, y;
        son[x].push_back(y);
    }
    rep(i, 1, n)if(!dfn[i])tarjan(i);
    cout << scc_cnt << endl;
    rep(i, 1, n){
        cout << i << ' ' << id[i] << endl;
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