/*
 * @Author: JorD
 * @LastEditTime: 2023-08-06 00:47:35
 * how to Get
 */
#pragma GCC optimize(2)
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
const int N = 5e4 + 10;
vector<int> son[N];
int siz[N];
ll res = 0;
void dfs(int now){
    siz[now] = 1;
    ll sum = 0;
    for(auto x:son[now]){
        dfs(x);
        siz[now] += siz[x];
        sum += siz[x];
    }
    vector<int> dp(sum + 1);
    for(auto x:son[now]){
        for(int i = sum;i >= siz[x];i --){
            dp[i] = max(dp[i], dp[i - siz[x]] + siz[x]);
        }
    }
    ll mx = 0;
    rep(i, 0, sum){
        mx = max(mx, 1ll * (sum - i) * dp[i]);
    }
    res += mx;
}
void Solve(){
    int n; cin >> n;
    rep(i, 2, n){
        int x; cin >> x;
        son[x].push_back(i);
    }
    dfs(1);
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