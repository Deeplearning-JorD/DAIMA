/*
 * @Author: JorD
 * @LastEditTime: 2023-04-03 02:37:38
 */
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
void Solve(){   
    int n;
    cin >> n;
    vector<vector<int>> son(n + 1);
    rep(i, 2, n){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    vector<int> dist(n + 1);
    vector<int> l(n + 1), r(n + 1), up(n + 1);
    auto dfs = [&](auto dfs, int now, int fa) -> void{
        for(auto x:son[now])if(x != fa){
            dfs(dfs, x, now);
            dist[now] = max(dist[now], dist[x] + 1); 
            if(dist[x] + 1 > r[now]){
                l[now] = r[now];
                r[now] = dist[x] + 1;
            }else l[now] = max(l[now], dist[x] + 1);
        }
        return;
    };
    dfs(dfs, 1, -1);
    vector<int> mx(n + 1);
    auto dp = [&](auto dp, int now, int fa) -> void{
        mx[now] = max(up[now], r[now]);
        for(auto x:son[now])if(x != fa){
            if(dist[x] + 1 == r[now]){
                up[x] = max(up[now] + 1, l[now] + 1);
            }else up[x] = max(up[now] + 1, r[now] + 1);
            dp(dp, x, now);
        }
        return;
    };
    dp(dp, 1, -1);
    vector<int> res(n + 1), cnt(n + 2);
    for(int i = 1;i <= n;i ++) cnt[mx[i]] ++;
    for(int i = n;i >= 1;i --) cnt[i] += cnt[i + 1];
    for(int i = 1;i <= n;i ++) cout << min(n, n - cnt[i] + 1) << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}