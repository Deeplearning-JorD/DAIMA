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
int dfn[N], low[N], idx, cnt;
int sta[N], in[N], scc_cnt;
int js[N];
void tarjan(int now){
    dfn[now] = low[now] = ++ idx;
    sta[++ cnt] = now; in[now] = 1;
    for(auto x:son[now]){
        if(!dfn[x]){
            tarjan(x);
            low[now] = min(low[now], low[x]);
        }else if(in[x]) low[now] = min(low[now], dfn[x]);
    }
    if(dfn[now] == low[now]){
        int y;
        scc_cnt ++;
        do{
            y = sta[cnt --];
            in[y] = 0;
            js[scc_cnt] ++;
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
    int res = 0;
    rep(i, 1, scc_cnt) res += js[i] >= 2;
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