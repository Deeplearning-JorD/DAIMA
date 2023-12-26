/*
 * @Author: JorD
 * @LastEditTime: 2022-09-24 20:20:19
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
const int N = 2e5 + 10;
vector<int> son[N];
int n, x, y;
bool st = false;
vector<int> res;
void dfs(int now, int fa){
    res.push_back(now);
    if(now == y){
        for(auto x:res) cout << x << " ";
        exit(0);
    }
    for(auto x:son[now]){
        if(x == fa) continue;
        dfs(x, now);
    }
    res.pop_back();
}
void Solve(){
    cin >> n >> x >> y;
    rep(i, 2, n){
        int u, v;
        cin >> u >> v;
        son[u].push_back(v);
        son[v].push_back(u);
    }
    dfs(x, 0);
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}