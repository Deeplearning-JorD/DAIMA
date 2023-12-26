/*
 * @Author: JorD
 * @Date: 2023-11-30 14:04:18
 * @LastEditTime: 2023-11-30 14:17:30
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
const int N = 1e5 + 10;
double dp[N];
vector<int> son[N];
double res;
void dfs(int now, int fa, int dep){
    bool leaf = true;
    double down = 0;
    for(auto x:son[now])down += x != fa;
    for(auto x:son[now])if(x != fa){
        leaf = false;
        dp[x] = dp[now] / down;
        dfs(x, now, dep + 1);
    }
    if(leaf) res += dep * dp[now];
}
void Solve(){
    int n; cin >> n;
    rep(i, 2, n){
        int x, y; cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    dp[1] = 1;
    dfs(1, 0, 0);
    cout << SPO(10) << res << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}