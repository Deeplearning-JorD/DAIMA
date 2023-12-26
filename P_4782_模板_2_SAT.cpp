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
        int i, x, j, y;
        cin >> i >> x >> j >> y;
        if(x && y){
            //i + n, j + n
            son[i].push_back(j + n);
            son[j].push_back(i + n);
        }else if(!x && y){
            //i, j + n
            son[i + n].push_back(j + n);
            son[j].push_back(i);
        }else if(x && !y){
            //i + n, j
            son[i].push_back(j);
            son[j + n].push_back(i + n);
        }else{
            //i, j
            son[i + n].push_back(j);
            son[j + n].push_back(i);
        }
    }
    rep(i, 1, n << 1|1)if(!dfn[i])tarjan(i);
    rep(i, 1, n){
        if(id[i] == id[i + n]){
            cout << "IMPOSSIBLE";
            return;
        }
    }
    cout << "POSSIBLE\n";
    rep(i, 1, n){
        if(id[i] < id[i + n]) cout << 0 << ' ';
        else cout << 1 << ' ';
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