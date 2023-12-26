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
int dfn[N], low[N], cnt, idx;
int sta[N], in[N], scc_cnt;
int id[N];
vector<int> son[N];
void tarjan(int now){
    dfn[now] = low[now] = ++ idx;
    sta[++ cnt] = now; in[now] = 1;
    for(auto x : son[now]){
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
            id[y] = scc_cnt;
        }while(y != now);
    }
}
void Solve(){
    int n, m;
    cin >> n >> m;
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
    }
    rep(i, 1, n)if(!dfn[i])tarjan(i);
    vector<vector<int>> ls(scc_cnt + 1);
    vector<int> use(n + 1);
    rep(i, 1, n){
        ls[id[i]].push_back(i);
    }
    cout << scc_cnt << endl;
    rep(i, 1, n)if(!use[i]){
        for(auto x:ls[id[i]]){
            cout << x << ' ';
            use[x] = 1;
        }
        cout << endl;
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