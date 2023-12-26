/*
 * @Author: JorD
 * @LastEditTime: 2022-11-22 01:58:45
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<pair<int,int>>> son(n + 1);
    rep(i, 2, n){
        int x, y, w;
        cin >> x >> y >> w;
        son[x].push_back({y, w});
        son[y].push_back({x, w});
    }
    map<int,int> st;
    string res = "NO\n";
    function<void(int,int,int)> dfs = [&](int now, int fa, int dist){
        if(now == a&&!dist) res = "YES\n";
        if(now != b) st[dist] = 1;
        for(auto [ne, x]:son[now]){
            if(ne == fa) continue;
            dfs(ne, now, dist ^ x);
        }
    };
    function<void(int,int,int)> dfs1 = [&](int now, int fa, int dist){
        if(st[dist]) res = "YES\n";
        for(auto [ne, x]:son[now]){
            if(ne == fa||ne == b) continue;
            dfs1(ne, now, dist ^ x);
        }
    };
    dfs(b, 0, 0);
    dfs1(a, 0, 0);
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}