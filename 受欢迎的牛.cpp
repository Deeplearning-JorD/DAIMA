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
const int N = 1e4 + 10;
int n, m;
vector<int> son[N];
int dfn[N], low[N], in[N], idx, cnt, scc_cnt;
int sta[N], id[N];
void tarjan(int now){
    dfn[now] = low[now] = ++ idx;
    sta[++ cnt] = now; in[now] = 1;
    for(auto x:son[now]){
        if(!in[x]){
            tarjan(x);
            low[now] = min(low[now], low[x]);
        }else low[now] = min(low[now], dfn[x]);
    }
    if(dfn[now] == low[now]){
        ++ scc_cnt;
        int y;
        do{
            y = sta[cnt --];
            id[y] = scc_cnt;
        }while(y != now);
    }
}
void Solve(){
    cin >> n >> m;
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
    }
    rep(i, 1, n)if(!dfn[i])tarjan(i);
    vector<int> d(n + 1);
    rep(i, 1, n){
        for(auto x:son[i]){
            if(id[i] == id[x]) continue;
            d[id[i]] ++;
        }
    }
    vector<int> can;
    rep(i, 1, scc_cnt)if(!d[i]){
        can.push_back(i);
    }
    if(can.size() > 1) cout << 0 << endl;
    else{
        int now = can[0], res = 0;
        rep(i, 1, n){
            if(id[i] == now) res ++;
        }
        cout << res << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}