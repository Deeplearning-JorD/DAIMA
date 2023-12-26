/*
 * @Author: JorD
 * @LastEditTime: 2022-12-03 19:11:14
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
ll n;
ll res = 1e18;
void dfs(int deep, ll now, int L, int R){
    if(now >= n && (L + R) % 2 == 0){
        if(L != R) return;
        res = min(res, now);
        return;
    }
    dfs(deep + 1, now * 10 + 4, L + 1, R);
    dfs(deep + 1, now * 10 + 7, L, R + 1);
}
void Solve(){
    cin >> n;
    dfs(0, 0,0,0);
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