/*
 * @Author: JorD
 * @Date: 2023-10-18 13:25:18
 * @LastEditTime: 2023-10-18 14:22:38
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
const int N = 2e2 + 10;
int dfn[N], low[N], idx;
int sta[N], in[N], top, scc_cnt, id[N];
vector<vector<int>> son;
void tarjan(int now){
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
int get(string &s){
    int res = 0;
    for(int i = 1;i < s.size();i ++){
        res = res * 10 + s[i] - '0';
    }
    return res;
}
void Solve(){
    int n, m;
    cin >> n >> m;
    son.clear();
    idx = scc_cnt = top = 0;
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(in, 0, sizeof in);
    memset(id, 0, sizeof id);
    memset(sta, 0, sizeof sta);
    son.resize(n << 1|1);
    rep(i, 1, m){
        string s, t; cin >> s >> t;
        int a, b, c, d;
        a = get(s), b = get(t);
        c = s[0] == 'h';
        d = t[0] == 'h';
        // cout << c << ' ' << a << ' ' << d << ' ' << b << endl; 
        if(c && d){
            son[a].push_back(b + n);
            son[b].push_back(a + n);
            // cout << a << ' ' << b + n << endl;
            // cout << b << ' ' << a + n << endl;
        }else if(!c && d){
            son[a + n].push_back(b + n);
            son[b].push_back(a);
            // cout << a + n << ' ' << b + n << endl;
            // cout << b << ' ' << a << endl;
        }else if(c && !d){
            son[a].push_back(b);
            son[b + n].push_back(a + n);
            // cout << a << ' ' << b << endl;
            // cout << b + n << ' ' << a + n << endl;
        }else if(!c && !d){
            son[a + n].push_back(b);
            son[b + n].push_back(a);
            // cout << a + n << ' ' << b << endl;
            // cout << b + n << ' ' << a << endl;
        }
    }
    rep(i, 1, n << 1)if(!dfn[i])tarjan(i);
    rep(i, 1, n){
        if(id[i] == id[i + n]){
            cout << "BAD\n";
            return;
        }
    }
    cout << "GOOD\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}