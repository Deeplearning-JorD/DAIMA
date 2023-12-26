/*
 * @Author: JorD
 * @LastEditTime: 2022-11-27 14:00:35
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
int n, m;
ll res;
void dfs(ll now, int dist){
    if(dist == n){
        if(now % m == 0) res ++;
        return;
    }
    rep(i, 1, 6) dfs(now * 10 + i, dist + 1);
}
void Solve(){
    cin >> n >> m;
    dfs(0, 0);
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}