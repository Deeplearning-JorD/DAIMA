/*
 * @Author: JorD
 * @LastEditTime: 2023-03-04 19:47:40
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
const int N = 5e6 + 10;
int tr[N][2], idx;
void build(int x){
    int p = 0;
    for(int i = 30;i >= 0;i --){
        int c = x >> i & 1;
        if(!tr[p][c]) tr[p][c] = ++ idx;
        p = tr[p][c];
    }
}
ll res = 1e18;
void dfs(int i, int p, ll now){
    if(i < 0){
        res = min(res, now);
        return;
    }
    if(tr[p][1]&&tr[p][0]){
        dfs(i - 1, tr[p][1], now | (1 << i));
        dfs(i - 1, tr[p][0], now | (1 << i));
    }else if(tr[p][0]){
        dfs(i - 1, tr[p][0], now);
    }else if(tr[p][1]){
        dfs(i - 1, tr[p][1], now);
    }
}
void Solve(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++){
        int x; cin >> x;
        build(x);
    }
    dfs(30, 0, 0);
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