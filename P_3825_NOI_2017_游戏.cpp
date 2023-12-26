#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (int(i) = (r); (i) >= (l); --(i))
const int N = 1e5 + 10;
int dfn[N], low[N], idx;
int id[N], sta[N], in[N], top, scc_cnt;
vector<vector<int>> son(N);
int n, d, m;
string s;
inline void tarjan(int now){
    dfn[now] = low[now] = ++ idx;
    sta[++ top] = now, in[now] = 1;
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
            y = sta[top --];
            in[y] = 0;
            id[y] = scc_cnt;
        }while(y != now);
    }
}
struct node{
    int a, c;
    char b, d;
}e[N];
char ban[N];
char find(int i){
    char x = s[i];
    if(x == 'x') x = ban[i];
    if(x == 'a') return 'B';
    return 'A';
}
char fi(int i){
    char x = s[i];
    if(x == 'x') x = ban[i];
    if(x == 'a'||x == 'b') return 'C';
    return 'B';
}
int k(char x, char y){
    if(x == 'a'){
        if(y == 'B') return 0;
        return n;
    }else if(x == 'b'){
        if(y == 'A') return 0;
        return n;
    }else if(x == 'c'){
        if(y == 'A') return 0;
        return n;
    }
    return n;
}
inline bool get(char c, char x){
    return c != (char)(x + 32);
}
inline void check(){   
    scc_cnt = idx = top = 0;
    rep(i, 1, n << 1){
        dfn[i] = low[i] = id[i] = 0;
        son[i].clear();
    }
    rep(i, 1, m){
        auto [a, c, b, d] = e[i];
        char l = s[a], r = s[c];
        if(l == 'x') l = ban[a];
        if(r == 'x') r = ban[c];
        if(!get(l, b)) continue;
        if(!get(r, d)){
            son[a + k(l, b)].push_back(a + n - k(l, b));
            continue;
        }
        son[a + k(l, b)].push_back(c + k(r, d));
        son[c + n - k(r, d)].push_back(a + n - k(l, b));
    }
    rep(i, 1, n << 1)if(!dfn[i]){
        tarjan(i);
    }
    rep(i, 1, n)if(id[i] == id[i + n])return;
    rep(i, 1, n){
        if(id[i] < id[i + n]){
            cout << find(i);
        }else cout << fi(i);
    }
    exit(0);
}
void dfs(int i){
    if(i > n){
        check();
        return;
    }
    if(s[i] != 'x'){
        dfs(i + 1);
    }else{
        ban[i] = 'b';
        dfs(i + 1);
        ban[i] = 'c';
        dfs(i + 1);
    }
}
void Solve(){
    cin >> n >> d;
    cin >> s;
    s = ' ' + s;
    vector<int> id;
    rep(i, 1, n)if(s[i] == 'x')id.push_back(i);
    cin >> m;
    rep(i, 1, m){
        int a, c; char b, d; cin >> a >> b >> c >> d;
        e[i] = {a, c, b, d};
    }
    for(int i = 0;i < (1 << d);i ++){
        for(int j = 0;j < d;j ++){
            if(i >> j & 1) ban[id[j]] = 'b';
            else ban[id[j]] = 'a';
        }
        check();
    }
    cout << -1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}